#include <gtest/gtest.h>

#include "uinteger_t.hh"

TEST(Comparison, greater_than_or_equals) {
	const uinteger_t big  (0xffffffffffffffffULL, 0xffffffffffffffffULL);
	const uinteger_t small(0x0000000000000000ULL, 0x0000000000000000ULL);

	EXPECT_EQ(small >= small,  true);
	EXPECT_EQ(small >= big,   false);

	EXPECT_EQ(big >= small,    true);
	EXPECT_EQ(big >= big,      true);
}

#define unsigned_compare_gte(Z)                                         \
do                                                                      \
{                                                                       \
	static_assert(std::is_signed <Z>::value, "Type must be signed");    \
																		\
	const T small = std::numeric_limits <Z>::min();                     \
	const T big   = std::numeric_limits <Z>::max();                     \
																		\
	const uinteger_t int_small(small);                                      \
	const uinteger_t int_big(big);                                          \
}                                                                       \
while (0)

#define signed_compare_gte(Z)                                           \
do                                                                      \
{                                                                       \
	static_assert(std::is_signed <Z>::value, "Type must be signed");    \
																		\
	const T small =  1;                                                 \
	const T big = std::numeric_limits <Z>::max();                       \
																		\
	const uinteger_t int_small(small);                                      \
	const uinteger_t int_big(big);                                          \
}                                                                       \
while (0)

// TEST(External, greater_than_or_equals) {
	// unsigned_compare_gte(bool);
	// unsigned_compare_gte(uint8_t);
	// unsigned_compare_gte(uint16_t);
	// unsigned_compare_gte(uint32_t);
	// unsigned_compare_gte(uint64_t);
	// signed_compare_gte(int8_t);
	// signed_compare_gte(int16_t);
	// signed_compare_gte(int32_t);
	// signed_compare_gte(int64_t);
// }
