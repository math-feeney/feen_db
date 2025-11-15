/*
Author: Michael Feeney
Date: 2025-10-28
Description: Some kind of database thing
*/

#include "header.h"

struct candidate_master
{
    INDEX index; // NOTE: maybe this index will match with the index of the array that is the table itself
    CHAR32 name;
    PARTY party_code; // for DEM, REP, or IND
    REAL total_receipts;
    STATE state;

};

// initialize candidate master function
// initializes to 0s and ' ' where relevant
// TODO: allow specific values to be passed in
void initialize_candidate(struct candidate_master *cand)
{
    static INDEX cand_index = 0;
    cand_index++;
    cand->index = cand_index;
    memset(cand->name, ' ', sizeof(cand->name));
    memset(cand->party_code, ' ', sizeof(cand->party_code)); 
    cand->total_receipts = 0.0f;
    memset(cand->state, ' ', sizeof(cand->state));
}

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


    // test row to insert into the test table
    candidate_master PetolaMary = {};

    // for now I'm thinking first row will be index 1, and index zero can be metatdata
    PetolaMary.index = 1;
    strncpy(PetolaMary.name, "Petola, Mary", sizeof(PetolaMary.name) - 1);
    strncpy(PetolaMary.party_code, "DEM", sizeof(PetolaMary.party_code) - 1);
    PetolaMary.total_receipts = 136626.13;
    strncpy(PetolaMary.state, "AK", sizeof(PetolaMary.state) - 1);

    // create a table, which will be an array of pointers to structs
    // that are the rows
    int candidate_master_rows = 5;

    candidate_master *CandidateMaster[5] = {};

    CandidateMaster[1] = &PetolaMary;

    // TODO: WRITE THIS FUNCTION, which takes a table name and prints a single row
    print_row(CandidateMaster);

    return 0;
}