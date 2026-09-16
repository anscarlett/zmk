/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <zephyr/kernel.h>
#include <zmk/event_manager.h>

struct zmk_behavior_hold_tap_state_changed {
    int64_t timestamp;
};

ZMK_EVENT_DECLARE(zmk_behavior_hold_tap_state_changed);

static inline int raise_behavior_hold_tap_state_changed(void) {
    return raise_zmk_behavior_hold_tap_state_changed(
        (struct zmk_behavior_hold_tap_state_changed){.timestamp = k_uptime_get()});
}
