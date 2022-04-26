/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define RAI_DEL LT(_RAISE, KC_DEL)
#define RAI_TAB LT(_RAISE, KC_TAB)

#define FUNC_L OSL(_FUNCTION)

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,--------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                                   KC_H,   HOME_J,  HOME_K,  HOME_L, HOME_SCLN,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 RAI_DEL, KC_BSPC, KC_ESC,     KC_ENT,  KC_SPC,  RAI_TAB
                             //`--------------------------'  `--------------------------'

      ),
 [_RAISE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,--------------------------------------------.
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      KC_PIPE, KC_BSLS, KC_PLUS, KC_EQL,  KC_TILD,                               KC_GRV,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_DQT,  KC_QUOT, _______,    _______, KC_MINS, KC_UNDS
                             //`--------------------------'  `--------------------------'
     ),
 [_LOWER] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,--------------------------------------------.
      _______, _______, KC_PGUP, _______, _______,                               _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      KC_CAPS, KC_HOME, KC_PGDN, KC_END,  _______,                              KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  _______,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 _______, _______, FUNC_L,     _______, _______, _______
                             //`--------------------------'  `--------------------------'
     ),
 [_FUNCTION] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,--------------------------------------------.
      _______, _______, KC_VOLU, _______, _______,                               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      _______, KC_MPRV, KC_VOLD, KC_MNXT, KC_MPLY,                               _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                               _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 _______, _______, FUNC_L,     _______, _______, _______
                             //`--------------------------'  `--------------------------'
    )
};
