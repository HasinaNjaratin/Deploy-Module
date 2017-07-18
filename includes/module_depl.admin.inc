<?php

/**
 * @file
 * {@inheritdoc}
 */

include drupal_get_path('module', 'module_depl') . '/includes/module_depl.common.inc';

/**
 * Import admin form.
 */
function module_depl_back_form($form, $form_state) {
  $type = array(
    'all' => t('All'),
    'install' => t('Install'),
    'revert' => t('Revert'),
  );

  $form['depl_arg'] = array(
    '#title' => t("Deploiement argument"),
    '#type' => 'select',
    '#default_value' => 'all',
    '#options' => $type,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Deployer'),
  );

  $form['#submit'] = array(
    'module_depl_back_submit',
  );
  return $form;
}

/**
 * {@inheritdoc}
 */
function module_depl_back_submit(&$form, &$form_state) {
  $arg = $form_state['values']['depl_arg'];
  module_depl_auto_deploy($arg);
}
