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

// Test 1: count_leading_characters - empty string (covers if branch)
TEST(PasswordTest, count_leading_characters_empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

// Test 2: count_leading_characters - single character (covers while loop not entered)
TEST(PasswordTest, count_leading_characters_single_char)
{
	Password my_password;
	int actual = my_password.count_leading_characters("A");
	ASSERT_EQ(1, actual);
}

// Test 3: count_leading_characters - same characters (covers while loop execution)
TEST(PasswordTest, count_leading_characters_same_chars)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAA");
	ASSERT_EQ(3, actual);
}

// Test 4: count_leading_characters - different characters (covers while condition2 false)
TEST(PasswordTest, count_leading_characters_different_chars)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AB");
	ASSERT_EQ(1, actual);
}

// Test 5: has_mixed_case - only uppercase (covers islower false, isupper true, return false)
TEST(PasswordTest, has_mixed_case_only_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HELLO");
	ASSERT_FALSE(actual);
}

// Test 6: has_mixed_case - only lowercase (covers islower true, isupper false, return false)
TEST(PasswordTest, has_mixed_case_only_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hello");
	ASSERT_FALSE(actual);
}

// Test 7: has_mixed_case - mixed case (covers both true, return true)
TEST(PasswordTest, has_mixed_case_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Hello");
	ASSERT_TRUE(actual);
}

// Test 8: has_mixed_case - no letters (covers both false, return false)
TEST(PasswordTest, has_mixed_case_no_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123!@#");
	ASSERT_FALSE(actual);
}

// Test 9: unique_characters - all same (covers if branch false case)
TEST(PasswordTest, unique_characters_all_same)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("AAAA");
	ASSERT_EQ(1, actual);
}

// Test 10: unique_characters - all different (covers if branch true case)
TEST(PasswordTest, unique_characters_all_different)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("ABCD");
	ASSERT_EQ(4, actual);
}
