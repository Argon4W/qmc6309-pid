#include "qmc6309_reg.h"

int32_t WEAK qmc6309_raw_read_register(
	const	qmc_context_t*	context,
	const	uint8_t			address,
			uint8_t*		buffer,
	const	uint16_t		length
) {
	// We cannot proceed without the context.
	if (context == NULL) {
		return -1;
	}

	// Read from the registers.
	return context->read_register(
		/* user_handle	= */ context->user_handle,
		/* address		= */ address,
		/* buffer		= */ buffer,
		/* length		= */ length
	);
}

int32_t WEAK qmc6309_raw_write_register(
	const qmc_context_t*	context,
	const uint8_t			address,
	const uint8_t*			buffer,
	const uint16_t			length
) {
	// We cannot proceed without the context.
	if (context == NULL) {
		return -1;
	}

	// Write to the registers.
	return context->write_register(
		/* user_handle	= */ context->user_handle,
		/* address		= */ address,
		/* buffer		= */ buffer,
		/* length		= */ length
	);
}

int32_t WEAK qmc6309_raw_chip_id_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the CHIP_ID register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CHIP_ID,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_x_lsb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_X_L register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_X_L,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_x_msb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_X_H register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_X_H,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_y_lsb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_Y_L register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_Y_L,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_y_msb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_Y_H register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_Y_H,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_z_lsb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_Z_L register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_Z_L,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_mag_z_msb_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the OUT_Z_H register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_Z_H,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_status_1_get(const qmc_context_t* context, qmc6309_raw_status_1_t* val) {
	// Read from the STATUS_1 register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_STATUS_1,
		/* buffer	= */ (uint8_t*) val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_1_set(const qmc_context_t* context, const qmc6309_raw_control_1_t val) {
	// Write to the CONTROL_1 register.
	return qmc6309_raw_write_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_1,
		/* buffer	= */ (const uint8_t*) &val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_1_get(const qmc_context_t* context, qmc6309_raw_control_1_t* val) {
	// Read from the CONTROL_1 register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_1,
		/* buffer	= */ (uint8_t*) val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_2_set(const qmc_context_t* context, const qmc6309_raw_control_2_t val) {
	// Write to the CONTROL_2 register.
	return qmc6309_raw_write_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_2,
		/* buffer	= */ (const uint8_t*) &val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_2_get(const qmc_context_t* context, qmc6309_raw_control_2_t* val) {
	// Read from the CONTROL_2 register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_2,
		/* buffer	= */ (uint8_t*) val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_3_set(const qmc_context_t* context, const qmc6309_raw_control_3_t val) {
	// Write to the CONTROL_3 register.
	return qmc6309_raw_write_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_3,
		/* buffer	= */ (const uint8_t*) &val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_control_3_get(const qmc_context_t* context, qmc6309_raw_control_3_t* val) {
	// Read from the CONTROL_3 register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_CONTROL_3,
		/* buffer	= */ (uint8_t*) val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_selftest_x_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the SELF_TEST_X register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_SELF_TEST_X,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_selftest_y_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the SELF_TEST_Y register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_SELF_TEST_Y,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_selftest_z_get(const qmc_context_t* context, uint8_t* val) {
	// Read from the SELF_TEST_Z register.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_SELF_TEST_Z,
		/* buffer	= */ val,
		/* length	= */ 1U
	);
}

int32_t WEAK qmc6309_raw_selftest_get(const qmc_context_t* context, qmc6309_raw_selftest_out_t* val) {
	// Read from the SELF_TEST_X, SELF_TEST_Y, SELF_TEST_Z registers.
	return qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_SELF_TEST_X,
		/* buffer	= */ (uint8_t*) val,
		/* length	= */ 3U
	);
}

// Gauss-per-LSB at each full scale range.
const float_t qmc6309_g_per_lsb_32g	= 1.0f / 1000.0f;
const float_t qmc6309_g_per_lsb_16g	= 1.0f / 2000.0f;
const float_t qmc6309_g_per_lsb_8g	= 1.0f / 4000.0f;

// Look-up table of the Gauss-per-LSB.
const float_t qmc6309_g_per_lsb[3U] = {
	qmc6309_g_per_lsb_32g,
	qmc6309_g_per_lsb_16g,
	qmc6309_g_per_lsb_8g
};

float_t WEAK qmc6309_ll_from_rng8_to_gauss(const int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_8g;
}

float_t WEAK qmc6309_ll_from_rng16_to_gauss(const int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_16g;
}

float_t WEAK qmc6309_ll_from_rng32_to_gauss(const int16_t lsb) {
	return ((float_t) lsb) * qmc6309_g_per_lsb_32g;
}

int32_t WEAK qmc6309_ll_mag_x_get(const qmc_context_t* context, int16_t* val) {
	// Reserve 2 bytes for the output.
	uint8_t buffer[2U];

	// Read from the LSB and HSB registers.
	FAIL_FAST(qmc6309_raw_read_register(
		/* context	= */ context,
		/* address	= */ QMC6309_OUT_X_L,
		/* buffer	= */ buffer,
		/* length	= */ 2U
	));

	// Pack 2 bytes into a signed short.
	*val = (int16_t) (((uint16_t) buffer[1U] << 8U) | buffer[0U]);

	return 0;
}

int32_t WEAK qmc6309_ll_mag_y_get(const qmc_context_t* context, int16_t* val) {
	// Reserve 2 bytes for the output.
	uint8_t buffer[2U];

	// Read from the LSB and HSB registers.
	FAIL_FAST(qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Y_L,
		/* buffer			= */ buffer,
		/* length			= */ 2U
	));

	// Pack 2 bytes into a signed short.
	*val = (int16_t) (((uint16_t) buffer[1U] << 8U) | buffer[0U]);

	return 0;
}

int32_t WEAK qmc6309_ll_mag_z_get(const qmc_context_t* context, int16_t* val) {
	// Reserve 2 bytes for the output.
	uint8_t buffer[2U];

	// Read from the LSB and HSB registers.
	FAIL_FAST(qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_Z_L,
		/* buffer			= */ buffer,
		/* length			= */ 2U
	));

	// Pack 2 bytes into a signed short.
	*val = (int16_t) (((uint16_t) buffer[1U] << 8U) | buffer[0U]);

	return 0;
}

int32_t WEAK qmc6309_ll_mag_get(const qmc_context_t* context, qmc6309_ll_out_t* val) {
	// Reserve 6 bytes for the output.
	uint8_t buffer[6U];

	// Read from all output registers.
	qmc6309_raw_read_register(
		/* context			= */ context,
		/* register_address	= */ QMC6309_OUT_X_L,
		/* buffer			= */ buffer,
		/* length			= */ 6U
	);

	// Pack every 2 bytes into signed shorts.
	val->out_x = (int16_t) (((uint16_t) buffer[1U] << 8U) | buffer[0U]);
	val->out_y = (int16_t) (((uint16_t) buffer[3U] << 8U) | buffer[2U]);
	val->out_z = (int16_t) (((uint16_t) buffer[5U] << 8U) | buffer[4U]);

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_drdy_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Read from the STATUS_1 register.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the value of DRDY bit of STATUS_1 register.
	*val = status_1.drdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_ovfl_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Read from the STATUS_1 register.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the value of OVFL bit of STATUS_1 register.
	*val = status_1.ovfl_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_st_rdy_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Read from the STATUS_1 register.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the value of ST_RDY bit of STATUS_1 register.
	*val = status_1.st_rdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_nvm_rdy_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Read from the STATUS_1 register.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the value of ST_RDY bit of STATUS_1 register.
	*val = status_1.nvm_rdy_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_status_1_nvm_load_done_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Read from the STATUS_1 register.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the value of NVM_LOAD_DONE bit of STATUS_1 register.
	*val = status_1.nvm_load_done_bit;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_mode_set(const qmc_context_t* context, const qmc6309_mode_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Set MODE on the existing value to prevent overwriting other bits.
	control_1.mode = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_1_set(context, control_1);
}

int32_t WEAK qmc6309_ll_control_1_mode_get(const qmc_context_t* context, qmc6309_mode_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Return the value of MODE of CONTROL_1 register.
	*val = control_1.mode;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr1_set(const qmc_context_t* context, const qmc6309_osr1_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Set OSR1 on the existing value to prevent overwriting other bits.
	control_1.osr1 = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_1_set(context, control_1);
}

int32_t WEAK qmc6309_ll_control_1_osr1_get(const qmc_context_t* context, qmc6309_osr1_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Return the value of OSR1 of CONTROL_1 register.
	*val = control_1.osr1;

	return 0;
}

int32_t WEAK qmc6309_ll_control_1_osr2_set(const qmc_context_t* context, const qmc6309_osr2_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Set OSR2 on the existing value to prevent overwriting other bits.
	control_1.osr2 = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_1_set(context, control_1);
}

int32_t WEAK qmc6309_ll_control_1_osr2_get(const qmc_context_t* context, qmc6309_osr2_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_1_t control_1 = {0U};

	// Read from the CONTROL_1 register.
	FAIL_FAST(qmc6309_raw_control_1_get(context, &control_1));

	// Return the value of OSR2 of CONTROL_1 register.
	*val = control_1.osr2;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_set_reset_mode_set(const qmc_context_t* context, const qmc6309_set_reset_mode_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Set SET_RESET_MODE on the existing value to prevent overwriting other bits.
	control_2.set_reset_mode = val;

	// Write to the CONTROL_2 register.
	return qmc6309_raw_control_2_set(context, control_2);
}

int32_t WEAK qmc6309_ll_control_2_set_reset_mode_get(const qmc_context_t* context, qmc6309_set_reset_mode_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Return the value of SET_RESET_MODE of CONTROL_2 register.
	*val = control_2.set_reset_mode;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_rng_set(const qmc_context_t* context, const qmc6309_rng_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Set RNG on the existing value to prevent overwriting other bits.
	control_2.rng = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_2_set(context, control_2);
}

int32_t WEAK qmc6309_ll_control_2_rng_get(const qmc_context_t* context, qmc6309_rng_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Return the value of RNG of CONTROL_2 register.
	*val = control_2.rng;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_odr_set(const qmc_context_t* context, const qmc6309_odr_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Set ODR on the existing value to prevent overwriting other bits.
	control_2.odr = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_2_set(context, control_2);
}

int32_t WEAK qmc6309_ll_control_2_odr_get(const qmc_context_t* context, qmc6309_odr_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Return the value of ODR of CONTROL_2 register.
	*val = control_2.odr;

	return 0;
}

int32_t WEAK qmc6309_ll_control_2_soft_rst_set(const qmc_context_t* context, const uint8_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Set SOFT_RST bit on the existing value to prevent overwriting other bits.
	control_2.soft_rst = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_2_set(context, control_2);
}

int32_t WEAK qmc6309_ll_control_2_soft_rst_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_2_t control_2 = {0U};

	// Read from the CONTROL_2 register.
	FAIL_FAST(qmc6309_raw_control_2_get(context, &control_2));

	// Return the value of SOFT_RST bit of CONTROL_2 register.
	*val = control_2.soft_rst;

	return 0;
}

int32_t WEAK qmc6309_ll_control_3_selftest_set(const qmc_context_t* context, const uint8_t val) {
	// Reserve space for the read.
	qmc6309_raw_control_3_t control_3 = {0U};

	// Read from the CONTROL_3 register.
	FAIL_FAST(qmc6309_raw_control_3_get(context, &control_3));

	// Set SELFTEST bit on the existing value to prevent overwriting other bits.
	control_3.selftest = val;

	// Write to the CONTROL_1 register.
	return qmc6309_raw_control_3_set(context, control_3);
}

int32_t WEAK qmc6309_ll_control_3_selftest_get(const qmc_context_t* context, uint8_t* val) {
	// Reserve space for the read.
	qmc6309_raw_control_3_t control_3 = {0U};

	// Read from the CONTROL_3 register.
	FAIL_FAST(qmc6309_raw_control_3_get(context, &control_3));

	// Return the value of SELFTEST bit of CONTROL_2 register.
	*val = control_3.selftest;

	return 0;
}

int32_t WEAK qmc6309_hl_soft_reset(const qmc_context_t* context) {
	// perform the soft reset.
	FAIL_FAST(qmc6309_ll_control_2_soft_rst_set(context, PROPERTY_ENABLE));
	FAIL_FAST(qmc6309_ll_control_2_soft_rst_set(context, PROPERTY_DISABLE));

	return 0;
}

int32_t WEAK qmc6309_hl_setup_typical(const qmc_context_t* context, const qmc6309_mode_t val) {
	// Typical setup.
	const qmc6309_hl_setup_t setup = {
		.mode			= val,
		.set_reset_mode	= SET_RESET_ON,
		.rng			= RNG_32G,
		.odr			= ODR_200HZ,
		.osr1			= OSR1_8,
		.osr2			= OSR2_8
	};

	// Set up the device.
	return qmc6309_hl_setup(context, setup);
}

int32_t WEAK qmc6309_hl_setup(const qmc_context_t* context, const qmc6309_hl_setup_t val) {
	// Set up the CONTROL_1 register value.
	const qmc6309_raw_control_1_t control_1 = {
		.mode		= val.mode,
		.reserved	= PROPERTY_DISABLE,
		.osr1		= val.osr1,
		.osr2		= val.osr2,
	};

	// Set uup the CONTROL_2 register value.
	const qmc6309_raw_control_2_t control_2 = {
		.set_reset_mode	= val.set_reset_mode,
		.rng			= val.rng,
		.odr			= val.odr,
		.soft_rst		= PROPERTY_DISABLE
	};

	// Write to control registers.
	FAIL_FAST(qmc6309_raw_control_1_set(context, control_1));
	FAIL_FAST(qmc6309_raw_control_2_set(context, control_2));

	return 0;
}

int32_t WEAK qmc6309_hl_mode_switch(const qmc_context_t* context, const qmc6309_mode_t val) {
	// Switch to suspend mode first before switching to other modes.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, SUSPEND));

	// Abort if we are already in suspend mode.
	if (val == SUSPEND) {
		return 0;
	}

	// Switch to the actual mode we want.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, val));

	return 0;
}

int32_t WEAK qmc6309_hl_selftest(const qmc_context_t* context, uint8_t* val) {
	// Cannot proceed without the delay function.
	if (context->delay_milliseconds == NULL) {
		return -1;
	}

	// Reserve space for the read.
	qmc6309_mode_t mode;

	// Record the original device mode.
	FAIL_FAST(qmc6309_ll_control_1_mode_get(context, &mode));

	// Switch to continuous mode
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, SUSPEND));
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, CONTINUOUS));

	// Wait 20 milliseconds until measurement ends.
	context->delay_milliseconds(20U);

	// Set self-test enable.
	FAIL_FAST(qmc6309_ll_control_3_selftest_set(context, PROPERTY_ENABLE));

	// Wait 150 milliseconds until measurement ends.
	context->delay_milliseconds(150U);

	uint8_t ready = 0U;

	do {
		// Check if the self-test data is ready to read.
		FAIL_FAST(qmc6309_ll_status_1_st_rdy_get(context, &ready));

		// Wait 1 millisecond until next self-test ready check.
		context->delay_milliseconds(1U);
	} while (!ready);

	// Reserve space for the read.
	qmc6309_raw_selftest_out_t selftest_out = {0U};

	// Get the result of the self-test.
	FAIL_FAST(qmc6309_raw_selftest_get(context, &selftest_out));

	// Restore the original device mode after the self-test.
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, SUSPEND));
	FAIL_FAST(qmc6309_ll_control_1_mode_set(context, mode));

	// Check the result of the self-test.
	if (	selftest_out.selftest_out_x >= -50
		&&	selftest_out.selftest_out_x <= -1
		&&	selftest_out.selftest_out_y >= -50
		&&	selftest_out.selftest_out_y <= -1
		&&	selftest_out.selftest_out_z >= -50
		&&	selftest_out.selftest_out_z <= -1
	) {
		*val = PROPERTY_DISABLE;
	} else {
		*val = PROPERTY_ENABLE;
	}

	return 0;
}

int32_t WEAK qmc6309_hl_mag_get(
	const	qmc_context_t*		context,
	const	qmc6309_rng_t		rng,
			qmc6309_hl_out_t*	val
) {
	// Reserve space for the read.
	qmc6309_raw_status_1_t status_1 = {0U};

	// Check if the data output is ready to read and the data overflow status.
	FAIL_FAST(qmc6309_raw_status_1_get(context, &status_1));

	// Return the data ready and overflow status.
	val->output_ready		= status_1.drdy_bit;
	val->output_overflow	= status_1.ovfl_bit;

	// We cannot proceed if the data is not ready.
	if (!status_1.drdy_bit) {
		return 0;
	}

	// Reserve space for the read.
	qmc6309_ll_out_t out = {0U};

	// Select the correct gauss_per_lsb from the look-up table.
	const float_t gauss_per_lsb = qmc6309_g_per_lsb[rng];

	// Read magnetometer data output from registers.
	FAIL_FAST(qmc6309_ll_mag_get(context, &out));

	// Convert the LSBs into Gauss and return.
	val->gauss_x = ((float_t) out.out_x) * gauss_per_lsb;
	val->gauss_y = ((float_t) out.out_y) * gauss_per_lsb;
	val->gauss_z = ((float_t) out.out_z) * gauss_per_lsb;

	return 0;
}