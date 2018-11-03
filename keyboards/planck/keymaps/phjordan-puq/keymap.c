/* Copyright 2015-2017 Jack Humbert
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

/* Base layer with adnw-puq for german keyboard layout
 *
 *
 *
 *
 */

#include "planck.h"
#include "action_layer.h"
#include "muse.h"
#include "keymap_german.h"

extern keymap_config_t keymap_config;

/* Based on default - change _NUM replaces LOWER, _SYM replaces RAISE
 * */
enum planck_layers {
  _ADNW_PUQ,
  _UMLAUT,
  _SYM,
  _SYM_OVLY,
  _NUM,
  _NUM_OVLY,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define SYMLYR LT(_SYM,KC_LEFT)
#define NUMLYR LT(_NUM,KC_ESC)
#define SYMOVLY MO(_SYM_OVLY)
#define NUMOVLY MO(_NUM_OVLY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*Qwerty umgeschieben als adnw puq - für deutsches os tastaturlayout*/
/* Adnw-puq Tapped 
 * ,--------------------------------------------------------------------------------------.
 * |(^Alt) |   P  |   U  | UML  |   ,  |   Q  |   G  |   C  |   L  |   M  |   F  |(^GUI)  |
 * |-------+------+------+------+------+-------------+------+------+------+------+--------|
 * |(S-Alt)|   H  |   I  |   E  |   A  |   O  |   D  |   T  |   R  |   N  |   S  |(S-GUI) |
 * |-------+------+------+------+------+------|------+------+------+------+------+--------|
 * |(Shift)|   K  |   Y  |   .  |   '  |   X  |   J  |   V  |   W  |   B  |   Z  |(^Shift)|
 * |-------+------+------+------+------+------+------+------+------+------+------+--------|
 * | Ctrl  | GUI  | Alt  | ESC  | Bksp | Tab  |Enter |Space | Left | Down |  Up  | Right  |
 * `--------------------------------------------------------------------------------------'
 */

/* Bottom row held
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | NUM  |LSHFT | NAV  |  FN  |RSHFT |  SYM |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADNW_PUQ] = LAYOUT_planck_grid(
    OSM(MOD_LCTL | MOD_LALT), DE_P,    DE_U,    OSL(_UMLAUT), DE_COMM,              DE_Q,    DE_G,   DE_C,                DE_L,   DE_M,    DE_F,  OSM(MOD_RCTL | MOD_RGUI),
    OSM(MOD_LSFT | MOD_LALT), DE_H,    DE_I,    DE_E,         DE_A,                 DE_O,    DE_D,   DE_T,                DE_R,   DE_N,    DE_S,  OSM(MOD_RSFT | MOD_RGUI),
    OSM(MOD_LSFT),            DE_K,    DE_Y,    DE_DOT,       DE_QUOT,              DE_X,    DE_J,   DE_V,                DE_W,   DE_B,    DE_Z,  OSM(MOD_RCTL | MOD_RSFT),
    OSM(MOD_LCTL),            KC_LGUI, KC_LALT, NUMLYR,       MT(MOD_LSFT,KC_BSPC), KC_TAB,  KC_ENT, MT(MOD_RSFT,KC_SPC), SYMLYR, KC_DOWN, KC_UP, KC_RGHT
),


/*Qwerty umgeschieben als adnw puq - für deutsches os tastaturlayout*/
/* Umlaut 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   Ü  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |   Ä  |   Ö  |      |      |      |      |   ß  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UMLAUT] = LAYOUT_planck_grid(
    _______,_______,  DE_UE,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,  DE_AE,  DE_OE,_______,_______,_______,_______,  DE_SS,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

/* Sym
 * ,-----------------------------------------------------------------------------------.
 * |     |  {   |   \  |   *  |   &  |   }  |      |      |  f9  |  f10 | f11  | f12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  §   |  (   |   ^  |   %  |   $  |   )  |      |      |  f5  |  f6  | f7   | f8   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  [   |   #  |   @  |   !  |   ]  |      | OVLY |  f1  |  f2  | f3   | f4   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   .  |   |  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    DE_EURO, DE_LCBR, DE_BSLS, DE_ASTR, DE_AMPR, DE_RCBR, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,
    DE_PARA,  DE_LPRN, DE_CIRC, DE_PERC, DE_DLR,  DE_RPRN, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    _______, DE_LBRC, DE_HASH, DE_AT,   DE_EXLM, DE_RBRC, _______, SYMOVLY, KC_F1,   KC_F2,   KC_F3,   KC_F4,
    _______, _______, _______, _______, DE_DOT,  DE_PIPE, _______, _______, _______, _______, _______, _______
),

/* Sym Overlay
 * ,-----------------------------------------------------------------------------------.
 * |      |  ´   |   ?  |   +  |   ~  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  "   |   <  |   >  |   =  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  `   |   3  |   2  |   1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   :  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM_OVLY] = LAYOUT_planck_grid(
    _______, DE_ACUT,       DE_QST,  DE_PLUS, DE_TILD, _______, _______, _______, _______, _______, _______, _______,
    _______, DE_DQOT,       DE_LESS, DE_MORE, DE_EQL,  _______, _______, _______, _______, _______, _______, _______,
    _______, LSFT(DE_ACUT), DE_3   , DE_2,    DE_1   , _______, _______, _______, _______, _______, _______, _______,
    _______, _______,       _______, _______, DE_COLN, _______, _______, _______, _______, _______, _______, _______
),


/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  /   |  7   |  8   |  9   |  *   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  .   |  4   |  5   |  6   |  -   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | OVLY |      |  ,   |  1   |  2   |  3   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  =   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_PSLS, DE_7, DE_8,    DE_9,    KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, KC_PDOT, DE_4, DE_5,    DE_6,    KC_PMNS, _______,
    _______, _______, _______, _______, NUMOVLY, _______, KC_PCMM, DE_1, DE_2,    DE_3,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______, DE_0, KC_PEQL, _______, _______, _______
),

/* Num-Overlay
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  {   |  &   |  *   |  \   |  }   |  °   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  (   |  $   |  %   |  ^   |  )   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  [   |  !   |  @   |  #   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  |   |  .   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM_OVLY] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, DE_LCBR, DE_AMPR, DE_ASTR,  DE_BSLS, DE_RCBR, DE_RING,
    _______, _______, _______, _______, _______, _______, DE_LPRN, DE_DLR,  DE_PERC, DE_CIRC, DE_RPRN, _______,
    _______, _______, _______, _______, _______, _______, DE_LBRC, DE_EXLM, DE_AT,   DE_HASH, DE_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, DE_PIPE, DE_DOT,  _______, _______, _______
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SYM, _NUM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_ADNW_PUQ);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
   }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_SYM)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SYMLYR:
    case NUMLYR:
      return false;
    default:
      return true;
  }
}
