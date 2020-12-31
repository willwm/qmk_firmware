/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1:       | Knob 2:       | Knob 3:       |
        | (Vol -/+)     | (RGB Mode)    | (PgDn/PgUp)   |
        | [Mute]        | [Toggle]      | [Play/Pause]  |
        |===============|===============|===============|
        | Hold: Layer 2 | Up            | Refresh       |
        | Left          | Down          | Right         |
     */
    [0] = LAYOUT(
        KC_MUTE, RGB_TOG, KC_MPLY,
        MO(1)  , KC_UP  , KC_WREF,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | RESET         | N/A       | N/A           |
        | Held: Layer 2 | Home      | N/A           |
        | Media Prev.   | End       | Media Next    |
     */
    [1] = LAYOUT(
        RESET  , KC_TRNS, KC_TRNS,
        _______, KC_HOME, KC_TRNS,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code16(RGB_RMOD);
        } else {
            tap_code16(RGB_MOD);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
