#include <iostream>    // std::cout

#include <limits>      // std::numeric_limits

#include<typeinfo>

using namespace std;
/// <summaryy
/// Template function to abstract away the logic of:
///  start + (increment * steps)
/// </summary>
/// <typeparam name="T">A type that with basic math functions</typeparam>
/// <param name="start">The number to start with</param>
/// <param name="increment">How much to add each step</param>
/// <param name="steps">The number of steps to iterate</param>
/// <returns>start + (increment * steps)</returns>0

template <typename T>

T add_numbers(T const& start, T const& increment, unsigned long int const& steps)
{

    T result = start;

    for (unsigned long int i = 0; i < steps; ++i)

    {

        result += increment;

    }
    //added 
    //overflow 
    if (start > 0 && increment > 0 && result > std::numeric_limits<T>::max())
    {
        cout << "test_overflow the addition failed ";
        return -1;

    }

    else if (start < 0 && increment < 0 && result < std::numeric_limits<T>::max()) {
        cout << " test_overflow the addition failed ";

        return -1;

    }

    else
    {
        cout << " no overflow happened ";
        return result;

    }


}

/// <summary>
/// Template function to abstract away the logic of:
///  start - (increment * steps)
/// </summary>
/// <typeparam name="T">A type that with basic math functions</typeparam
/// <param name="start">The number to start with</param>
/// <param name="increment">How much to subtract each step</param>
/// <param name="steps">The number of steps to iterate</param>
/// <returns>start - (increment * steps)</returns>

template <typename T>

T subtract_numbers(T const& start, T const& decrement, unsigned long int const& steps)

{

    T result = start;

    for (unsigned long int i = 0; i < steps; ++i)
    {

        result -= decrement;

    }
    //added 
    //underflow 
    if (start > 0 && decrement > 0 && result < std::numeric_limits<T>::min())
    {
        cout << "test_underflow the addition failed ";
        return -1;

    }

    else if (start < 0 && decrement < 0 && result < std::numeric_limits<T>::min()) {
        cout << "test_underflow the addition failed ";

        return -1;

    }

    else
    {
        cout << "No underflow happened ";
        return result;

    }

}

template <typename T>

void test_overflow()

{


    // START DO NOT CHANGE
    // how many times will we iterate

    const unsigned long int steps = 5;

    // how much will we add each step (result should be: start + (increment * steps))

    const T increment = std::numeric_limits<T>::max() / steps;

    // whats our starting point

    const T start = 0;

    std::cout << "Overflow Test of Type = " << typeid(T).name() << std::endl;

    // END DO NOT CHANGE

    std::cout << "\tAdding Numbers Without Overflow (" << +start << ", " << +increment << ", " << steps << ") = ";

    T result = add_numbers<T>(start, increment, steps);

    if (result != -1)
    {
        std::cout << +result << std::endl;

    }
    else {
        cout << "  Overflow happened \n";
    }

    std::cout << "\tAdding Numbers With Overflow (" << +start << ", " << +increment << ", " << (steps + 1) << ") = ";

    result = add_numbers<T>(start, increment, steps + 1);

    if (result != -1)
    {
        std::cout << +result << std::endl;

    }
    else {
        cout << " Overflow happened after Adding Numbers  \n";
    }


}



template <typename T>

void test_underflow()

{


    // START DO NOT CHANGE
    // how many times will we iterate

    const unsigned long int steps = 5;

    // how much will we subtract each step (result should be: start - (increment * steps))

    const T decrement = std::numeric_limits<T>::max() / steps;

    // whats our starting point

    const T start = std::numeric_limits<T>::max();

    std::cout << "Underflow Test of Type = " << typeid(T).name() << std::endl;

    // END DO NOT CHANGE

    std::cout << "\tSubtracting Numbers Without Overflow (" << +start << ", " << +decrement << ", " << steps << ") = ";

    auto result = subtract_numbers<T>(start, decrement, steps);

    if (result != -1)
    {
        std::cout << +result << std::endl;

    }
    else {
        cout << " Underflow happened \n";
    }

    std::cout << "\tSubtracting Numbers With Overflow (" << +start << ", " << +decrement << ", " << (steps + 1) << ") = ";

    result = subtract_numbers<T>(start, decrement, steps + 1);


    if (result != -1)
    {
        std::cout << +result << std::endl;

    }
    else {
        cout << " Underflow happened \n";
    }

}



void do_overflow_tests(const std::string& star_line)

{

    std::cout << std::endl << star_line << std::endl;

    std::cout << "*** Running Overflow Tests ***" << std::endl;

    std::cout << star_line << std::endl;



    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/
    // signed integers

    test_overflow<char>();
    test_overflow<wchar_t>();
    test_overflow<short int>();
    test_overflow<int>();
    test_overflow<long>();
    test_overflow<long long>();



    // unsigned integers

    test_overflow<unsigned char>();
    test_overflow<unsigned short int>();
    test_overflow<unsigned int>();
    test_overflow<unsigned long>();
    test_overflow<unsigned long long>();



    // real numbers

    test_overflow<float>();
    test_overflow<double>();
    test_overflow<long double>();

}

void do_underflow_tests(const std::string& star_line)

{

    std::cout << std::endl << star_line << std::endl;

    std::cout << "*** Running Undeflow Tests ***" << std::endl;

    std::cout << star_line << std::endl;



    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/

    // signed integers

    test_underflow<char>();
    test_underflow<wchar_t>();
    test_underflow<short int>();
    test_underflow<int>();
    test_underflow<long>();
    test_underflow<long long>();



    // unsigned integers

    test_underflow<unsigned char>();
    test_underflow<unsigned short int>();
    test_underflow<unsigned int>();
    test_underflow<unsigned long>();
    test_underflow<unsigned long long>();



    // real numbers

    test_underflow<float>();
    test_underflow<double>();
    test_underflow<long double>();

}

/// <summary>
/// Entry point into the application
/// </summary>
/// <returns>0 when complete</returns>

int main()

{

    // create a string of "*" to use in the console
    const std::string star_line = std::string(50, '*');
    std::cout << "Starting Numeric Underflow / Overflow Tests!" << std::endl;

    // run the overflow tests
    do_overflow_tests(star_line);

    // run the underflow tests
    do_underflow_tests(star_line);
    std::cout << std::endl << "All Numeric Underflow / Overflow Tests Complete!" << std::endl;

    return 0;

}