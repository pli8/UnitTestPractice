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

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, single_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, capital_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("A");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, double_digit_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("12");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, all_capital_letters_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ASSERT_EQ(26, actual);
}