
/***********************************************************************
Bachelor of Software Engineering
Media Design School at Strayer
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : discretemaths.cpp
Description : Implements discrete mathematics functions.
Author : Vincent
Mail : Vincentantonweber@gmail.com
************************************************************************/

#include "discretemaths.h"


// this gets the possitive value of the number
float Magnitude(const float _kfX)
{
    if (_kfX < 0)
    {
        return _kfX * -1;
    }
    else
    {
        return _kfX;
    }
}


// this returns back -1 if its a negative number and 1 for positive and 0 for zero.
float Signum(const float _kfX)
{
    if (_kfX < 0)
    {
        return -1;
    }
    else if (_kfX > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// this rounds the number down .
float Floor(const float _kfX)
{
    int iValue = (int)_kfX;

    // negative decimals need to go down one more.
    if (_kfX < iValue)
    {
        iValue = iValue - 1;
    }

    return (float)iValue;
}


// this makes it so it rounds the numbers to whole number 
float Ceiling(const float _kfX)
{
    int iValue = (int)_kfX;

    if (_kfX > iValue)
    {
        iValue = iValue + 1;
    }

    return (float)iValue;
}


// factorial multiplies the numbers from 1 up to the number given.
// for example 5 factorial is 5 x 4 x 3 and goes down to 1
unsigned long long Factorial(const unsigned int _kdn)
{
    unsigned long long ullResult = 1;

    for (unsigned int i = 1; i <= _kdn; i++)
    {
        ullResult = ullResult * i;
    }

    return ullResult;
}


// combination is used when the order of the items does not matter 
unsigned long long Combination(const unsigned int _kuin, const unsigned int _kuir)
{
    if (_kuir > _kuin)
    {
        return 0;
    }

    unsigned int iSmaller = _kuir;

    // this uses smaller numbers to make the calculations easierx.
    if (_kuir > _kuin - _kuir)
    {
        iSmaller = _kuin - _kuir;
    }

    unsigned long long ullResult = 1;

    for (unsigned int i = 1; i <= iSmaller; i++)
    {
        ullResult = ullResult * (_kuin - i + 1) / i;
    }

    return ullResult;
}


// this is when the order of selected items matter 
unsigned long long Permutation(const unsigned int _kuin, const unsigned int _kuir)
{
    if (_kuir > _kuin)
    {
        return 0;
    }

    unsigned long long ullResult = 1;

    for (unsigned int i = 0; i < _kuir; i++)
    {
        ullResult = ullResult * (_kuin - i);
    }

    return ullResult;
}


// this counts how many elemtns are in the set
int Cardinality(Set& _rSet)
{
    int iCount = 0;

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rSet.ContainsElement(i) == true)
        {
            iCount = iCount + 1;
        }
    }

    return iCount;
}


// this works on how many subsets can be made 
unsigned long long Power(Set& _rSet)
{
    int iCount = Cardinality(_rSet);
    unsigned long long ullResult = 1;

    // the elements can either be included or not included .
    for (int i = 0; i < iCount; i++)
    {
        ullResult = ullResult * 2;
    }

    return ullResult;
}


// this works out  how many pairs can be made between the two sets.
unsigned long long CartesianProduct(Set& _rA, Set& _rB)
{
    int iSizeA = Cardinality(_rA);
    int iSizeB = Cardinality(_rB);

    return (unsigned long long)(iSizeA * iSizeB);
}


// this checks if both of them contain the same elements .
bool Equals(Set& _rA, Set& _rB)
{
    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) != _rB.ContainsElement(i))
        {
            return false;
        }
    }

    return true;
}


// sees if the elements that are in B are also in A
bool Subset(Set& _rA, Set& _rB)
{
    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == true &&
            _rB.ContainsElement(i) == false)
        {
            return false;
        }
    }

    return true;
}


// checks if what is inside A is inside B
bool Superset(Set& _rA, Set& _rB)
{
    return Subset(_rB, _rA);
}


// this checks if they have no elements taht are in common.
bool Disjoint(Set& _rA, Set& _rB)
{
    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == true &&
            _rB.ContainsElement(i) == true)
        {
            return false;
        }
    }

    return true;
}


// this combines both the elements 
Set& Union(Set& _rA, Set& _rB, Set& _rResultant)
{
    _rResultant.SetClear();

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == true ||
            _rB.ContainsElement(i) == true)
        {
            _rResultant.AddElement(i);
        }
    }

    return _rResultant;
}


// this adds the elements that are in both of the sets 
Set& Intersection(Set& _rA, Set& _rB, Set& _rResultant)
{
    _rResultant.SetClear();

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == true &&
            _rB.ContainsElement(i) == true)
        {
            _rResultant.AddElement(i);
        }
    }

    return _rResultant;
}


// only gets whats in A and not whats in B
Set& SetDifference(Set& _rA, Set& _rB, Set& _rResultant)
{
    _rResultant.SetClear();

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == true &&
            _rB.ContainsElement(i) == false)
        {
            _rResultant.AddElement(i);
        }
    }

    return _rResultant;
}


// gets elements that are only in one of the sets 
Set& SymmetricDifference(Set& _rA, Set& _rB, Set& _rResultant)
{
    _rResultant.SetClear();

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) != _rB.ContainsElement(i))
        {
            _rResultant.AddElement(i);
        }
    }

    return _rResultant;
}


// gets what ever is from 1 to 100 that is not inside set A.
Set& Complement(Set& _rA, Set& _rResultant)
{
    _rResultant.SetClear();

    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) == false)
        {
            _rResultant.AddElement(i);
        }
    }

    return _rResultant;
}
