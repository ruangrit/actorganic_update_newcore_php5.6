<?php
/**
 * @file
 * Contains the i18nstrings localization plugin.
 */

/**
 * Localization plugin to pass translatable strings through i18nstrings().
 *
 * @ingroup views_localization_plugins
 */
class i18nviews_plugin_localization_i18nstrings extends views_plugin_localization {

  /**
   * Translate a string.
   *
   * @param $string
   *   The string to be translated.
   * @param $keys
   *   An array of keys to identify the string. Generally constructed from
   *   view name, display_id, and a property, e.g., 'header'.
   */
  function translate_string($string, $keys = array(), $format = '') {
    return i18nstrings($this->stringid($keys), $string);
  }

  /**
   * Save a string for translation.
   *
   * @param $source
   *   Full data for the string to be translated.
   */
  function save($source) {
    // @TODO identify format for special elements
    //  header, footer, empty are currently untranslateable
    i18nstrings_update($this->stringid($source['keys']), $source['value'], NULL);
    return TRUE;
  }

  /**
   * Delete a string.
   *
   * @param $source
   *   Full data for the string to be translated.
   */
  function delete($source) {
    i18nstrings_remove($this->stringid($source['keys']), $source['value']);
    return TRUE;
  }
  
  /**
   * Get string id for i18n
   *
   * @param $keys
   *   Array of keys for the string to be translated.
   */
  function stringid($keys) {
    return 'views:' . implode(':', $keys);
  }
}

