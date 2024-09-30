/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
// #include <iostream>

enum custom_keycodes {
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3,
  _ENTER  = 100,
  _ALT    = 101,
  _VI_W   = 102, // next word
  _VI_B   = 103, // prev word
  _DEL_W  = 104, // delete word
  _GUI    = 105,
  _SHIFT  = 106,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _GUI,  _LOWER,  KC_SPC,      KC_ENT,  _SHIFT,  _RAISE
                                      //`--------------------------'  `--------------------------'

  ),



  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_HASH, KC_LCBR,  KC_DLR,  KC_ESC, KC_PERC,                      KC_AMPR, KC_CIRC, KC_LPRN, KC_LBRC, KC_RBRC, KC_RCBR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  KC_DOT, KC_COMM, KC_SCLN, KC_COLN, KC_ASTR,                      KC_DQUO, KC_QUOT, KC_MINS,  KC_EQL, KC_PLUS, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LABK, KC_RABK,  KC_GRV, KC_SLSH, KC_QUES,                      KC_PIPE, KC_EXLM, KC_BSLS, KC_UNDS, KC_BSPC,  KC_AT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,MO(_ADJUST),_______
                                      //`--------------------------'  `--------------------------'

 //                               ,-----------------------.                    ,-----------------------.
 //                               | ~ , # , { , $ , % ,ESC,                    , & , ^ , ( , [ , ] , } |
 //                               |---+---+---+---+---+---|                    |---+---+---+---+---+---|
 //                               |TAB, . , , , ; , : , * ,                    , " , ' , - , = , + , ) |
 //                               |---+---+---+---+---+---|                    |---+---+---+---+---+---|
 //                               |   , < , > , ` , / , ? ,                    , | , ! , \ , _ ,BSPC,@ |
 //                               `---+---+---+---+---+---+---.            ,---+---+---+---+---+---+---`
 //                                             |CTRL,LOWER,SPC,          |ENT,RAISE,ALT|
 //                                              `---+---+---`             `---+---+---`
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,   KC_7,    KC_8,    KC_9,    KC_0, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX,  _DEL_W,   _VI_B,   _VI_W,  XXXXXXX,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______,MO(_ADJUST),_______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_VOLU, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  _DEL_W,   _VI_B,   _VI_W, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};


void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        // apple log
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    } else {
        // windows log
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE


struct Enable_alt {
    bool by_gui;
    bool by_shift;
};

enum ADJUST_FLAG {
    BY_SHIFT,
    BY_LOWER,
    NONE,
};

static  struct Enable_alt enable_alt = { false, false };
static bool lower_pressed = false;
static bool adjust_flag = false;

void try_adjust_layers(void) {
    if (!adjust_flag) { // Already pressing adjust key
        adjust_flag = false;
        layer_off(_ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _LOWER:
      if (record->event.pressed) {
        if (adjust_flag) { // Already pressing adjust key
          layer_on(_ADJUST);
        }else {
          adjust_flag = true;
          layer_on(_LOWER);
        }
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed) {
          register_code(KC_LNG2);
          // register_code(KC_MHEN);
          unregister_code(KC_LNG2);
          // unregister_code(KC_MHEN);
        }
        lower_pressed = false;
        try_adjust_layers();
      }
      return false;
      break;
    case _RAISE:
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed) {
          tap_code(KC_LNG1);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case _SHIFT:
      if (record->event.pressed) {
        if (adjust_flag) {
          layer_on(_ADJUST);
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
          return false;
        }
        adjust_flag = true;
        if (enable_alt.by_gui) {
          unregister_code(KC_LGUI);
          register_code(KC_LALT);
        } else {
          register_code(KC_RSFT);
          enable_alt.by_shift = true;
        }
      } else {
        unregister_code(KC_RSFT);
        if (enable_alt.by_shift) {
          unregister_code(KC_LALT);
          enable_alt.by_shift = false;
        }
        try_adjust_layers();
      }
      return false;
      break;
    case _ENTER:
      if (record->event.pressed) {
        if (enable_alt.by_gui) {
          unregister_code(KC_LGUI);
          register_code(KC_LALT);
        } else {
          lower_pressed = true;
          register_code(KC_LCTL);
          enable_alt.by_shift = true;
        }
      } else {
        unregister_code(KC_LCTL);
        if (enable_alt.by_shift) {
          unregister_code(KC_LALT);
          enable_alt.by_shift = false;
        }
        if (lower_pressed) {
          tap_code(KC_ENT);
          lower_pressed = false;
        }
      }
      return false;
      break;
    case _GUI:
      if (record->event.pressed) {
        if (enable_alt.by_shift) {
          unregister_code(KC_LCTL);
          register_code(KC_LALT);
        } else {
          register_code(KC_LGUI);
          enable_alt.by_gui = true;
        }
      } else {
        unregister_code(KC_LGUI);
        if (enable_alt.by_gui) {
          unregister_code(KC_LALT);
          enable_alt.by_gui = false;
        }
      }
      return false;
      break;
    case _ALT:
      if (record->event.pressed) {
        lower_pressed = true;

        register_code(KC_RALT);
      } else {
        unregister_code(KC_RALT);

        if (lower_pressed) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case _VI_W:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_RIGHT);
        unregister_code(KC_RALT);
      }
      return false;
      break;
    case _VI_B:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_LEFT);
        unregister_code(KC_RALT);
      }
      return false;
      break;
    case _DEL_W:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_BSPC);
        unregister_code(KC_RALT);
       }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        lower_pressed = false;
        adjust_flag = false;
      }
      break;
  }
  return true;
}
