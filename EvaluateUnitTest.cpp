#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Evaluate/Evaluate.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EvaluateUnitTest
{
	TEST_CLASS(TokenizeUnitTest)
	{
		int result = 0;
	public:
		TEST_METHOD(Test_Empty_Expression_Returns_False)
		{
			Assert::IsFalse(evaluate("", result));
		}

		TEST_METHOD(Test_All_WhiteSpace_Expression_Returns_False)
		{
			Assert::IsFalse(evaluate("    ", result));
		}

		TEST_METHOD(Test_Single_Digit_Expression_Returns_True_And_That_Digit)
		{
			Assert::IsTrue(evaluate("1", result));
			Assert::IsTrue(result == 1);
		}

		TEST_METHOD(Test_Simple_Expression_Returns_True_And_Correct_Answer)
		{
			Assert::IsTrue(evaluate("1+2", result));
			Assert::IsTrue(result == 3);
		}

		TEST_METHOD(Test_Expression_Including_All_Operators_Returns_True_And_Correct_Answer)
		{
			Assert::IsTrue(evaluate("1+2*3-1/4", result));
			Assert::IsTrue(result == 2);
		}

		TEST_METHOD(Test_Division_By_Zero_Is_Trapped)
		{
			Assert::IsFalse(evaluate("1/0", result));
		}

		TEST_METHOD(Test_Expression_Including_All_Operators_And_Spaces_Returns_True_And_Correct_Answer)
		{
			Assert::IsTrue(evaluate(" 1 + 2 *    3 - 1 /   4 ", result));
			Assert::IsTrue(result == 2);
		}

		TEST_METHOD(Test_Expression_Starting_With_Operator_Returns_False)
		{
			Assert::IsFalse(evaluate("+2*3-1/4", result));
		}

		TEST_METHOD(Test_Expression_Ending_With_Operator_Returns_False)
		{
			Assert::IsFalse(evaluate("1+2*3-1/", result));
		}

		TEST_METHOD(Test_An_Invalid_Character_Stopll_WhiteSpace_Expression_Returns_False)
		{
			Assert::IsFalse(evaluate("1+2*3#", result));
		}

		TEST_METHOD(Test_An_Expression_Consisting_Of_Single_Number_Inside_A_Braceket_Returns_True)
		{
			Assert::IsTrue(evaluate("(1)", result));
		}

		TEST_METHOD(Test_An_Simple_Expression_Consisting_Of_Braceket_Returns_True)
		{
			Assert::IsTrue(evaluate("(1 + 2)", result));
			Assert::IsTrue(result == 3);
		}

		TEST_METHOD(Test_An_Expression_Consisting_Of_Number_Opertor_Braceket_Returns_True)
		{
			Assert::IsTrue(evaluate("3  * (1 + 2)", result));
			Assert::IsTrue(result == 9);
		}

		TEST_METHOD(Test_An_Expression_Consisting_Of_Brackets_Returns_True)
		{
			Assert::IsTrue(evaluate("(1 + 4)  * (1 + 2)", result));
			Assert::IsTrue(result == 15);
		}

		TEST_METHOD(Test_An_Bracket_Expression_Consisting_Of_Brackets_Returns_True)
		{
			Assert::IsTrue(evaluate("((1 + 4)  * (1 + 2)) + 6", result));
			Assert::IsTrue(result == 21);
		}

		TEST_METHOD(Test_An_Bracket_Expression_Consisting_Of_Brackets_Only_Returns_True)
		{
			Assert::IsTrue(evaluate("((1 + 4)  * (1 + 2))", result));
			Assert::IsTrue(result == 15);

			Assert::IsTrue(evaluate("4 + (12*(1 * 2))", result));
			Assert::IsTrue(result == 28);
		}



		TEST_METHOD(Test_Sony_Evaluate_Example_One)
		{
			Assert::IsTrue(evaluate("1 + 3 * 4", result));
			Assert::IsTrue(result == 16);
		}

		TEST_METHOD(Test_Sony_Evaluate_Example_Two)
		{
			Assert::IsTrue(evaluate("1 + 3", result));
			Assert::IsTrue(result == 4);
		}

		TEST_METHOD(Test_Sony_Evaluate_Example_Three)
		{
			Assert::IsTrue(evaluate("(1 + 3) * 2", result));
			Assert::IsTrue(result == 8);
		}

		TEST_METHOD(Test_Sony_Evaluate_Example_Four)
		{
			Assert::IsTrue(evaluate("(4/2) + 6", result));
			Assert::IsTrue(result == 8);
		}

		TEST_METHOD(Test_Sony_Evaluate_Example_Five)
		{
			Assert::IsTrue(evaluate("4 + (12/(1 * 2))", result));
			Assert::IsTrue(result == 10);
		} 

		TEST_METHOD(Test_Sony_Evaluate_Example_Six)
		{
			Assert::IsFalse(evaluate("(1 + (12 *2)", result));
		}

		TEST_METHOD(Test_Final_Complex_Expression)
		{
			Assert::IsTrue(evaluate("(((100 + 2 + ((255+45)-(1+1)+(3*4))))-406) + 36", result));
			Assert::IsTrue(result == 42);
		}

		TEST_METHOD(Test_Final_Invalid_Complex_SMissing_Opening_Bracket_Expression)
		{
			Assert::IsFalse(evaluate("((100 + 2 + ((255+45)-(1+1)+(3*4))))-406) + 36", result));
		}



		TEST_METHOD(Test_Double_Operator_Returns_False)
		{
			Assert::IsFalse(evaluate("1**2", result));
		}

	};
}
