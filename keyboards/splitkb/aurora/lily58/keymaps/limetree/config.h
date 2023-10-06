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

#pragma once

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_EFFECT_CHRISTMAS
#   define RGBLIGHT_EFFECT_KNIGHT
#   define RGBLIGHT_EFFECT_RAINBOW_MOOD
#   define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#   define RGBLIGHT_EFFECT_RGB_TEST
#   define RGBLIGHT_EFFECT_SNAKE
#   define RGBLIGHT_EFFECT_STATIC_GRADIENT
#   define RGBLIGHT_EFFECT_TWINKLE
#endif

//#define DEBOUNCE 3
//#define USB_POLLING_INTERVAL_MS 1
//#define QMK_KEYS_PER_SCAN 12

#define OLED_TIMEOUT 60000
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define SPLIT_WPM_ENABLE
#define SPLIT_TRANSPORT_MIRROR


#define MOUSE_KEY_INTERVAL 1