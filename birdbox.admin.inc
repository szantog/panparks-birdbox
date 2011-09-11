<?php

/**
 * @file
 * Settings for posting tweets with Birdbox. 
 */

function birdbox_admin_form($form_state) {
  $form = array();

  $form['oauth_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('OAuth Settings'),
    '#description' => t('In order to use Birdbox, you need OAuth based access for Twitter. You have to <a href="@url">register your application</a> with Twitter and add the provided keys here. Important: Birdbox needs \'Read and Write\' access level, you can configure this by editing your already added application\'s settings.', array('@url' => 'https://dev.twitter.com/apps/new')),
  );
  $form['oauth_settings']['callback_url'] = array(
    '#type' => 'item',
    '#title' => t('Callback URL'),
    '#markup' => url('birdbox/oauth', array('absolute' => TRUE)),
  );
  $form['oauth_settings']['birdbox_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth Consumer key'),
    '#default_value' => variable_get('birdbox_consumer_key', NULL),
    '#required' => TRUE,
  );
  $form['oauth_settings']['birdbox_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth Consumer secret'),
    '#default_value' => variable_get('birdbox_consumer_secret', NULL),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
