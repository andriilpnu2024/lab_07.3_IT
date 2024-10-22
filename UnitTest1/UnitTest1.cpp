#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-7.3 IT/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 2;
			int n = 2;
			int** a = new int* [k];
			rowmem(a, k, n);
			a[0][0] = 0;
			a[0][1] = 0;
			a[1][0] = 6;
			a[1][1] = 5;
			firstrowpos(a, k, n);
			Assert::AreEqual(firstrowpos(a, k, n) , 1);
		}
	};
}
