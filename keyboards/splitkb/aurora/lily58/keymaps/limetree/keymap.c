/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include <stdio.h>
#include "bongo.h"

enum layer_number {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* DEFAULT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LALT |LOWER | /Space  /       \ ENTER\  |RAISE |BackSP| RCTL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_DEFAULT] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_BTN1,  KC_BTN2,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                      KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,        KC_ENT, MO(_RAISE), KC_BSPC, KC_LALT
),
    

	/* lower
  * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  INS | HOME |  UP  |  END | PGUP |                    |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  DEL | LEFT | DOWN | RGHT | PGDN |-------.    ,-------|      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2  |   3  |   .  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |  xx  | /       /       \    0 \  |ADJUST|      |      |
 *                   |      |      |  xx  |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,                     KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
  KC_TRNS, KC_INS,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,                   KC_TRNS,  KC_P7,    KC_P8,    KC_P9,     KC_P,      KC_TRNS,
  KC_TRNS, KC_DEL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,                   KC_TRNS,  KC_P4,    KC_P5,    KC_P6,     KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_P1,    KC_P2,    KC_P3,     KC_DOT,    KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_P0, MO(_ADJUST), KC_TRNS, KC_TRNS
),

//https://getreuer.info/posts/keyboards/symbol-layer/index.html  <- reference
    	/* raise
  * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |  <   |  >   |  @   |   .  |                    |   &  |      |   [  |   ]  |  %   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   -  |   +  |   =  |  #   |-------.    ,-------|   |  |   :  |   (  |  )   |  ?   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ^  |   /  |   *  |   ^  |      |-------|    |-------|   ~  |  $   |  {   |   }  |  @   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |ADJUST| /       /       \      \  |  xx  |      |      |
 *                   |      |      |      |/       /         \      \ |  xx  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,                     KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
  KC_TRNS, KC_QUOT, KC_LT,    KC_GT,    KC_AT,    KC_DOT,                    KC_AMPR,  KC_TRNS,  KC_LBRC,  KC_RBRC,   KC_PERC,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_PMNS,  KC_PPLS,  KC_EQL,   KC_HASH,                   KC_PIPE,  KC_COLN,  KC_LPRN,  KC_RPRN,   KC_QUES,   KC_TRNS,
  KC_TRNS, KC_CIRC, KC_PSLS,  KC_ASTR,  KC_CIRC,  KC_TRNS, KC_TRNS,  KC_TRNS,KC_TILD,  KC_DLR,   KC_LCBR,  KC_RCBR,   KC_AT,     KC_TRNS,
                        KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),


    	/* adjust
  * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |toggle| hue+ | sat+ | bri+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | mode | hue- | sat- | bri- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_ADJUST] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,    KC_LBRC,  KC_RBRC,  KC_TRNS,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,KC_NO,    KC_NO,    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS
)
};

//combo keys
const uint16_t PROGMEM bspc_combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM change_language_combo1[] = {KC_LSFT, KC_SPC, COMBO_END};



combo_t key_combos[] = {
    COMBO(bspc_combo1, KC_BSPC),
    COMBO(change_language_combo1, KC_RALT)
};


/* #ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
}
#endif */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder
    // 1 is right-half encoder
    if (index == 0) {
        if (clockwise) {
        tap_code16(KC_MS_RIGHT);
      } else {
        tap_code(KC_MS_LEFT);
      }
    } else if (index == 1) {
        if (clockwise) {
        tap_code16(KC_MS_UP);
      } else {
        tap_code(KC_MS_DOWN);
      }
    }

    return false;
}
#endif


void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
    } else {
      return rotation;
    }
}

void render_layer_states(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_DEFAULT)) {
        oled_write_P(default_layer, false);
    } else {
        oled_write_P(adjust_layer, false);
    }
}
//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_states();
        if (is_caps_word_on()) {
          oled_write(" CAPS", true);
        } else {
          oled_write(" CAPS", false);
        }
    } else {
      draw_bongo();
    }
	
	return false;
}

#endif