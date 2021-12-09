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
  _LEFT, // 0
  _RIGHT, // 1
  _MIDDLE, // 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | n/a               | n/a                   | Play/Pause         |
        | To: Layer 1       | Switch Audio Output   | F10                |
        | Left              | Down                  | Right              |
     */
    [0] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_MPLY,
        TO(1)  , RCTL(KC_F12), KC_F10,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | n/a               | n/a                   | RGB On/Off         |
        | To: Layer 0       | Switch Audio Output   | F10                |
        | Left              | Down                  | Right              |
     */
    [1] = LAYOUT(
        XXXXXXX  , XXXXXXX, RGB_TOG,
        TO(0), RCTL(KC_F12), KC_F10,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

/**
 * Rotary Encoders
 * Array entry is
 * [layer_name] = {{left_ccw, left_cw}, {right_ccw, right_cw}, {mid_ccw, mid_cw}},
 * etc...
 * {{ , }, { , }, { , }},
 */
const uint16_t PROGMEM encoders[][3][2] = {
    [0] = {{KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK}, {KC_VOLD, KC_VOLU}, {KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD}},
    [1] = {{KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK}, {KC_VOLD, KC_VOLU}, {KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD}}, //ignored
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case 1:
            switch (index) {
                case _LEFT:
                    if (clockwise){
                        rgblight_increase_val();
                    } else{
                        rgblight_decrease_val();
                    }
                    break;
                case _MIDDLE:
                    if (clockwise){
                        rgblight_increase_hue();
                    } else{
                        rgblight_decrease_hue();
                    }
                    break;
                case _RIGHT:
                    if (clockwise){
                        rgblight_step();
                    } else{
                        rgblight_step_reverse();
                    }
                    break;
            }
            break;
        default:
            tap_code16(pgm_read_word(&encoders[layer][index][clockwise]));
            break;
    }
    return true;
}
