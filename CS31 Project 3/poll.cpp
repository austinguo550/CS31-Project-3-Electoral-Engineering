//
//  main.cpp
//  CS31 Project 3
//
//  Created by Austin Guo on 10/25/16.
//  Copyright © 2016 Austin Guo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


bool hasCorrectSyntax(string pollData);
int countVotes(string pollData, char party, int& voteCount);

//private helper methods
void upperCasing (string&);


int main() {
    
    //texting code
    /*if (hasCorrectSyntax("TX38RCA55D"))
        cerr << "Passed test 1: hasCorrectSyntax(\"TX38RCA55D\")"<< endl;
    if (!hasCorrectSyntax("MX38RCA55D"))
        cerr << "Passed test 2: !hasCorrectSyntax(\"MX38RCA55D\")" << endl;
    int votes;
    votes = -999;    // so we can detect whether countVotes sets votes
    if (countVotes("TX38RCA55DMs6rnY29dUT06L", 'd', votes) == 0  &&  votes == 84)
        cerr << "Passed test 3: countVotes(\"TX38RCA55DMs6rnY29dUT06L\", 'd', votes)" << endl;
    votes = -999;    // so we can detect whether countVotes sets votes
    if (countVotes("TX38RCA55D", '%', votes) == 3  &&  votes == -999)
        cerr << "Passed test 4: countVotes(\"TX38RCA55D\", '%', votes)" << endl;
    if (!hasCorrectSyntax("TX38R CA55D"))
        cerr << "Passed test 5: TX38R CA55D not correct syntax" << endl;
    if (!hasCorrectSyntax("TX450R")) {
        cerr << "Passed test 6: TX389R has too many digits: you can only have 1 or 2 digits in a state forecast" << endl;
    }
    if (hasCorrectSyntax("")) {
        cerr << "Passed test 7: empty string is correct syntax" << endl;
    }
    if (!hasCorrectSyntax("CA4")) {
        cerr << "Passed test 8: not a complete state forecast" << endl;
    }
    if (!hasCorrectSyntax("C5d")) {
        cerr << "Passed test 9: not a correct state code" << endl;
    }
    if (!hasCorrectSyntax("gA8dCA918728379871899789327498236781648972384g")) {
        cerr << "Passed test 10: electoral vote has too many digits" << endl;
    }
    if (countVotes("hI35jTX38rCa55dmS6r", '4', votes) == 3) {
        cerr << "Passed test 11: countVotes returns 3 when the party character is not a letter" << endl;
    }
    if (countVotes("h35jTX38rCa55dmS6r", 'r', votes) == 1) {
        cerr << "Passed test 12: countVotes returns 1 when the poll data string has incorrect syntax" << endl;
    }
    if (countVotes("CA0dTX59R", 'r', votes) == 2) {
        cerr << "Passed test 13: countVotes recognizes when there is a zero in the string and correctly returns 2" << endl;
    }
    if (hasCorrectSyntax("CA06dTX59R")) {
        cerr << "Passed test 14: 06 is a correctly formatted electoral vote format" << endl;
    }
    */
    return 0;
}

/*
 *To turn a string to all uppercase to make it easier to check syntax
 */
void upperCasing (string& pollData) {
    for (int i = 0; i < pollData.size(); i++) {
        pollData[i] = toupper(pollData[i]);
    }
}

//*************************************
//  isValidUppercaseStateCode
//*************************************

// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.

bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
    "AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
    "KY.LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC."
    "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}


/*
 *This function returns true if its parameter is a poll data string (i.e., it meets the definition above), or false otherwise.
 */
bool hasCorrectSyntax(string pollData) {
    upperCasing(pollData);
    int i = 0;
    long length = pollData.size();
    while (i < length) {
        //checking if the syntax of the state is correct
        if (i + 1 < length && i + 2 < length && isValidUppercaseStateCode(pollData.substr(i, 2))) {
            if (isalpha(pollData[i]) && isalpha(pollData[i+1])) {
                i += 2;
                //checking the syntax of the electoral votes for correctness
                if (isdigit(pollData[i]) && i + 1 < length) {
                    i++;
                    int count = 1;  //to keep track of how many digits are in the state forecast
                    for (; i < length; i++) {
                        if (isdigit(pollData[i])) {
                            count++;
                            if (count > 2) { //can only have 2 digits or less in state forecast
                                return false;
                            }
                        }
                        else break; //not digits anymore
                    }
                    //checking syntax of the party for correctness
                    if (i < length) {
                        if (isalpha(pollData[i])) {
                            i++;
                            //end of one state forecast, reenter outermost loop to check the next state forecast in the poll data string
                        }
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    return true;
}


/*
 *Counts the number of votes that a given party receives and sets a variable voteCount to that number of votes
 */
int countVotes(string pollData, char party, int& voteCount) {
    //boundary cases
    if (!hasCorrectSyntax(pollData)) {
        return 1;
    }
    //to check if there are any states with zero votes
    int i = 0;
    long length = pollData.size();
    if (hasCorrectSyntax(pollData)) {
        for (; i < length; i++) {
            if (pollData[i] == '0') {
                i++;
                if (i < length) { //to prevent out of bound errors
                    if (pollData[i] == '0' || !isdigit(pollData[i])) {
                        return 2;
                    }
                }
            }
        }
    }
    
    if (!isalpha(party)) {
        return 3;
    }
    
    //if no issue with boundary cases, find the number of votes for a certain party
    
    upperCasing(pollData);
    //cerr << "The poll data string being tested is " << pollData << endl;
    
    //cerr << "The syntax code is " << hasCorrectSyntax(pollData) << endl;
    
    int tempCount = 0;
    voteCount = 0;
    int j = 0;
    if (hasCorrectSyntax(pollData)) {
        for (; j < length; j++) {
            if (isdigit(pollData[j])) {
                tempCount = tempCount * 10 + (pollData[j] - '0'); //code in parentheses to retrieve actual integer value and not char converted int value
                //cerr << "Tempcount = " << tempCount << endl;
            }
            else {
                //cerr << "executed else statement" << endl;
                if (pollData[j] == toupper(party)) {
                    voteCount += tempCount;
                    //cerr << "temp votecount value = " << voteCount << endl;
                }
                tempCount = 0;
            }

        }
    }
    
    return 0;
}
