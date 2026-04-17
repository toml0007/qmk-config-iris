#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FN
};

// Hold for Alt, tap for Esc — mirrors Zen 2 home row mod
#define ESC_ALT LALT_T(KC_ESC)

// Activate FN when both LOWER and RAISE are held simultaneously
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _FN);
}

// Iris rev4 LAYOUT argument order (56 keys total):
//
//  Row 0 (12):  L0–L5 then R5–R0
//  Row 1 (12):  L0–L5 then R5–R0
//  Row 2 (12):  L0–L5 then R5–R0
//  Row 3L (6):  L0–L5
//  Inner thumbs (2): Left-inner-upper, Right-inner-upper    ← interleaved here!
//  Row 3R (6):  R5–R0
//  Left  lower thumbs (3): outer → mid → inner
//  Right lower thumbs (3): inner → mid → outer
//
// Physical thumb cluster:
//   Left:                         Right:
//                 [inner-upper]   [inner-upper]
//   [outer][mid][inner-lower]     [inner-lower][mid][outer]
//
// Thumb assignments:
//   Left inner-upper  = BSPC   (bonus key)
//   Left  outer       = CMD
//   Left  mid         = LOWER
//   Left  inner-lower = SPACE
//   Right inner-upper = DEL    (bonus key)
//   Right inner-lower = ENTER
//   Right mid         = RAISE
//   Right outer       = RCTRL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
// ┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬──────┬──────┐
// │  =   │  1   │  2   │  3   │  4   │  5   │                    │  6   │  7   │  8   │  9   │  0   │  -   │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ TAB  │  Q   │  W   │  E   │  R   │  T   │                    │  Y   │  U   │  I   │  O   │  P   │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ESC/⌥ │  A   │  S   │  D   │  F   │  G   │                    │  H   │  J   │  K   │  L   │  ;   │  '   │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ SHFT │  Z   │  X   │  C   │  V   │  B   │ [BSPC] │ [DEL ] │  N   │  M   │  ,   │  .   │  /   │ SHFT │
// └──────┴──────┴──────┴──────┴──────┴──────┘                    └──────┴──────┴──────┴──────┴──────┴──────┘
//                      ┌──────┬──────┬──────┐                    ┌──────┬──────┬──────┐
//                      │ CMD  │ LWR  │ SPC  │                    │ ENT  │ RSE  │RCTRL │
//                      └──────┴──────┴──────┘                    └──────┴──────┴──────┘
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        ESC_ALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_BSPC, KC_DEL,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LGUI, MO(_LOWER), KC_SPC,
        KC_ENT,  MO(_RAISE), KC_RCTL
    ),

    [_LOWER] = LAYOUT(
// ┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬──────┬──────┐
// │  ~   │  F1  │  F2  │  F3  │  F4  │  F5  │                    │  F6  │  F7  │  F8  │  F9  │ F10  │ DEL  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │  ~   │  1   │  2   │  3   │  4   │  5   │                    │  6   │  7   │  8   │  9   │  0   │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                    │      │ HOME │  UP  │ END  │ PGUP │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ SHFT │      │      │      │      │      │ [    ] │ [    ] │      │ LEFT │ DOWN │ RGT  │ PGDN │  ~   │
// └──────┴──────┴──────┴──────┴──────┴──────┘                    └──────┴──────┴──────┴──────┴──────┴──────┘
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TILD,
        KC_LGUI, MO(_LOWER), KC_SPC,
        KC_ENT,  MO(_RAISE), KC_RCTL
    ),

    [_RAISE] = LAYOUT(
// ┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬──────┬──────┐
// │  ~   │  !   │  @   │  #   │  $   │  %   │                    │  ^   │  &   │  *   │  (   │  )   │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │  ~   │  !   │  @   │  #   │  $   │  %   │                    │  ^   │  &   │  *   │  (   │  )   │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ESC/⌥ │ ⌘⇧[  │ ⌘⇧]  │      │      │      │                    │  -   │  =   │  [   │  ]   │  \   │  `   │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ SHFT │  ⌘`  │ ⌘⇧`  │      │      │      │ [    ] │ [    ] │  _   │  +   │  {   │  }   │  |   │  ~   │
// └──────┴──────┴──────┴──────┴──────┴──────┘                    └──────┴──────┴──────┴──────┴──────┴──────┘
        KC_TILD, KC_EXLM,       KC_AT,            KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_TILD, KC_EXLM,       KC_AT,            KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        ESC_ALT, SGUI(KC_LBRC), SGUI(KC_RBRC),    KC_TRNS, KC_TRNS, KC_TRNS,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        KC_LSFT, LGUI(KC_GRV),  LGUI(LSFT(KC_GRV)), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        KC_LGUI, MO(_LOWER), KC_SPC,
        KC_ENT,  MO(_RAISE), KC_RCTL
    ),

    [_FN] = LAYOUT(
// ┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬──────┬──────┐
// │      │      │      │      │      │      │                    │      │      │      │      │ F11  │ F12  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  F1  │  F2  │  F3  │  F4  │  F5  │                    │  F6  │  F7  │  F8  │  F9  │ F10  │ DEL  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │ F12  │ PREV │ PLAY │ NEXT │      │                    │      │ VOL- │ VOL+ │ MUTE │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ SHFT │      │      │      │      │ ⇧⌘4  │ [    ] │ [    ] │ ⌃⇧⌘4 │ BRI- │ BRI+ │      │      │      │
// └──────┴──────┴──────┴──────┴──────┴──────┘                    └──────┴──────┴──────┴──────┴──────┴──────┘
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS, KC_F12,  KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,   KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SGUI(KC_4),
        KC_TRNS, KC_TRNS,
        LCTL(LSFT(LGUI(KC_4))), KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LGUI, MO(_LOWER), KC_SPC,
        KC_ENT,  MO(_RAISE), KC_RCTL
    ),
};
