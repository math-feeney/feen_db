/*
Author: Michael Feeney
Date: 2025-10-28
Description: Some kind of database thing
*/

#include <stdio.h>
#include <stdint.h>

// TODO: implement my own strcpy() 
#include <string.h>

typedef uint64_t INDEX;
typedef int64_t BIGINT;

// TODO: see if there is a way to guarantee size for a double
// One idea is to use an int64_t and then cast to a double?
// Still not sure if that would guarantee a size
typedef double REAL;
typedef char STATE[2];
// TODO: see if there is a more flexible way to adjust the 
// number of bytes
typedef char CHAR32[32];

// Make a prototype record for now
struct test_table
{
    INDEX index;
    CHAR32 name;
    STATE state;
    BIGINT count;
    REAL avg_score;
};

int main(void)
{
    //check to see if size of double is what we think
    if(sizeof(REAL) != 8)
    {
        printf("Error: size of double is not 8-bytes\nit is: %zd\n", sizeof(double));
        return 1;
    }

    test_table test_record = {};

    test_record.index = 1;
    strncpy(test_record.name, "Test Name", sizeof(test_record.name) - 1);

    printf("test_record.index: %I64d\n", test_record.index);
    printf("test_record.name: %s\n", test_record.name);

    return 0;
}