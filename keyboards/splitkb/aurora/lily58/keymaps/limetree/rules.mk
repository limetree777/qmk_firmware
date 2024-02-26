# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# NOTE: These are already enabled by default at the revision level
#ENCODER_ENABLE = yes
#OLED_ENABLE = yes
RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE = yes


NKRO_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk
WPM_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

CONVERT_TO = liatris

SRC += features/select_word.c