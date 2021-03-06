#include <map>

#include <gtest/gtest.h>

#include "uinteger_t.hh"

static const std::map <uint32_t, std::string> tests = {
	std::make_pair(2,  "10000100000101011000010101101100"),
	std::make_pair(3,  "12201102210121112101"),
	std::make_pair(4,  "2010011120111230"),
	std::make_pair(5,  "14014244043144"),
	std::make_pair(6,  "1003520344444"),
	std::make_pair(7,  "105625466632"),
	std::make_pair(8,  "20405302554"),
	std::make_pair(9,  "5642717471"),
	std::make_pair(10, "2216002924"),
	std::make_pair(11, "a3796a883"),
	std::make_pair(12, "51a175124"),
	std::make_pair(13, "294145645"),
	std::make_pair(14, "170445352"),
	std::make_pair(15, "ce82d6d4"),
	std::make_pair(16, "8415856c"),
	// std::make_pair(256, "uinteger_t"),
};

TEST(Function, str) {
	const uinteger_t original(2216002924);

	// test std::to_string()
	EXPECT_EQ(std::to_string(original), "2216002924");

	// make sure all of the test strings create the ASCII version of the string
	for (std::pair <uint32_t const, std::string>  t : tests) {
		EXPECT_EQ(original.str(t.first), t.second);
	}
}

TEST(External, ostream) {
	const uinteger_t value(0xfedcba9876543210ULL);

	// write out octal uinteger_t
	std::stringstream oct; oct << std::oct << value;
	EXPECT_EQ(oct.str(), "1773345651416625031020");

	// write out decimal uinteger_t
	std::stringstream dec; dec << std::dec << value;
	EXPECT_EQ(dec.str(), "18364758544493064720");

	// write out hexadecimal uinteger_t
	std::stringstream hex; hex << std::hex << value;
	EXPECT_EQ(hex.str(), "fedcba9876543210");

	// zero
	std::stringstream zero; zero << uinteger_t(0);
	EXPECT_EQ(zero.str(), "0");
}
