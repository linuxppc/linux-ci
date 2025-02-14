/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2015, Intel Corporation.
 */

#ifndef __IA_CSS_CONTROL_H
#define __IA_CSS_CONTROL_H

/* @file
 * This file contains functionality for starting and controlling CSS
 */

#include <type_support.h>
#include <ia_css_env.h>
#include <ia_css_firmware.h>
#include <ia_css_irq.h>

/* @brief Initialize the CSS API.
 * @param[in]	env		Environment, provides functions to access the
 *				environment in which the CSS code runs. This is
 *				used for host side memory access and message
 *				printing. May not be NULL.
 * @param[in]	l1_base         Base index (isp2400)
 *                              of the L1 page table. This is a physical
 *                              address or index.
 * @param[in]	irq_type	The type of interrupt to be used (edge or level)
 * @return			Returns -EINVAL in case of any
 *				errors and 0 otherwise.
 *
 * This function initializes the API which includes allocating and initializing
 * internal data structures.
 * ia_css_load_firmware() must be called to load the firmware before calling
 * this function.
 */
int ia_css_init(struct device           *dev,
		const struct ia_css_env *env,
		u32                     l1_base,
		enum ia_css_irq_type    irq_type);

/* @brief Un-initialize the CSS API.
 * @return	None
 *
 * This function deallocates all memory that has been allocated by the CSS API.
 * After this function is called, no other CSS functions should be called.
 */
void
ia_css_uninit(void);

/* @brief Enable use of a separate queue for ISYS events.
 *
 * @param[in]	enable: enable or disable use of separate ISYS event queues.
 * @return		error if called when SP is running.
 *
 * @deprecated{This is a temporary function that allows drivers to migrate to
 * the use of the separate ISYS event queue. Once all drivers supports this, it
 * will be made the default and this function will be removed.
 * This function should only be called when the SP is not running, calling it
 * when the SP is running will result in an error value being returned. }
 */
int
ia_css_enable_isys_event_queue(bool enable);

/* @brief Test whether the ISP has started.
 *
 * @return	Boolean flag true if the ISP has started or false otherwise.
 *
 * Temporary function to poll whether the ISP has been started. Once it has,
 * the sensor can also be started. */
bool
ia_css_isp_has_started(void);

/* @brief Test whether the SP has initialized.
 *
 * @return	Boolean flag true if the SP has initialized or false otherwise.
 *
 * Temporary function to poll whether the SP has been initialized. Once it has,
 * we can enqueue buffers. */
bool
ia_css_sp_has_initialized(void);

/* @brief Test whether the SP has terminated.
 *
 * @return	Boolean flag true if the SP has terminated or false otherwise.
 *
 * Temporary function to poll whether the SP has been terminated. Once it has,
 * we can switch mode. */
bool
ia_css_sp_has_terminated(void);

/* @brief start SP hardware
 *
 * @return			0 or error code upon error.
 *
 * It will boot the SP hardware and start multi-threading infrastructure.
 * All threads will be started and blocked by semaphore. This function should
 * be called before any ia_css_stream_start().
 */
int
ia_css_start_sp(void);

/* @brief stop SP hardware
 *
 * @return			0 or error code upon error.
 *
 * This function will terminate all threads and shut down SP. It should be
 * called after all ia_css_stream_stop().
 */
int
ia_css_stop_sp(void);

#endif /* __IA_CSS_CONTROL_H */
