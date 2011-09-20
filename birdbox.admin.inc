<?php

/**
 * @file
 * Settings for posting tweets with Birdbox. 
 */

function birdbox_admin_form($form_state) {
  $form = array();

  $form['tweet_form_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tweet form settings'),
  );
  $form['tweet_form_settings']['birdbox_default_text_to_tweet'] = array(
    '#type' => 'textarea',
    '#title' => t('Default text to tweet'),
    '#default_value' => variable_get('birdbox_default_text_to_tweet', ''),
    '#rows' => 2,
    '#resizable' => FALSE,
    '#required' => TRUE,
    '#maxlength' => 140,
    '#maxlength_js' => TRUE,
  );
  $form['tweet_form_settings']['birdbox_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Error message'),
    '#description' => t('This message will appear when tweeting was unsuccessfull.'),
    '#default_value' => variable_get('birdbox_error_message', t('Oops, something went wrong. Please try again.')),
    '#rows' => 2,
    '#required' => TRUE,
  );
  $success_message = variable_get('birdbox_success_message');
  $form['tweet_form_settings']['birdbox_success_message'] = array(
    '#base_type' => 'textarea',
    '#title' => t('Success message'),
    '#description' => t('This message will appear when tweeting was successfull.'),
    '#default_value' => (is_array($success_message) && !empty($success_message['value'])) ?
      $success_message['value'] : t('Thank you!'),
    '#format' => (is_array($success_message) && !empty($success_message['format'])) ?
      $success_message['format'] : filter_default_format(),
    '#process' => array('filter_process_format'),
    '#theme_wrappers' => array('text_format_wrapper'),
    '#rows' => 2,
    '#required' => TRUE,
  );
  $form['tweet_form_settings']['birdbox_show_tweet_form_after_success'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show tweet form after successfull tweeting.'),
    '#default_value' => variable_get('birdbox_show_tweet_form_after_success', TRUE),
  );

  $form['oauth_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('OAuth settings'),
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

  return system_settings_form($form);
}

