/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>


#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int start_index = 0;
    int end_index = n - 1;
    int test_index;
    
    while (start_index <= end_index)
    {
        test_index = (end_index + start_index) / 2;
        if (values[test_index] == value)
        { 
            return true;
        }
        else if (values[test_index] > value)
        {
            end_index = test_index - 1;
        } 
        else if (values[test_index] < value)
        {
            start_index = test_index + 1;
        } 
     
    } 
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int lower;
    int min_index;
    for (int i = 0; i < n-2; i++)
    {
        min_index = i;
        for (int m = i+1; m < n; m++)
        {
            if (values[m] < values[min_index])
            {
                min_index = m;
            }
        }
        lower = values[min_index];
        values[min_index] = values[i];
        values[i] = lower;
    }
    return;
}
