#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../task-3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace task3test
{
	TEST_CLASS(task3test)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int m = 0, n = 0;
			vector<vector<int>> matr(m, vector<int>(n));
			vector<int> vec = { };
			vector<vector<int>> result = { };

			vtom(matr, vec, m, n);

			Assert::IsTrue(matr == result);
		}

		TEST_METHOD(TestMethod2)
		{
			const int m = 0, n = 0;
			vector<vector<int>> matr = { };
			vector<int> vec(m*n);
			vector<int> result = { };

			mtov(matr, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod3)
		{
			const int m = 1, n = 1;
			vector<vector<int>> matr(m, vector<int>(n));
			vector<int> vec = { 1 };
			vector<vector<int>> result = { { 1 } };

			vtom(matr, vec, m, n);

			Assert::IsTrue(matr == result);
		}
		
		TEST_METHOD(TestMethod4)
		{
			const int m = 1, n = 1;
			vector<vector<int>> matr = { { 1 } };
			vector<int> vec(m*n);
			vector<int> result = { 1 };

			mtov(matr, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod5)
		{
			const int m = 3, n = 3;
			vector<vector<int>> matr(m, vector<int>(n));
			vector<int> vec = { 1, 1, 1, 2, 2, 2, 3, 3, 3 };
			vector<vector<int>> result = { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 } };

			vtom(matr, vec, m, n);

			Assert::IsTrue(matr == result);
		}

		TEST_METHOD(TestMethod6)
		{
			const int m = 3, n = 3;
			vector<vector<int>> matr = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
			vector<int> vec(m*n);
			vector<int> result = { 1, 1, 1, 2, 2, 2, 3, 3, 3 };

			mtov(matr, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod7)
		{
			const int m = 1, n = 3;
			vector<vector<int>> matr(m, vector<int>(n));
			vector<int> vec = { 1, 1, 1 };
			vector<vector<int>> result = { { 1, 1, 1 } };

			vtom(matr, vec, m, n);

			Assert::IsTrue(matr == result);
		}

		TEST_METHOD(TestMethod8)
		{
			const int m = 1, n = 3;
			vector<vector<int>> matr = { { 1, 1, 1 } };
			vector<int> vec(m * n);
			vector<int> result = { 1, 1, 1 };

			mtov(matr, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod9)
		{
			const int m = 3, n = 1;
			vector<vector<int>> matrix(m, vector<int>(n));
			vector<int> vec = { 1, 1, 1 };
			vector<vector<int>> result = { { 1 }, { 1 }, { 1 } };

			vtom(matrix, vec, m, n);

			Assert::IsTrue(matrix == result);
		}

		TEST_METHOD(TestMethod10)
		{
			const int m = 3, n = 1;
			vector<vector<int>> matr = { { 1 }, { 1 }, { 1 } };
			vector<int> vec(m * n);
			vector<int> result = { 1, 1, 1 };

			mtov(matr, vec, m, n);

			Assert::IsTrue(vec == result);
		}

	};
}
