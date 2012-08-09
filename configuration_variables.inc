<?php

function variable_set($name, $value) {

  cache_clear_all('variables', 'cache_bootstrap');

  $old_value = array_key_exists($name, $conf) ? $conf[$name] : NULL;
  $conf[$name] = $value;
  module_invoke_all('variable_set', $name, $value, $old_value);
}

function variable_del($name) {
  
  cache_clear_all('variables', 'cache_bootstrap');

  unset($conf[$name]);
  module_invoke_all('variable_del', $name);
}

/**
* Allow modules to react to changes in a variable.
*
* @param mixed $name
*   The name of the variable.
* @param mixed $value
*   The value the variable is being set to.
* @param mixed $old_value
*   The old value of the variable.
*/
//function hook_variable_set($name, $value, $old_value = NULL) {
//  if ($name == 'mymodule_foo') {
//    mymodule_notify_variable_change($name, $value, $old_value);
//  }
//}

/**
* Allow modules to react to a variable deletion.
*
* @param mixed $name
*   The name of the variable.
*/
//function hook_variable_del($name) {
//  if ($name == 'mymodule_foo') {
//    mymodule_notify_variable_del($name);
//  }
//}