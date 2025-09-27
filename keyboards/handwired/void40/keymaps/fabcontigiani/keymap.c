// Copyright 2023 QMK SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// QWERTY
// Left-hand home row mods
#define SFT_A     LSFT_T(KC_A)
#define SFT_F1    LSFT_T(KC_F1)

#define GUI_S     LGUI_T(KC_S)
#define GUI_F2    LGUI_T(KC_F2)

#define ALT_D     LALT_T(KC_D)
#define ALT_F3    LALT_T(KC_F3)

#define CTL_F     LCTL_T(KC_F)
#define CTL_F4    LCTL_T(KC_F4)

// Right-hand home row mods
#define CTL_J     RCTL_T(KC_J)
#define CTL_UNDS  RCTL_T(KC_UNDS)
#define CTL_MINS  RCTL_T(KC_MINS)

#define ALT_K     LALT_T(KC_K)
#define ALT_PLUS  LALT_T(KC_PLUS)
#define ALT_EQL   LALT_T(KC_EQL)

#define GUI_L     RGUI_T(KC_L)
#define GUI_LCBR  RGUI_T(KC_LCBR)
#define GUI_LBRC  RGUI_T(KC_LBRC)

#define SFT_SCLN  RSFT_T(KC_SCLN)
#define SFT_RCBR  RSFT_T(KC_RCBR)
#define SFT_RBRC  RSFT_T(KC_RBRC)

enum void40_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_ESC,  SFT_A,   GUI_S,   ALT_D,   CTL_F,   KC_G,    KC_H,    CTL_J,   ALT_K,   GUI_L,   SFT_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT ,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
    ),
  
    [_LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_BSPC,
        KC_DEL,  SFT_F1,  GUI_F2,  ALT_F3,  CTL_F4,  KC_F5,   KC_F6,   CTL_UNDS,   ALT_PLUS,   GUI_LCBR, SFT_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME,  KC_END,   _______,
        _______, _______, _______, _______, _______,      _______,     _______,    KC_MNXT,    KC_VOLD,  KC_VOLU,  KC_MPLY
    ),
    
    [_RAISE] = LAYOUT_planck_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        KC_DEL,  SFT_F1,  GUI_F2,  ALT_F3,  CTL_F4,  KC_F5,   KC_F6,   CTL_MINS, ALT_EQL,  GUI_LBRC, SFT_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN,  _______,
        _______, _______, _______, _______, _______,     _______,     _______,   KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY
    ),

    [_ADJUST] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    )
};
