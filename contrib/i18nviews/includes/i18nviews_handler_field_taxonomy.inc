<?php

/**
 * Field handler to provide simple renderer that allows linking to a taxonomy
 * term.
 */
class i18nviews_handler_field_taxonomy extends views_handler_field_taxonomy {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = 'tid';
  }
  function pre_render($values) {
    foreach ($values as $key => $value) {
      if (isset($value->{$this->field_alias})) {
        $tid = $value->{$this->aliases['tid']};
        $values[$key]->{$this->field_alias} = tt('taxonomy:term:'. $tid .':name', $value->{$this->field_alias});
      }
    }
  }
}