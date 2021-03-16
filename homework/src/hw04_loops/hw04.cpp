#include <cmath>
#include <iostream>

#include "hw04.h"

// Pre-conditions: none
// Post-conditions: none
//
//          e.g. x=4, y=0 -> 1
//               x=4, y=1 -> 4
//               x=4, y=2 -> 16
//               x=4, y=3 -> 64/ Returns: returns the pow of x**y (aka x^y, x raised to the y)
unsigned int int_pow(unsigned int x, unsigned int y)
{
    int product = 1; 
    for (int i = 0; i < y; i++)
    {
        product *= x; 
    }
    return product;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: returns the sum of the numbers between [0, .. n]
//
//          if n == 11, the range would be
//              0,1,2,3,4,5,6,7,8,9,10
//
//          And then, you would return the sum of that sequence mentioned above:
//              0+1+2+3+4+5+6+7+8+9+10 -> 55
unsigned int range_sum(unsigned int n)
{
    int j = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += j;
        j++;
    }


    return sum;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: returns the nth number in the fibonacci sequence
//
//          The fibonacci sequence is defined as:
//              fib(0) = 0
//              fib(1) = 1
//              fib(n) = fib(n-2) + fib(n+1)
//          For example, the sequence would look like:
//              0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
unsigned int fibonacci(unsigned int n)
{
    unsigned int no_1 = 1;
    unsigned int no_2 = 0;
    unsigned int sum = 0;
    if (n == 0)
    {
        return 0;
    }

    for (unsigned int i = 0; i < n; i++)
    {
        sum = no_1 + no_2;
        //std::cout << "Sum: " << sum << std::endl;
        no_1 = no_2;
        //std::cout << "Number 1: " << no_1 << std::endl;
        no_2 = sum;
        //std::cout << "Number 2: " << no_2 << std::endl;
    }
    return sum;
}
// Pre-conditions: input will be >= 0.0
// Post-conditions: none
// Returns: returns the cubic root of input calculated via bisection
//
//          Use the bisection algorithm to reduce the guessing space
//          window of where the potential answer could be located at
//
//          if the input is 25, a valid initial window would be [0, 25]
//
//          do note that numbers between [0,1] are a bit special, so think
//          about reasonable windows for those items
//
//          the return value must be within 0.001 of the real answer
//
//          also, the fabs function may be useful for you (floating point
//          absolute value)
//          
double bisect_cubicroot(double input)
{
    const double ACCURACY = 0.001;
    double min = 0.0;
    double max = input;

    if (input < 1.0 and input > 0)
    {
        max = 1;
    }
    double mid = (min + max) / 2;
    double guess_result = mid * mid * mid;

    for (int i = 1; fabs(guess_result - input) > ACCURACY; mid = (min+max)/2, guess_result = mid*mid*mid,i++)
    {

        //if (i <= 10)
        //std::cout << guess_result << std::endl;
        if (guess_result > input)
        {
            max = mid;
            //if (i <= 10)
            //std::cout << min <<"-"<<max<<std::endl;
        }

        if (guess_result < input)
        {
            min = mid;
            //if (i <= 10)
            //std::cout << min <<"-"<<max<<std::endl;
        }
    }
    return mid;

}
