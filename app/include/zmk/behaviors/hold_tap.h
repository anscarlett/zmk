/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <zephyr/kernel.h>
#include <zmk/behavior.h>

enum zmk_behavior_hold_tap_state {
    ZMK_BEHAVIOR_HOLD_TAP_STATE_UNDECIDED = 0,
    ZMK_BEHAVIOR_HOLD_TAP_STATE_TAP = 1,
    ZMK_BEHAVIOR_HOLD_TAP_STATE_HOLD_INTERRUPT = 2,
    ZMK_BEHAVIOR_HOLD_TAP_STATE_HOLD_TIMER = 3,
};

struct zmk_behavior_hold_tap_active_state {
    uint32_t position;
    uint8_t source;
    int64_t timestamp;
    enum zmk_behavior_hold_tap_state state;
    zmk_behavior_local_id_t hold_behavior_local_id;
    zmk_behavior_local_id_t tap_behavior_local_id;
    uint32_t param_hold;
    uint32_t param_tap;
};

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_HOLD_TAP)
#define ZMK_BEHAVIOR_HOLD_TAP_ACTIVE_STATE_MAX CONFIG_ZMK_BEHAVIOR_HOLD_TAP_MAX_HELD
#else
#define ZMK_BEHAVIOR_HOLD_TAP_ACTIVE_STATE_MAX 1
#endif

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_HOLD_TAP)
size_t zmk_behavior_hold_tap_get_active_states(
    size_t max_states, struct zmk_behavior_hold_tap_active_state states[max_states]);
#else
static inline size_t zmk_behavior_hold_tap_get_active_states(
    size_t max_states, struct zmk_behavior_hold_tap_active_state states[max_states]) {
    ARG_UNUSED(max_states);
    ARG_UNUSED(states);
    return 0;
}
#endif
