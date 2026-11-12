/***********************************************************************
Bachelor of Software Engineering
Media Design School at Strayer
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : test.cpp
Description : Implements unit tests for discrete mathematics functions.
Author : Vincent 
Mail : Vincentantonweber@gmail.com
************************************************************************/

#include "test.h"
#include "discretemaths.h"
#include <iostream>

using namespace std;

// runs one test and updates the test totals
void RunTest(bool _bPassed, const char* _pcTestName, int& _riPassed, int& _riFailed)
{
    if (_bPassed)
    {
        cout << "[PASS] " << _pcTestName << endl;
        ++_riPassed;
    }
    else
    {
        cout << "[FAIL] " << _pcTestName << endl;
        ++_riFailed;
    }
}

// runs all of the rtests.
void RunTests()
{
    int iPassed = 0;
    int iFailed = 0;

    cout << "\n========== DISCRETE MATHS TESTS ==========\n" << endl;

    // math tests to see 
    RunTest(Magnitude(-5.0f) == 5.0f, "Magnitude negative", iPassed, iFailed);
    RunTest(Magnitude(5.0f) == 5.0f, "Magnitude positive", iPassed, iFailed);
    RunTest(Signum(-5.0f) == -1.0f, "Signum negative", iPassed, iFailed);
    RunTest(Signum(0.0f) == 0.0f, "Signum zero", iPassed, iFailed);
    RunTest(Signum(5.0f) == 1.0f, "Signum positive", iPassed, iFailed);
    RunTest(Floor(3.7f) == 3.0f, "Floor positive decimal", iPassed, iFailed);
    RunTest(Floor(-3.7f) == -4.0f, "Floor negative decimal", iPassed, iFailed);
    RunTest(Ceiling(3.2f) == 4.0f, "Ceiling positive decimal", iPassed, iFailed);
    RunTest(Ceiling(-3.2f) == -3.0f, "Ceiling negative decimal", iPassed, iFailed);

    // counts the tests
    RunTest(Factorial(5) == 120, "Factorial of 5", iPassed, iFailed);
    RunTest(Factorial(0) == 1, "Factorial of 0", iPassed, iFailed);
    RunTest(Combination(5, 2) == 10, "Combination of 5 and 2", iPassed, iFailed);
    RunTest(Combination(2, 3) == 0, "Combination invalid values", iPassed, iFailed);
    RunTest(Permutation(5, 2) == 20, "Permutation of 5 and 2", iPassed, iFailed);
    RunTest(Permutation(2, 3) == 0, "Permutation invalid values", iPassed, iFailed);

    // this crreate sets for testing
    Set setA;
    Set setB;
    Set setC;
    Set setResult;

    setA.AddElement(1);
    setA.AddElement(2);
    setA.AddElement(3);

    setB.AddElement(3);
    setB.AddElement(4);

    setC.AddElement(7);
    setC.AddElement(8);

    // set calculation tests
    RunTest(Cardinality(setA) == 3, "Cardinality", iPassed, iFailed);
    RunTest(Power(setA) == 8, "Power set size", iPassed, iFailed);
    RunTest(CartesianProduct(setA, setB) == 6, "Cartesian product", iPassed, iFailed);

    // set comparison tests
    RunTest(Equals(setA, setA), "Equals identical sets", iPassed, iFailed);
    RunTest(Subset(setB, setA) == false, "Subset false", iPassed, iFailed);
    RunTest(Subset(setC, setC), "Subset identical sets", iPassed, iFailed);
    RunTest(Superset(setA, setB) == false, "Superset false", iPassed, iFailed);
    RunTest(Disjoint(setA, setC), "Disjoint sets", iPassed, iFailed);
    RunTest(Disjoint(setA, setB) == false, "Non-disjoint sets", iPassed, iFailed);

    // set operation tests
    Union(setA, setB, setResult);
    RunTest(setResult.ContainsElement(1) &&
        setResult.ContainsElement(2) &&
        setResult.ContainsElement(3) &&
        setResult.ContainsElement(4), "Union", iPassed, iFailed);

    Intersection(setA, setB, setResult);
    RunTest(setResult.ContainsElement(3) &&
        Cardinality(setResult) == 1, "Intersection", iPassed, iFailed);

    SetDifference(setA, setB, setResult);
    RunTest(setResult.ContainsElement(1) &&
        setResult.ContainsElement(2) &&
        Cardinality(setResult) == 2, "Set difference", iPassed, iFailed);

    SymmetricDifference(setA, setB, setResult);
    RunTest(setResult.ContainsElement(1) &&
        setResult.ContainsElement(2) &&
        setResult.ContainsElement(4) &&
        Cardinality(setResult) == 3, "Symmetric difference", iPassed, iFailed);

    Complement(setA, setResult);
    RunTest(!setResult.ContainsElement(1) &&
        setResult.ContainsElement(4) &&
        setResult.ContainsElement(100), "Complement", iPassed, iFailed);

    // Display test results
    cout << "\n========== TEST SUMMARY ==========" << endl;
    cout << "Tests conducted: " << iPassed + iFailed << endl;
    cout << "Tests passed: " << iPassed << endl;
    cout << "Tests failed: " << iFailed << endl;

    if (iFailed == 0)
    {
        cout << "\nAll tests have passed! NICE :DD" << endl;
    }
    else
    {
        cout << "\nSome tests failed. :((" << endl;
    }
}
