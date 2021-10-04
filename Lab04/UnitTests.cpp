#include "Recursion.h"
#include <gtest/gtest.h>

TEST(palidrome, recusion1)
		{

			std::string teststr = "HILLIH";

			palindromeRecursion Calculator;
			ASSERT_TRUE(Calculator.palidromeCalculator(teststr));
		}
		TEST(palidrome, recusion2)
		{

			std::string teststr = "bubitltabub";

			palindromeRecursion Calculator;
			ASSERT_FALSE(Calculator.palidromeCalculator(teststr));
		}
		TEST(palidrome, recursion3)
		{
			std::string teststr = "";

			palindromeRecursion Calculator;
			ASSERT_FALSE(Calculator.palidromeCalculator(teststr));
		}
		TEST(palidrome, recusion4)
		{
			std::string teststr = "!TeStitSeT!";

			palindromeRecursion Calculator;
			ASSERT_TRUE(Calculator.palidromeCalculator(teststr));
		}

		TEST(palidrome, stack1)
		{
			std::string teststr = "HILLIH";

			palindromeStack Calculator;
			ASSERT_TRUE(Calculator.palidromeCalculator(teststr));

		}
		TEST(palidrome, stack2)
		{
			std::string teststr = "bubitltabub";

			palindromeStack Calculator;
			ASSERT_FALSE(Calculator.palidromeCalculator(teststr));

		}
		TEST(palidrome, stack3)
		{
			std::string teststr = "";

			palindromeStack Calculator;
			ASSERT_FALSE(Calculator.palidromeCalculator(teststr));

		}
		TEST(palidrome, stack4)
		{
			std::string teststr = "!TeStitSeT!";

			palindromeStack Calculator;
			ASSERT_TRUE(Calculator.palidromeCalculator(teststr));
		}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}