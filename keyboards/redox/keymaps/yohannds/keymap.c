#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BVOFRAK 0
#define _NAV 1

enum custom_keycodes
{
  BVOFRAK = SAFE_RANGE,
  NAV
};

// Shortcut to make keymap more readable
#define NAV     TT(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BVOFRAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CALC,  KC_F1,   KC_F2,   KC_F3,    KC_F4,  KC_F5,                                               KC_F8,   KC_F9,   KC_F10, KC_F11,   KC_F12,  KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_F6,                             KC_F7,   KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,   KC_TAB,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       NAV,      KC_A,    KC_S,    KC_D,     KC_F/**/,KC_G,   NAV,                              NAV,    KC_H,    KC_J/**/,  KC_K,   KC_L,   KC_SCLN ,NAV,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE, KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,   KC_LALT, KC_LCTL,         KC_LALT, KC_RCTL, KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLASH, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_ESC,  XXXXXXX,  XXXXXXX, KC_LWIN,     KC_LSFT,     KC_BSPC,  KC_DEL,          KC_ENT,  KC_SPC,     KC_ALGR,      KC_LWIN,  XXXXXXX, XXXXXXX, KC_ESC
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP, _______, _______, _______, _______, _______,                                             _______ ,_______ ,_______ ,_______ ,_______ , RESET ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_VOLU,  KC_HOME, KC_UP,   KC_END,  KC_CUT, _______ ,                          _______,  KC_WH_U, KC_KP_1, KC_KP_2, KC_KP_3,KC_MNXT,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MUTE,  KC_LEFT, KC_DOWN,KC_RIGHT, KC_COPY,_______ ,                          _______,  KC_KP_0, KC_KP_4, KC_KP_5, KC_KP_6,KC_MPLY,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_VOLD,  KC_PGUP, XXXXXXX,KC_PGDOWN,KC_PASTE,KC_BTN1,KC_BTN2,         _______, _______,  KC_WH_D, KC_KP_7, KC_KP_8, KC_KP_9,KC_MPRV,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,      _______,     _______ ,_______,         _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

// Change LED colors depending on the layer.
uint32_t layer_state_set_user(uint32_t state)
{
  switch (biton32(state)) {
  case _BVOFRAK:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb_green();
    break;
  case _NAV:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb_blue();
    break;
  
  default: //  for any other layers, or the default layer
    rgblight_setrgb_yellow();
    break;
  }
  return state;
};
