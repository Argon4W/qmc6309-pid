#include "qmc6309_reg.h"

int32_t WEAK qmc6309_raw_read_register(
	const qmc_context_t*	context,
	uint8_t					register_address,
	uint8_t*				buffer,
	uint16_t				length
) {
	// We cannot proceed without the context.
	if (context == NULL) {
		return -1;
	}

	return context->read_register_function(
		/* user_handle		= */ context->user_handle,
		/* register_address	= */ register_address,
		/* buffer			= */ buffer,
		/* length			= */ length
	);
}

int32_t WEAK qmc6309_raw_write_register(
	const qmc_context_t*	context,
	uint8_t					register_address,
	uint8_t*				buffer,
	uint16_t				length
) {
	// We cannot proceed without the context.
	if (context == NULL) {
		return -1;
	}

	return context->write_register_function(
		/* user_handle		= */ context->user_handle,
		/* register_address	= */ register_address,
		/* buffer			= */ buffer,
		/* length			= */ length
	);
}

int32_t WEAK qmc6309_raw_chip_id_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CHIP_ID,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_x_lsb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_X_L,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_x_msb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_X_H,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_y_lsb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Y_L,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_y_msb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Y_H,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_z_lsb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Z_L,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_mag_z_msb_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Z_H,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_status_1_get(const qmc_context_t* context, qmc6309_status_1_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_STATUS_1,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_1_set(const qmc_context_t* context, qmc6309_control_1_t val) {
	return qmc6309_raw_write_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_1,
		/* buffer			= */ (uint8_t*) &val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_1_get(const qmc_context_t* context, qmc6309_control_1_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_1,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_2_set(const qmc_context_t* context, qmc6309_control_2_t val) {
	return qmc6309_raw_write_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_2,
		/* buffer			= */ (uint8_t*) &val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_2_get(const qmc_context_t* context, qmc6309_control_2_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_2,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_3_set(const qmc_context_t* context, qmc6309_control_3_t val) {
	return qmc6309_raw_write_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_3,
		/* buffer			= */ (uint8_t*) &val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_control_3_get(const qmc_context_t* context, qmc6309_control_3_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_CONTROL_3,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_selftest_x_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_SELF_TEST_X,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_selftest_y_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_SELF_TEST_Y,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

int32_t WEAK qmc6309_raw_selftest_z_get(const qmc_context_t* context, uint8_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_SELF_TEST_Z,
		/* buffer			= */ val,
		/* length			= */ 1
	);
}

// Gauss-per-LSB at each full scale range.
const float_t qmc6309_g_per_lsb_32g	= 1.0f / 32767.0f * 8;	// Gauss-per-LSB at 32G full scale range..
const float_t qmc6309_g_per_lsb_16g	= 1.0f / 32767.0f * 16;	// Gauss-per-LSB at 16G full scale range.
const float_t qmc6309_g_per_lsb_8g	= 1.0f / 32767.0f * 32;	// Gauss-per-LSB at 8G full scale range

// Look-up table of the Gauss-per-LSB.
const float_t qmc6309_g_per_lsb[3] = {
	/* qmc6309_g_per_lsb[RNG_32G]	= */ qmc6309_g_per_lsb_32g,
	/* qmc6309_g_per_lsb[RNG_16G]	= */ qmc6309_g_per_lsb_16g,
	/* qmc6309_g_per_lsb[RNG_8G]	= */ qmc6309_g_per_lsb_8g
};

float_t WEAK qmc6309_ll_from_rng8_to_gauss(int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_8g;
}

float_t WEAK qmc6309_ll_from_rng16_to_gauss(int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_16g;
}

float_t WEAK qmc6309_ll_from_rng32_to_gauss(int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_32g;
}

int32_t WEAK qmc6309_ll_mag_x_get(const qmc_context_t* context, qmc6309_out_single_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_X_L,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 2
	);
}

int32_t WEAK qmc6309_ll_mag_y_get(const qmc_context_t* context, qmc6309_out_single_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Y_L,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 2
	);
}

int32_t WEAK qmc6309_ll_mag_z_get(const qmc_context_t* context, qmc6309_out_single_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Z_L,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 2
	);
}

int32_t WEAK qmc6309_ll_mag_get(const qmc_context_t* context, qmc6309_out_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_X_L,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 6
	);
}

int32_t WEAK qmc6309_ll_status_1_drdy_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	*val = status_1.drdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_ovfl_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	*val = status_1.ovfl_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_st_rdy_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	*val = status_1.st_rdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_nvm_rdy_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	*val = status_1.nvm_rdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_nvm_load_done_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	*val = status_1.drdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_mode_set(const qmc_context_t* context, qmc6309_mode_t val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Modify on the existing register data to prevent overriding other bits.
	control_1.mode = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_1_set(context, control_1));

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_mode_get(const qmc_context_t* context, qmc6309_mode_t* val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	*val = control_1.mode;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr1_set(const qmc_context_t* context, qmc6309_osr1_t val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Modify on the existing register data to prevent overriding other bits.
	control_1.osr1 = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_1_set(context, control_1));

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr1_get(const qmc_context_t* context, qmc6309_osr1_t* val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	*val = control_1.osr1;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr2_set(const qmc_context_t* context, qmc6309_osr2_t val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Modify on the existing register data to prevent overriding other bits.
	control_1.osr2 = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_1_set(context, control_1));

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr2_get(const qmc_context_t* context, qmc6309_osr2_t* val) {
	qmc6309_control_1_t control_1 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	*val = control_1.osr2;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_set_reset_mode_set(const qmc_context_t* context, qmc6309_set_reset_mode_t val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Modify on the existing register data to prevent overriding other bits.
	control_2.set_reset_mode = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_set_reset_mode_get(const qmc_context_t* context, qmc6309_set_reset_mode_t* val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	*val = control_2.set_reset_mode;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_rng_set(const qmc_context_t* context, qmc6309_rng_t val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Modify on the existing register data to prevent overriding other bits.
	control_2.rng = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_rng_get(const qmc_context_t* context, qmc6309_rng_t* val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	*val = control_2.rng;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_odr_set(const qmc_context_t* context, qmc6309_odr_t val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Modify on the existing register data to prevent overriding other bits.
	control_2.odr = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_odr_get(const qmc_context_t* context, qmc6309_odr_t* val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	*val = control_2.odr;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_soft_rst_set(const qmc_context_t* context, uint8_t val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Modify on the existing register data to prevent overriding other bits.
	control_2.soft_rst = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_soft_rst_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_control_2_t control_2 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	*val = control_2.soft_rst;

	return 0;
}

int32_t WEAK qmc6309_ll_control_3_selftest_set(const qmc_context_t* context, uint8_t val) {
	qmc6309_control_3_t control_3 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_3_get(context, &control_3));

	// Modify on the existing register data to prevent overriding other bits.
	control_3.selftest = val;

	// Set the modified register data.
	FAIL_FAST(qmc6309_raw_control_3_set(context, control_3));

	return 0;
}

int32_t WEAK qmc6309_ll_control_3_selftest_get(const qmc_context_t* context, uint8_t* val) {
	qmc6309_control_3_t control_3 = {0};

	// Get the full register data.
	FAIL_FAST(qmc6309_raw_control_3_get(context, &control_3));

	*val = control_3.selftest;

	return 0;
}

int32_t WEAK qmc6309_ll_selftest_get(const qmc_context_t* context, qmc6309_selftest_out_t* val) {
	return qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_SELF_TEST_X,
		/* buffer			= */ (uint8_t*) val,
		/* length			= */ 3
	);
}

int32_t WEAK qmc6309_hl_soft_reset(const qmc_context_t* context) {
	// perform the soft reset.
	FAIL_FAST(qmc6309_ll_control_2_soft_rst_set(context, PROPERTY_ENABLE));	// Enable the soft reset.
	FAIL_FAST(qmc6309_ll_control_2_soft_rst_set(context, PROPERTY_DISABLE));	// Manually disable the soft reset.

	return 0;
}

int32_t WEAK qmc6309_hl_setup_typical(const qmc_context_t* context, qmc6309_mode_t val) {
	const qmc6309_setup_t setup = {
		.mode			= val,
		.set_reset_mode	= SET_RESET_ON,
		.rng			= RNG_32G,
		.odr			= ODR_200HZ,
		.osr1			= OSR1_8,
		.osr2			= OSR2_8
	};

	return qmc6309_hl_setup(context, setup);
}

int32_t WEAK qmc6309_hl_setup(const qmc_context_t* context, qmc6309_setup_t val) {
	const qmc6309_control_1_t control_1 = {
		.mode		= val.mode,
		.reserved	= 0U,
		.osr1		= val.osr1,
		.osr2		= val.osr2,
	};

	const qmc6309_control_2_t control_2 = {
		.set_reset_mode	= val.set_reset_mode,
		.rng			= val.rng,
		.odr			= val.odr,
		.soft_rst		= PROPERTY_DISABLE
	};

	FAIL_FAST(qmc6309_raw_control_1_set(context, control_1));
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_hl_mode_switch(const qmc_context_t* context, qmc6309_mode_t val) {
	// Switch to suspend mode first before switching to other modes.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, SUSPEND));

	if (val == SUSPEND) {
		// Abort since we are already in suspend mode.
		return 0;
	}

	// Switch to the actual mode we want.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, val));

	return 0;
}

int32_t WEAK qmc6309_hl_selftest(const qmc_context_t* context, uint8_t* val) {
	// Cannot proceed without the delay function.
	if (context->delay_milliseconds_function == NULL) {
		return -1;
	}

	// Variable holding the original device mode before the self-test.
	qmc6309_mode_t mode;

	FAIL_FAST(qmc6309_ll_control_1_mode_get(context, &mode));		// Record the original device mode.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, SUSPEND));		// Switch to suspend mode before switching to continuous mode.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, CONTINUOUS));	// Switch to continuous mode for self-test.

	// Wait 20 milliseconds until measurement ends.
	context->delay_milliseconds_function(20);

	// Set self-test enable.
	FAIL_FAST(qmc6309_ll_control_3_selftest_set(context, PROPERTY_ENABLE));

	// Wait 150 milliseconds until measurement ends.
	context->delay_milliseconds_function(150);

	uint8_t ready = 0U;

	do {
		// Check if the self-test data is ready to read.
		FAIL_FAST(qmc6309_ll_status_1_st_rdy_get(context, &ready));

		// Wait 1 millisecond until next self-test ready check.
		context->delay_milliseconds_function(1);
	} while (!ready);

	qmc6309_selftest_out_t selftest_out = {0};

	FAIL_FAST(qmc6309_ll_selftest_get		(context, &selftest_out));	// Read the output data of the self-test to judge if the device is working properly.
	FAIL_FAST(qmc6309_ll_control_1_mode_set	(context, SUSPEND));		// Switch to suspend mode before restoring mode.
	FAIL_FAST(qmc6309_ll_control_1_mode_set	(context, mode));			// Restore the original device mode before the self-test.

	if (	selftest_out.selftest_out_x >= -50
		&&	selftest_out.selftest_out_x <= -1
		&&	selftest_out.selftest_out_y >= -50
		&&	selftest_out.selftest_out_y <= -1
		&&	selftest_out.selftest_out_z >= -50
		&&	selftest_out.selftest_out_z <= -1
	) {
		*val = PROPERTY_ENABLE;
	} else {
		*val = PROPERTY_DISABLE;
	}

	return 0;
}

int32_t WEAK qmc6309_hl_mag_get(const qmc_context_t* context, qmc6309_rng_t rng, qmc6309_out_full_t* val) {
	qmc6309_status_1_t status_1 = {0};

	// Check if the data output is ready to read and the data overflow status.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// We cannot proceed if the data is not ready.
	if (!status_1.drdy_bit) {
		return 0;
	}

	// Store the data ststus to the full output struct.
	val->output_ready		= status_1.drdy_bit; // Store the data-ready status.
	val->output_overflow	= status_1.ovfl_bit; // Store the data overflow status.

	// Buffer to hold the raw output data read from registers.
	qmc6309_out_t out = {0};

	// Select the correct gauss_per_lsb from the look-up table.
	float_t gauss_per_lsb = qmc6309_g_per_lsb[rng];

	// Read the data output.
	FAIL_FAST(qmc6309_ll_mag_get(context, &out));

	// Convert and store the data to the full output sturct.
	val->output_gauss_x = ((float_t) out.out_x.out_single) * gauss_per_lsb; // Convert and store the X-Axis raw data.
	val->output_gauss_y = ((float_t) out.out_y.out_single) * gauss_per_lsb; // Convert and store the Y-Axis raw data.
	val->output_gauss_z = ((float_t) out.out_z.out_single) * gauss_per_lsb; // Convert and store the Z-Axis raw data.

	return 0;
}