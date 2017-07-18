<?php

/**
 * @file
 * {@inheritdoc}
 */

include drupal_get_path('module', 'deploy_contributions') . '/includes/deploy_contributions.common.inc';

/**
 * Implements hook_drush_command().
 */
function deploy_contributions_drush_command() {

  $commands['deploy'] = array(
    'callback' => 'deploy_contributions_drush_execute',
    'description' => 'Modules Deploy drush command',
    'aliases' => array('depl'),
    'examples' => [
      'drush deploy argument' => 'Features revert or installs using update id as argument',
    ],
  );

  return $commands;
}

/**
 * Drush deploy callback.
 */
function deploy_contributions_drush_execute() {
  $args = func_get_args();
  deploy_contributions_auto_deploy(reset($args));
}
