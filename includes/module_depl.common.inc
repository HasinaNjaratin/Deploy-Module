<?php

/**
 * @file
 * {@inheritdoc}
 */

/**
 * Deploy process.
 */
function module_depl_auto_deploy($arg = 'all') {
  switch ($arg) {
    case 'install':
      module_depl_auto_install();
      break;

    case 'revert':
      module_depl_auto_revert();
      break;

    case 'all':
      module_depl_auto_install();
      module_depl_auto_revert();
      break;

    default:
      // code...
      break;
  }
}

/**
 * Install process.
 */
function module_depl_auto_install() {
  $listeModule = array();
  $file = new SPLFileObject(drupal_realpath('private://') . '/deploiement/install.txt');
  try {
    foreach ($file as $line) {
      $listeModule[] = htmlspecialchars($line);
    }
  }
  catch (Exception $e) {

  }
  // Install modules.
  if (is_array($listeModule) && count($listeModule) > 0) {
    foreach ($listeModule as $module) {
      if (!module_exists(trim($module)) && !empty(trim($module))) {
        module_enable(array(trim($module)), TRUE);
        drupal_set_message(t('@arg1 has been successfully installed.', ['@arg1' => $module]), 'status');
      }
    }
  }
}

/**
 * Revert process.
 */
function module_depl_auto_revert() {
  $listeModule = array();
  $file = new SPLFileObject(drupal_realpath('private://') . '/deploiement/revert.txt');
  try {
    foreach ($file as $line) {
      $listeModule[] = htmlspecialchars($line);
    }
  }
  catch (Exception $e) {

  }
  // Revert features.
  if (is_array($listeModule) && count($listeModule) > 0) {
    foreach ($listeModule as $module) {
      if (!empty(trim($module))) {
        if (!module_exists(trim($module))) {
          module_enable(array(trim($module)), TRUE);
          drupal_set_message(t('@arg has been successfully installed.', array('@arg' => $module)), 'status');
        }
        if (module_exists('features')) {
          features_revert_module($module);
          drupal_set_message(t('@arg has been successfully reverted.', array('@arg' => $module)), 'status');
        }
        else {
          drupal_set_message(t('You need features contrib module to use this operation'), 'error');
        }
      }
    }
  }
}
