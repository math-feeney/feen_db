/*
Author: Michael Feeney
Description: header file for database
*/

#include <stdio.h>
#include <stdint.h>

// TODO: implement my own strcpy() 
#include <string.h>

typedef uint64_t INDEX; // must be present in each observation, and unique
typedef int64_t BIGINT;
typedef uint64_t TBL_IND; // table index

// TODO: see if there is a way to guarantee size for a double
// One idea is to use an int64_t and then cast to a double?
// Still not sure if that would guarantee a size
typedef double REAL;
typedef char STATE[2];
// TODO: see if there is a more flexible way to adjust the 
// number of bytes
typedef char CHAR32[32];
typedef char PARTY[3];

// Generic struct for all tables
struct TABLE
{
    int number_columns;

    void *table_start; // start

}

// Make a prototype record for now
struct test_table
{
    INDEX index;
    CHAR32 name;
    STATE state;
    BIGINT count;
    REAL avg_score;
};

struct candidate_master
{
    INDEX index; // NOTE: maybe this index will match with the index of the array that is the table itself
    CHAR32 name;
    PARTY party_code; // for DEM, REP, or IND
    REAL total_receipts;
    STATE state;

};

// TODO: start with this function, which prints a single row of a struct
void print_row(candidate_master row_index)// NEED TO CHECK IF THESE PARAMETERS MAKE SENSE
{
    // TODO: so far this takes only a certain struct type
    // so the subypes are already known, 
    // for a more general function I might need to
    // pass the names of the struct? 
}