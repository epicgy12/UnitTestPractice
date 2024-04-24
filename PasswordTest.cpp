/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)  //TEST ( Name of test class, Descriptive name of this test case
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);  //Result of this function call should be exactly this
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("yy"));
}

TEST(PasswordTest, three_letter_password)
{
	Password my_password;
	ASSERT_EQ(3, my_password.count_leading_characters("xxx"));
}

TEST(PasswordTest, four_letter_password)
{
	Password my_password;
	ASSERT_EQ(4, my_password.count_leading_characters("wwww"));
}

TEST(PasswordTest, five_letter_password)
{
	Password my_password;
	ASSERT_EQ(5, my_password.count_leading_characters("vvvvv"));
}

TEST(PasswordTest, five_letter_mixed_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("abced"));
}

TEST(PasswordTest, five_letter_tailing_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("baaaa"));
}

TEST(PasswordTest, long_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("dkshblaihsdblfibhadsdljsdbhgilyubfviulhvjkdsnzul;iudhafjasbdilfuhds.fkjnsd.iujbas.diufbliadsubsdkjfb.asdufbilasdufb.,sdakjf.nasdkjufbiusaldbfsaldhbfuyadsbuflaysdh,bfasdkjbfiuladsb;uibgasdliufbyulasdhbfalsdkjfbilsaudbilfuasdhb,fjhb.fkuasbdlifuabsd.ubsdfasydlfiyasdguifa;shduifhsad.jkfh;asodiufh;asuidbf.sdubf"));
}

TEST(PasswordTest, long_char_password)
{
	Password my_password;
	ASSERT_EQ(300, my_password.count_leading_characters("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
}

TEST(PasswordTest, empty_string_password)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, has_mixed_case_T)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Password"));
}

TEST(PasswordTest, has_mixed_case_F)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("password"));
}

TEST(PasswordTest, mixed_empty_string)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case(""));
}


TEST(PasswordTest, set){
	Password my_password;
	ASSERT_EQ(true, my_password.authenticate("ChicoCA-95929"));
}

TEST(PasswordTest, defaultCheck){
	Password my_password;
	ASSERT_EQ(true, my_password.authenticate("ChicoCA-95929"));
}

TEST(PasswordTest, authenticateF){
	Password my_password;
	my_password.set("ChicoCA-95929");
	ASSERT_EQ(false, my_password.authenticate("urMomdotCom"));
}
