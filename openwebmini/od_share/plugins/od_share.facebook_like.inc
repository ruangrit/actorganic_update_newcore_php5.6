<?php

/**
 * Return info.
 */
function od_share_facebook_like_info() {
  return array(
    'name' => t('Facebook Like'),
    'display callback' => 'od_share_facebook_like_display',
    'options callback' => 'od_share_facebook_like_options',
  );
}

/**
 * Return HTML.
 */
function od_share_facebook_like_display($vars) {
  foreach ($vars as $key => $value) {
    $$key = $value;
  }

  $url = url_to_use($url);
  $use_send_button = variable_get('od_share_facebook_use_send_button', false);
  $width = variable_get('od_share_facebook_like_fbml_width', 450);

  $use_send_button = $use_send_button? 'true' : 'false';
  if (is_use_xfbml()) {
    $output = '<fb:like href="'. $url .'" send="'. $use_send_button .'" layout="' . $option .'" width="'. $width .'" show_faces="true" font=""></fb:like>';
  }
  else {
    $output = '<iframe src="http://www.facebook.com/plugins/like.php?href='. $url .'&amp;send='.$use_send_button.'&amp;layout='. $option .'&amp;width=450&amp;show_faces=true&amp;action=like&amp;colorscheme=light&amp;font&amp;height=90" scrolling="no" frameborder="0" style="border:none; overflow:hidden; height:90px;" allowTransparency="true"></iframe>';
    //$output = '<iframe src="http://www.facebook.com/plugins/like.php?href='. $url .'" scrolling="no" frameborder="0" style="height: 62px; width: 100%" allowTransparency="true"></iframe>';
  //$output .= '<a name="fb_share" type="'. $option .'" share_url="'. $url .'"></a> <script src="http://static.ak.fbcdn.net/connect.php/js/FB.Share" type="text/javascript"></script>';
  }
  return $output;
}

/**
 * Return options form.
 */
function od_share_facebook_like_options() {
  return array(
    'box_count' => t('Box Count'),
    'button_count' => t('Button Count'),
    'standard' => t('Standard'),
  );
}
