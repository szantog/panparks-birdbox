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

  $form['birdbox_redirect_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path'),
    '#default_value' => variable_get('birdbox_redirect_path', ''), 
    '#size' => 40,
    '#description' => t('Specify a relative URL to redirect after make an attempt to tweet.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['birdbox_default_text_to_tweet'] = array(
    '#type' => 'textarea',
    '#title' => t('Default text to tweet'),
    '#default_value' => variable_get('birdbox_default_text_to_tweet', ''),
    '#rows' => 1,
    '#resizable' => FALSE,
    '#required' => TRUE,
    '#maxlength' => 140,
    '#maxlength_js' => TRUE,
  );

  return system_settings_form($form);
}

