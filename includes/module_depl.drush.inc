<?php
include(drupal_get_path('module','module_depl').'/includes/module_depl.common.inc');

/**
 * Implements hook_drush_command().
 */
function module_depl_drush_command() {

  $commands['deploy'] = array(
    'callback' => 'module_depl_drush_execute',
    'description' => 'Modules Deploy drush command',
    'aliases' => array('depl'),
     'examples' => [
       'drush deploy argument' => 'Features revert or installs using update id as argument',
     ],
  );

  return $commands;
}    

/**
 *  Drush deploy callback
 **/
function module_depl_drush_execute() {
  $args = func_get_args();
  module_depl_auto_deploy(reset($args));
}
