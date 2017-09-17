//***********************************************************************************************//
//    Brief:  Calculates the sum of all elements in a vector filled with a series of values.     //
//    Author: M. Freudenberg                                                                     //
//    Date:   03.09.2017 (DD.MM.YYYY)                                                            //
//***********************************************************************************************//


#include <vector>
#include <iostream>

using namespace std;

const unsigned int element_count = 40;

// Tests whether an addition of summand_a and summand_b would lead to an over- or underflow.
// Assumes that the result of the addition will be stored in a variable of type Summable_A
template<class Sum_Type, class Summable_A_Type, class Summable_B_Type>
inline bool safe_addition(Sum_Type& sum, Summable_A_Type& summand_a, Summable_B_Type& summand_b)
{
	// Test for overflow
	if ((summand_a > numeric_limits<Sum_Type>::max() - summand_b) || (summand_a < numeric_limits<Sum_Type>::lowest() + summand_b))
	{
		return false;
	}

	sum = summand_a + summand_b;
	return true;
}

// Computes the sum of all elements in a vector. Checks for over- and underflow for the
// used result-type. Vector must contain elements that are summable!
// If an over- or underflow is caught, the result is not changed and an exception is thrown.
template<typename Summable, typename SumType>
inline bool sum(vector<Summable> vector, SumType& result)
{
	SumType temp_sum = 0;

	for (Summable& value : vector)
	{
		if (true != safe_addition(temp_sum, temp_sum, value))
			return false;
	}

	result = temp_sum;
	return true;
}

int main()
{
	vector<int> data(element_count);
	int result;

	// Fill vector with values
	int i = 0;
	for (auto& value : data)
	{
		value = i++;
	}

	// Sum all elements, abort in case of error
	if (true != sum(data, result))
	{
		cerr << "Over- or underflow during summation!";
		return 1;
	}

	// Print result of summation and terminate
	cout << "sum is " << result;
	return 0;
}