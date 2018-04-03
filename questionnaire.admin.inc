<?php

function questionnaire_settings_form($form, $form_state) {
  $types_info = node_type_get_types();

  foreach($types_info as $k => $v) {
    $types_info[$k] = $v->name;
  }

  $form['questionnaire_content_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type which use questionnaire'),
    '#options' => $types_info,
    '#multiple' => TRUE,
    '#default_value' => variable_get('questionnaire_content_type', array('article'))
  );
  $form['questionnaire_popup_possibility'] = array(
    '#type' => 'textfield',
    '#title' => t('Possibility'),
    '#description' => t('possibility in percent (%)'),
    '#default_value' => variable_get('questionnaire_popup_possibility', '30')
  );
  $form['questionnaire_number_of_items'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items'),
    '#description' => t('How many questionnaires should be displayed?'),
    '#default_value' => variable_get('questionnaire_number_of_items', '1')
  );
  $form['questionnaire_lifetime'] = array(
    '#type' => 'textfield',
    '#title' => t('Lifetime'),
    '#description' => t('Set 0 (zero) for staying until clicked'),
    '#default_value' => variable_get('questionnaire_lifetime', '0')
  );

  return system_settings_form($form);
}
