/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Tests for count_leading_characters function
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string_count)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, repeated_characters_at_beginning)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAABC");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, all_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZ");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, no_repeated_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABCDE");
	ASSERT_EQ(1, actual);
}

// Tests for has_mixed_case function
// Test with an empty string
TEST(PasswordTest, empty_string_has_no_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

// Test with all lowercase letters
TEST(PasswordTest, all_lowercase_has_no_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdefg");
	ASSERT_FALSE(actual);
}

// Test with all uppercase letters
TEST(PasswordTest, all_uppercase_has_no_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEFG");
	ASSERT_FALSE(actual);
}

// Test with mixed case letters
TEST(PasswordTest, mixed_case_returns_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aBcDeFg");
	ASSERT_TRUE(actual);
}

// Test with mixed case and numbers/symbols
TEST(PasswordTest, mixed_case_with_numbers_and_symbols)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aBc123!@#");
	ASSERT_TRUE(actual);
}

// Test with uppercase at beginning and lowercase at end
TEST(PasswordTest, uppercase_at_beginning_lowercase_at_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Abcdefg");
	ASSERT_TRUE(actual);
}

// Test with lowercase at beginning and uppercase at end
TEST(PasswordTest, lowercase_at_beginning_uppercase_at_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdefG");
	ASSERT_TRUE(actual);
}

// Test with only non-alphabetic characters
TEST(PasswordTest, only_non_alphabetic_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123!@#");
	ASSERT_FALSE(actual);
}