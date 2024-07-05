#include QMK_KEYBOARD_H

#include "mikybars.h"
#include "features/layer_lock.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();
  const bool shifted = (mods | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

  if (record->event.pressed) {
    switch (keycode) {
      case ARROW:  // -> Unicode arrow, or => when shifted.
        send_unicode_string(shifted ? "=>" : "->");
        return false;
    }
  }

  return true;
}
