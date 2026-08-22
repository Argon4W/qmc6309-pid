#ifndef QMC6309_REG_H
#define QMC6309_REG_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>
#include <stddef.h>
#include <math.h>

/**
 * @brief Ensure register layout structs to be tightly-packed.
 */
#ifndef PACKED
#define PACKED __attribute__((__packed__))
#endif

/**
 * @brief Endianness definitions.
 */
#ifndef DEVICE_BYTE_ORDER
	#ifndef __BYTE_ORDER__
		#define DEVICE_LITTLE_ENDIAN	1234
		#define DEVICE_BIG_ENDIAN		4321

		// If the byte order is not defined, choose the endianness by uncommenting the following defines.
		#define DEVICE_BYTE_ORDER DEVICE_LITTLE_ENDIAN
		// #define DEVICE_BYTE_ORDER DEVICE_LITTLE_ENDIAN
	#else
		#define DEVICE_LITTLE_ENDIAN	__ORDER_LITTLE_ENDIAN__
		#define DEVICE_BIG_ENDIAN		__ORDER_BIG_ENDIAN__
		#define DEVICE_BYTE_ORDER		__BYTE_ORDER__
	#endif // __BYTE_ORDER__
#endif // DEVICE_BYTE_ORDER

#ifndef QMC_SHARED_TYPES
#define QMC_SHARED_TYPES

#define PROPERTY_DISABLE	(0U)
#define PROPERTY_ENABLE		(1U)

/**
 * @brief	Platform independent function type of writing to a generic register of the device. ("0" = no error)
 * @retval	status of implementation function interfaces, ("0" = no error)
 */
typedef int32_t (*qmc_write_register_function_ptr)(
	void*			user_handle,		/*!< The user-defined custom handle needed by the implementation, as pointer. */
	uint8_t			register_address,	/*!<  The first register address to be written. */
	const uint8_t*	buffer,				/*!<  The data to be written to the registers, as pointer. */
	uint16_t		length				/*!<  The count of registers we want to write to. */
);

/**
 * @brief	Platform independent function type of reading from a generic register of the device. ("0" = no error)
 * @retval	status of implementation function interfaces, ("0" = no error)
 */
typedef int32_t (*qmc_read_register_function_ptr)(
	void*		user_handle,		/*!< The user-defined custom handle needed by the implementation, as pointer. */
	uint8_t		register_address,	/*!< The first register address to be read. */
	uint8_t*	buffer,				/*!< The buffer to hold the data read from the registers, as pointer. */
	uint16_t	length				/*!< The count of registers we want to read from. */
);

/**
 * @brief Platform independent function type of delaying milliseconds.
 */
typedef void (*qmc_delay_milliseconds_function_ptr)(uint32_t milliseconds);

/**
 * @brief Platform independent driver function interface context.
 */
typedef struct {
	qmc_write_register_function_ptr		write_register;		/*!< Implementation function of writing to registers. */
	qmc_read_register_function_ptr		read_register;		/*!< Implementation function of reading from registers. */
	qmc_delay_milliseconds_function_ptr	delay_milliseconds;	/*!< Implementation function of delaying milliseconds. */
	void*								user_handle;		/*!< The user-defined custom handle needed by the implementation. */
} qmc_context_t;

#endif // QMC_SHARED_TYPES

/**
 * @brief Chip properties.
 */
/** I2C Device Address in 8-bit format. */
#define QMC6309_I2C_ADDRESS 0x7CU

/**
 * @brief Chip identity register related.
 */
/** Chip ID Register. */
#define QMC6309_CHIP_ID		0x00U
/** Chip ID reference value. */
#define QMC6309_CHIP_ID_REF	0x90U

/**
 * @brief	Data output registers.
 *			Registers 0x01U ~ 0x06U store the measurement data from each axis magnetic sensor in each working mode.
 */
/** Data Output X LSB Register XOUT[7:0]. */
#define QMC6309_OUT_X_L 0x01U
/** Data Output X MSB Register XOUT[15:8]. */
#define QMC6309_OUT_X_H 0x02U
/** Data Output Y LSB Register YOUT[7:0]. */
#define QMC6309_OUT_Y_L 0x03U
/** Data Output Y MSB Register YOUT[15:8]. */
#define QMC6309_OUT_Y_H 0x04U
/** Data Output Z LSB Register ZOUT[7:0]. */
#define QMC6309_OUT_Z_L 0x05U
/** Data Output Z MSB Register ZOUT[15:8]. */
#define QMC6309_OUT_Z_H 0x06U

/**
 * @brief Full output (3-axis) raw data struct.
 */
typedef struct {
	int16_t out_x; /*!< Data output X registers XOUT[15:0]. */
	int16_t out_y; /*!< Data output Y registers YOUT[15:0]. */
	int16_t out_z; /*!< Data output Z registers ZOUT[15:0]. */
} qmc6309_out_t;

/**
 * @brief Status register 1.
 */
#define QMC6309_STATUS_1					0x09U
/** set when all three-axis data is ready, reset to "0" by reading the status register. ("0" = no new data; "1" = new data ready) */
#define QMC6309_STATUS_1_DRDY_BIT			0
/** set when either axis code output exceeds the range of [-32000, 32000] LSB, reset to "0" by reading the status register. ("0" = no data overflow occurs; "1" = data overflow occurs) */
#define QMC6309_STATUS_1_OVFL_BIT			1
/** Denotes the status of built-in selftest measurement. ("0" = selftest is not done; "1" = selftest is done, data is ready for reading) */
#define QMC6309_STATUS_1_ST_RDY_BIT			2
/** Denotes the status of built-in non-volatile memory. ("0" = NVM not ready for access; "1" = NVM iss ready for access) */
#define QMC6309_STATUS_1_NVM_RDY_BIT		3
/** Denotes the status of data loading from built-in non-volatile memory. ("0" = data loading from NVM not finished; "1" = data loading from NVM is finished) */
#define QMC6309_STATUS_1_NVM_LOAD_DONE_BIT	4

/**
 * @brief Status register 1 data layout struct.
 */
typedef struct {
	#if DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
		uint8_t drdy_bit			: 1; /*!< QMC6309_STATUS_1_DRDY_BIT */
		uint8_t ovfl_bit			: 1; /*!< QMC6309_STATUS_1_OVFL_BIT */
		uint8_t st_rdy_bit			: 1; /*!< QMC6309_STATUS_1_ST_RDY_BIT */
		uint8_t nvm_rdy_bit			: 1; /*!< QMC6309_STATUS_1_NVM_RDY_BIT */
		uint8_t nvm_load_done_bit	: 1; /*!< QMC6309_STATUS_1_NVM_LOAD_DONE_BIT */
		uint8_t reserved			: 3; /*!< Reserved. */
	#else
		uint8_t reserved			: 3; /*!< Reserved. */
		uint8_t nvm_load_done_bit	: 1; /*!< QMC6309_STATUS_1_NVM_LOAD_DONE_BIT */
		uint8_t nvm_rdy_bit			: 1; /*!< QMC6309_STATUS_1_NVM_RDY_BIT */
		uint8_t st_rdy_bit			: 1; /*!< QMC6309_STATUS_1_ST_RDY_BIT */
		uint8_t ovfl_bit			: 1; /*!< QMC6309_STATUS_1_OVFL_BIT */
		uint8_t drdy_bit			: 1; /*!< QMC6309_STATUS_1_DRDY_BIT */
	#endif // DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
} PACKED qmc6309_status_1_t;

/**
 * @brief Control register 1.
 */
#define QMC6309_CONTROL_1					0x0AU
/** Mode control[1:0]. The four modes are Suspend Mode (0b00U), Normal Mode (0b01U), Single Mode (0b10U), Continuous Mode (0b11U). Default mode after Power-On-Reset is Suspend Mode. Suspend Mode should be added in the middle of mode shifting. */
#define QMC6309_CONTROL_1_MODE_START_BIT	0
/** Over sample ratio[4:3]. Control bandwidth of the internal digital filter. Larger value leads to less noise but higher power consumption. For ratio can be selected: 8 (0b00), 4 (0b01), 2(0b10), 1 (0b11). */
#define QMC6309_CONTROL_1_OSR1_START_BIT	3
/** Low pass filter[7:5]. For better noise performance. There are totally 5 levels selectable: 1 (0b000), 2 (0b001), 4 (0b010), 8 (0b011), 16 (0b100). */
#define QMC6309_CONTROL_1_OSR2_START_BIT	5

/**
 * @brief Modes of mode control[1:0] in control register 1.
 */
typedef enum {
	SUSPEND		= 0b00U, /*!< Suspend Mode. */
	NORMAL		= 0b01U, /*!< Normal Mode. */
	SINGLE		= 0b10U, /*!< Single Mode. */
	CONTINUOUS	= 0b11U /*!< Continuous Mode. */
} qmc6309_mode_t;

/**
 * @brief Over sample ratio[4:3] selections in control register 1.
 */
typedef enum {
	OSR1_8 = 0b00U, /*!< Over sample ratio 8. */
	OSR1_4 = 0b01U, /*!< Over sample ratio 4. */
	OSR1_2 = 0b10U, /*!< Over sample ratio 2. */
	OSR1_1 = 0b11U /*!< Over sample ratio 1. */
} qmc6309_osr1_t;

/**
 * @brief Low pass filter[7:5] depth selections in control register 1.
 */
typedef enum {
	OSR2_1	= 0b000U, /*!< Low pass filter depth 1. */
	OSR2_2	= 0b001U, /*!< Low pass filter depth 2. */
	OSR2_4	= 0b010U, /*!< Low pass filter depth 4. */
	OSR2_8	= 0b011U, /*!< Low pass filter depth 8. */
	OSR2_16	= 0b100U /*!< Low pass filter depth 16. */
} qmc6309_osr2_t;

/**
 * @brief Control register 1 data layout struct.
 */
typedef struct {
	#if DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
		uint8_t mode		: 2; /*!< QMC6309_CONTROL_1_MODE_START_BIT, qmc6309_mode_t. */
		uint8_t reserved	: 1; /*!< Reserved. */
		uint8_t osr1		: 2; /*!< QMC6309_CONTROL_1_OSR1_START_BIT, qmc6309_osr1_t. */
		uint8_t osr2		: 3; /*!< QMC6309_CONTROL_1_OSR2_START_BIT, qmc6309_osr2_t. */
	#else
		uint8_t osr2		: 3; /*!< QMC6309_CONTROL_1_OSR2_START_BIT qmc6309_osr2_t. */
		uint8_t osr1		: 2; /*!< QMC6309_CONTROL_1_OSR1_START_BIT qmc6309_osr1_t. */
		uint8_t reserved	: 1; /*!< Reserved. */
		uint8_t mode		: 2; /*!< QMC6309_CONTROL_1_MODE_START_BIT, qmc6309_mode_t. */
	#endif // DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
} PACKED qmc6309_control_1_t;

/**
 * @brief Control register 2.
 */
#define QMC6309_CONTROL_2							0x0BU
/** Sst/Reset mode can be control by register SET/RESET MODE[1:0]. There are 3 modes for selection: SET AND RESET ON (0b00), SET ONLY ON (0b01), SET AND RESET OFF (0b10). */
#define QMC6309_CONTROL_2_SET_RESET_MODE_START_BIT	0
/** Field ranges of the magnetic sensor can be selected through the register RNG[3:2]. The lowest range has the highest sensitivity, therefore, higher resolution. */
#define QMC6309_CONTROL_2_RNG_START_BIT				2
/** The output data rate is controlled by ODR registers[6:4]. Four data update frequencies can be selected: 10Hz (0b001), 50Hz (0b010), 100Hz (0b011), 200Hz (0b100). */
#define QMC6309_CONTROL_2_ODR_START_BIT				4
/** Soft reset can be done by setting the register SOFT_RST[7:7] high. Soft resset can be invoked at any time of any mode. After setting high, the SOFT_RST bit will not be auto-cleared. */
#define QMC6309_CONTROL_2_SOFT_RST_BIT				7

/**
 * @brief Set and reset mode control[1:0] in control register 2.
 */
typedef enum {
	SET_RESET_ON	= 0b00 /*!< Set and reset on. */,
	SET_ONLY_ON		= 0b01 /*!< Set only on. */,
	SET_RESET_OFF	= 0b10 /*!< Set and reset off. */
} qmc6309_set_reset_mode_t;

/**
 * @brief Full scale range[3:2] selections in control register 2.
 */
typedef enum {
	RNG_32G	= 0b00,	/*!< 32 Gauss. */
	RNG_16G	= 0b01,	/*!< 16 Gauss. */
	RNG_8G	= 0b10	/*!< 8 Gauss. */
} qmc6309_rng_t;

/**
 * @brief Output data rate[6:4] selections in control register 2.
 */
typedef enum {
	ODR_1HZ		= 0b000,	/*!< 1Hz (Suspicious). */
	ODR_10HZ	= 0b001,	/*!< 10Hz. */
	ODR_50HZ	= 0b010,	/*!< 50Hz. */
	ODR_100HZ	= 0b011,	/*!< 100Hz. */
	ODR_200HZ	= 0b100		/*!< 200Hz. */
} qmc6309_odr_t;

/**
 * @brief Control register 2 data layout struct.
 */
typedef struct {
	#if DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
		uint8_t set_reset_mode	: 2; /*!< QMC6309_CONTROL_2_SET_RESET_MODE_START_BIT, qmc6309_set_reset_mode_t. */
		uint8_t rng				: 2; /*!< QMC6309_CONTROL_2_RNG_START_BIT, qmc6309_rng_t. */
		uint8_t odr				: 3; /*!< QMC6309_CONTROL_2_ODR_START_BIT, qmc6309_odr_t. */
		uint8_t soft_rst		: 1; /*!< QMC6309_CONTROL_2_SOFT_RST_BIT. */
	#else
		uint8_t soft_rst		: 1; /*!< QMC6309_CONTROL_2_SOFT_RST_BIT. */
		uint8_t odr				: 3; /*!< QMC6309_CONTROL_2_ODR_START_BIT, qmc6309_odr_t. */
		uint8_t rng				: 2; /*!< QMC6309_CONTROL_2_RNG_START_BIT, qmc6309_rng_t. */
		uint8_t set_reset_mode	: 2; /*!< QMC6309_CONTROL_2_SET_RESET_MODE_START_BIT, qmc6309_set_reset_mode_t. */
	#endif // DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
} PACKED qmc6309_control_2_t;

/**
 * @brief Control register 3.
 */
#define QMC6309_CONTROL_3				0x0EU
/** 1 bit reserved for built-in selftest. Only when the chip is under continuous mode, the selftest bit can be set high to enable the chip to enter selftest mode. After the selftest is done this bit will be auto cleared. */
#define QMC6309_CONTROL_3_SELFTEST_BIT	7

/**
 * @brief Self-test data output registers.
 */
/** Data output X self-test register[7:0]. */
#define QMC6309_OUT_SELF_TEST_X 0x13U
/** Data output Y self-test register[7:0]. */
#define QMC6309_OUT_SELF_TEST_Y 0x14U
/** Data output Z self-test register[7:0]. */
#define QMC6309_OUT_SELF_TEST_Z 0x15U

/**
 * @brief Control register 3 data layout struct.
 */
typedef struct {
	#if DEVICE_BYTE_ORDER == DEVICE_LITTLE_ENDIAN
		uint8_t reserved : 7; /*!< Reserved. **/
		uint8_t selftest : 1; /*!< QMC6309_CONTROL_3_SELFTEST_BIT. */
	#else
		uint8_t selftest : 1; /*!< QMC6309_CONTROL_3_SELFTEST_BIT. */
		uint8_t reserved : 7; /*!< Reserved. */
	#endif
} PACKED qmc6309_control_3_t;

/**
 * @brief Make sure driver functions can be overridden by user-defined custom implementations.
 */
#ifndef WEAK
#define WEAK __attribute__((weak))
#endif // WEAK

/**
 * @brief		Fail fast when the return value is indicating an error. ("0" = no error; other value = error)
 * @param val	The expression that needs to be checked.
 */
#define FAIL_FAST(val) do {	\
	int32_t result = (val);	\
	if (result != 0) {		\
		return result;		\
	}						\
} while (0);				\

/**
 * @brief	Read from a generic device register.
 * @param	context				implementation of the platform independent function interfaces, as pointer.
 * @param	register_address	first register address to read.
 * @param	buffer				destination buffer of the buffer read, as pointer.
 * @param	length				number of registers to read.
 * @retval						status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_read_register(
	const qmc_context_t*	context,
	uint8_t					register_address,
	uint8_t*				buffer,
	uint16_t				length
);

/**
 * @brief	Write to a generic device register.
 * @param	context				implementation of the platform independent function interfaces, as pointer.
 * @param	register_address	first register address to write.
 * @param	buffer				source buffer of the buffer write, as pointer.
 * @param	length				number of registers to write.
 * @retval						status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_write_register(
	const qmc_context_t*	context,
	uint8_t					register_address,
	uint8_t*				buffer,
	uint16_t				length
);

/**
 * @brief			Get raw chip ID.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_chip_id_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer LSB data on X-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_x_lsb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer MSB data on X-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_x_msb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer LSB data on Y-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_y_lsb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer MSB data on Y-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_y_msb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer LSB data on Z-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_z_lsb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw magnetometer MSB data on Z-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_mag_z_msb_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw status from status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_status_1_get(const qmc_context_t* context, qmc6309_status_1_t* val);

/**
 * @brief			Overwrite raw configurations into control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Source value for the register write.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_1_set(const qmc_context_t* context, qmc6309_control_1_t val);

/**
 * @brief			Get raw configurations from control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_1_get(const qmc_context_t* context, qmc6309_control_1_t* val);

/**
 * @brief			Overwrite raw configurations into control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Source value for the register write.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_2_set(const qmc_context_t* context, qmc6309_control_2_t val);

/**
 * @brief			Get raw configurations from control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_2_get(const qmc_context_t* context, qmc6309_control_2_t* val);

/**
 * @brief			Overwrite raw configurations into control 3 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Source value for the register write.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_3_set(const qmc_context_t* context, qmc6309_control_3_t val);

/**
 * @brief			Get raw configurations from control 3 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the register read, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_control_3_get(const qmc_context_t* context, qmc6309_control_3_t* val);

/**
 * @brief			Get raw self-test output data on X-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the self-test output data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_selftest_x_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw self-test output data on Y-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the self-test output data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_selftest_y_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get raw self-test output data on Z-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the self-test output data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_raw_selftest_z_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief		Convert magnetometer lsb into gauss. (full-scale range of 8G)
 * @param lsb	Magnetometer raw data when full-scale range is 8G.
 * @retval		Magnetometer value in gauss.
 */
float_t qmc6309_ll_from_rng8_to_gauss(int16_t lsb);

/**
 * @brief		Convert magnetometer lsb into gauss. (full-scale range of 16G)
 * @param lsb	Magnetometer raw data when full-scale range is 16G.
 * @retval		Magnetometer value in gauss.
 */
float_t qmc6309_ll_from_rng16_to_gauss(int16_t lsb);

/**
 * @brief		Convert magnetometer lsb into gauss. (full-scale range of 32G)
 * @param lsb	Magnetometer raw data when full-scale range is 32G.
 * @retval		Magnetometer value in gauss.
 */
float_t qmc6309_ll_from_rng32_to_gauss(int16_t lsb);

/**
 * @brief			Get raw magnetometer data on X-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the magnetometer data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_mag_x_get(const qmc_context_t* context, int16_t* val);

/**
 * @brief			Get raw magnetometer data on Y-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the magnetometer data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_mag_y_get(const qmc_context_t* context, int16_t* val);

/**
 * @brief			Get raw magnetometer data on Z-axis.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the magnetometer data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_mag_z_get(const qmc_context_t* context, int16_t* val);

/**
 * @brief			Get raw magnetometer data.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the magnetometer data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_mag_get(const qmc_context_t* context, qmc6309_out_t* val);

/**
 * @brief			Get the data-ready status from the status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the status, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_status_1_drdy_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get the overflow status from the status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the status, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_status_1_ovfl_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get the self-test-ready status from the status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the status, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_status_1_st_rdy_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get the NVM-ready status from the status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the status, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_status_1_nvm_rdy_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Get the NVM-load-done status from the status 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the status, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_status_1_nvm_load_done_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Set the device mode by the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Mode selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_mode_set(const qmc_context_t* context, qmc6309_mode_t val);

/**
 * @brief			Get the device mode from the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the mode, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_mode_get(const qmc_context_t* context, qmc6309_mode_t* val);

/**
 * @brief			Set the over sample rate by the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Over sample rate selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_osr1_set(const qmc_context_t* context, qmc6309_osr1_t val);

/**
 * @brief			Get the over sample rate from the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the over sample rate selection, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_osr1_get(const qmc_context_t* context, qmc6309_osr1_t* val);

/**
 * @brief			Set the low pass filter depth by the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Low pass filter depth selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_osr2_set(const qmc_context_t* context, qmc6309_osr2_t val);

/**
 * @brief			Get the low pass filter depth from the control 1 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the low pass filter depth selection, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_1_osr2_get(const qmc_context_t* context, qmc6309_osr2_t* val);

/**
 * @brief			Set the set and reset mode by the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Set and reset mode selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_set_reset_mode_set(const qmc_context_t* context, qmc6309_set_reset_mode_t val);

/**
 * @brief			Get the set and reset mode from the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the set and reset mode selection, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_set_reset_mode_get(const qmc_context_t* context, qmc6309_set_reset_mode_t* val);

/**
 * @brief			Set the full scale range by the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Full scale range selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_rng_set(const qmc_context_t* context, qmc6309_rng_t val);

/**
 * @brief			Get the full scale range from the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the full scale range selection, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_rng_get(const qmc_context_t* context, qmc6309_rng_t* val);

/**
 * @brief			Set the output data rate by the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Output data rate selection to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_odr_set(const qmc_context_t* context, qmc6309_odr_t val);

/**
 * @brief			Get the output data rate from the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the output data rate selection, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_odr_get(const qmc_context_t* context, qmc6309_odr_t* val);

/**
 * @brief			Enable/disable the soft reset by the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Soft reset state to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_soft_rst_set(const qmc_context_t* context, uint8_t val);

/**
 * @brief			Get the soft reset state from the control 2 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the soft reset state, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_2_soft_rst_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief			Enable/disable the self-test by the control 3 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Self-test state to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_3_selftest_set(const qmc_context_t* context, uint8_t val);

/**
 * @brief			Get the self-test status from the control 3 register.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the self-test state, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_control_3_selftest_get(const qmc_context_t* context, uint8_t* val);

/**
 * @brief Self-test data output struct.
 */
typedef struct {
	int8_t selftest_out_x : 8; /*!< Data output X of self-test. */
	int8_t selftest_out_y : 8; /*!< Data output Y of self-test. */
	int8_t selftest_out_z : 8; /*!< Data output Z of self-test. */
} PACKED qmc6309_selftest_out_t;

/**
 * @brief			Get raw selftest data.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		Destination buffer for the selftest data, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_ll_selftest_get(const qmc_context_t* context, qmc6309_selftest_out_t* val);

/**
 * @brief			Soft reset.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_soft_reset(const qmc_context_t* context);

/**
 * @brief Device setup sturct.
 */
typedef struct {
	qmc6309_mode_t				mode;			/*!< Device mode. */
	qmc6309_set_reset_mode_t	set_reset_mode;	/*!< Set and reset mode. */
	qmc6309_rng_t				rng;			/*!< Full scale range. */
	qmc6309_odr_t				odr;			/*!< Output data range. */
	qmc6309_osr1_t				osr1;			/*!< Over sample rate. */
	qmc6309_osr2_t				osr2;			/*!< Low pass filter depth */
} qmc6309_setup_t;

/**
 * @brief			Set up device.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		The parameters to set up the device.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_setup(const qmc_context_t* context, qmc6309_setup_t val);

/**
 * @brief			Set up to specified mode followed by the instructions and parameters in the datasheet.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		The device mode to be set.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_setup_typical(const qmc_context_t* context, qmc6309_mode_t val);

/**
 * @brief			Change device mode.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		The device mode to be set to.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_mode_switch(const qmc_context_t* context, qmc6309_mode_t val);

/**
 * @brief			Change device mode to continuous mode.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param val		The buffer to hold the result of the self-test ("0" = not passing the self-test; "1" = working properly).
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_selftest(const qmc_context_t* context, uint8_t* val);

/**
 * @brief Gauss data output struct.
 */
typedef struct {
	uint8_t output_ready;		/*!< The data-ready status of this read. ("0" = data is not ready; "1" = data is ready) */
	uint8_t output_overflow;	/*!< The data-overflow status of this read. ("0" = No data overflow occurred; "1" = Data overflow occurs) */
	float_t output_gauss_x; 	/*!< Data output of X-Axis in Gauss (or undefined if data is not ready). */
	float_t output_gauss_y; 	/*!< Data output of Y-Axis in Gauss (or undefined if data is not ready). */
	float_t output_gauss_z; 	/*!< Data output of Z-Axis in Gauss (or undefined if data is not ready). */
} qmc6309_out_full_t;

/**
 * @brief			Get the data output in gauss.
 * @param context	implementation of the platform independent function interfaces, as pointer.
 * @param rng		The full scale range of the data output.
 * @param val		The buffer to hold the output data.
 * @retval			status of implementation function interfaces, ("0" = no error)
 */
int32_t qmc6309_hl_mag_get(const qmc_context_t* context, qmc6309_rng_t rng, qmc6309_out_full_t* val);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // QMC6309_REG_H