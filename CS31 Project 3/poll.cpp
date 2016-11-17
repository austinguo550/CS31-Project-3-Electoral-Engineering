//
//  main.cpp
//  CS31 Project 3
//
//  Created by Austin Guo on 10/25/16.
//  Copyright © 2016 Austin Guo. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;


bool hasCorrectSyntax(string pollData);
int countVotes(string pollData, char party, int& voteCount);

//private helper methods
void upperCasing (string&);

void testone(int n)
{
    int v = 666;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert(!hasCorrectSyntax("3"));
        } break; case  2: {
            assert(!hasCorrectSyntax("#"));
        } break; case  3: {
            assert(!hasCorrectSyntax("3A"));
        } break; case  4: {
            assert(!hasCorrectSyntax("#A"));
        } break; case  5: {
            assert(!hasCorrectSyntax("C3"));
        } break; case  6: {
            assert(!hasCorrectSyntax("C#"));
        } break; case  7: {
            assert(!hasCorrectSyntax("CX"));
        } break; case  8: {
            assert(!hasCorrectSyntax("CA"));
        } break; case  9: {
            assert(!hasCorrectSyntax("CA3"));
        } break; case 10: {
            assert(!hasCorrectSyntax("CA73"));
        } break; case 11: {
            assert(!hasCorrectSyntax("CAD"));
        } break; case 12: {
            assert(!hasCorrectSyntax("CA$"));
        } break; case 13: {
            assert(!hasCorrectSyntax("CA7%"));
        } break; case 14: {
            assert(!hasCorrectSyntax("CA73%"));
        } break; case 15: {
            assert(!hasCorrectSyntax("CA738"));
        } break; case 16: {
            assert(!hasCorrectSyntax("CA738D"));
        } break; case 17: {
            assert(!hasCorrectSyntax("CA006D"));
        } break; case 18: {
            assert(!hasCorrectSyntax("XU44D"));
        } break; case 19: {
            assert(!hasCorrectSyntax("Xu44D"));
        } break; case 20: {
            assert(!hasCorrectSyntax("xU44D"));
        } break; case 21: {
            assert(!hasCorrectSyntax("xu44D"));
        } break; case 22: {
            assert(!hasCorrectSyntax("CA 55D"));
        } break; case 23: {
            assert(!hasCorrectSyntax("TX12R CA55D"));
        } break; case 24: {
            assert(!hasCorrectSyntax("TX12R3NY29D"));
        } break; case 25: {
            assert(!hasCorrectSyntax("TX12R#NY29D"));
        } break; case 26: {
            assert(!hasCorrectSyntax("TX12R3ANY29D"));
        } break; case 27: {
            assert(!hasCorrectSyntax("TX12R#ANY29D"));
        } break; case 28: {
            assert(!hasCorrectSyntax("TX12RC3NY29D"));
        } break; case 29: {
            assert(!hasCorrectSyntax("TX12RC#NY29D"));
        } break; case 30: {
            assert(!hasCorrectSyntax("TX12RCXNY29D"));
        } break; case 31: {
            assert(!hasCorrectSyntax("TX12RCANY29D"));
        } break; case 32: {
            assert(!hasCorrectSyntax("TX12RCA3NY29D"));
        } break; case 33: {
            assert(!hasCorrectSyntax("TX12RCA73NY29D"));
        } break; case 34: {
            assert(!hasCorrectSyntax("TX12RCADNY29D"));
        } break; case 35: {
            assert(!hasCorrectSyntax("TX12RCA$NY29D"));
        } break; case 36: {
            assert(!hasCorrectSyntax("TX12RCA7%NY29D"));
        } break; case 37: {
            assert(!hasCorrectSyntax("TX12RCA73%NY29D"));
        } break; case 38: {
            assert(!hasCorrectSyntax("TX12RCA738NY29D"));
        } break; case 39: {
            assert(!hasCorrectSyntax("TX12RCA738DNY29D"));
        } break; case 40: {
            assert(!hasCorrectSyntax("TX12RCA006DNY29D"));
        } break; case 41: {
            assert(!hasCorrectSyntax("TX12RCA 55DNY29D"));
        } break; case 42: {
            assert(hasCorrectSyntax(""));
        } break; case 43: {
            assert(hasCorrectSyntax("Ca4D"));
        } break; case 44: {
            assert(hasCorrectSyntax("cA4D"));
        } break; case 45: {
            assert(hasCorrectSyntax("ca4D"));
        } break; case 46: {
            assert(hasCorrectSyntax("CA42D"));
        } break; case 47: {
            assert(hasCorrectSyntax("Ca42D"));
        } break; case 48: {
            assert(hasCorrectSyntax("cA42D"));
        } break; case 49: {
            assert(hasCorrectSyntax("ca42D"));
        } break; case 50: {
            assert(hasCorrectSyntax("CA9D"));
        } break; case 51: {
            assert(hasCorrectSyntax("CA4D"));
        } break; case 52: {
            assert(hasCorrectSyntax("CA0D"));
        } break; case 53: {
            assert(hasCorrectSyntax("CA89D"));
        } break; case 54: {
            assert(hasCorrectSyntax("CA09D"));
        } break; case 55: {
            assert(hasCorrectSyntax("CA00D"));
        } break; case 56: {
            assert(hasCorrectSyntax("CA4d"));
        } break; case 57: {
            assert(hasCorrectSyntax("CA42d"));
        } break; case 58: {
            assert(hasCorrectSyntax("CA4Z"));
        } break; case 59: {
            assert(hasCorrectSyntax("CA42Z"));
        } break; case 60: {
            assert(hasCorrectSyntax("ND3RCT7D"));
        } break; case 61: {
            assert(hasCorrectSyntax("OH18RCT7D"));
        } break; case 62: {
            assert(hasCorrectSyntax("ND3RIL20D"));
        } break; case 63: {
            assert(hasCorrectSyntax("OH18RIL20D"));
        } break; case 64: {
            assert(hasCorrectSyntax("ND3RCT7DOR7DID4RSD3RRI4D"));
        } break; case 65: {
            assert(hasCorrectSyntax("CA55DWA12DTX38RMO10RTN11RMN10DNY29D"));
        } break; case 66: {
            assert(countVotes("3#QQ## QQ####", 'D', v) == 1);
        } break; case 67: {
            countVotes("3#QQ## QQ####", 'D', v);
            assert(v == 666);
        } break; case 68: {
            assert(countVotes("CA0D", 'D', v) == 2);
        } break; case 69: {
            countVotes("CA0D", 'D', v);
            assert(v == 666);
        } break; case 70: {
            assert(countVotes("CA00D", 'D', v) == 2);
        } break; case 71: {
            countVotes("CA00D", 'D', v);
            assert(v == 666);
        } break; case 72: {
            assert(countVotes("ND3RCT7DCA0DSD3R", 'D', v) == 2);
        } break; case 73: {
            assert(countVotes("TX38RNY29DCA00DTN11R", 'D', v) == 2);
        } break; case 74: {
            assert(countVotes("CA0D", 'R', v) == 2);
        } break; case 75: {
            assert(countVotes("CA00D", 'R', v) == 2);
        } break; case 76: {
            assert(countVotes("ND3RCT7DCA0DSD3R", 'R', v) == 2);
        } break; case 77: {
            assert(countVotes("TX38RNY29DCA00DTN11R", 'R', v) == 2);
        } break; case 78: {
            assert(countVotes("WV5R", '5', v) == 3);
        } break; case 79: {
            countVotes("WV5R", '5', v);
            assert(v == 666);
        } break; case 80: {
            assert(countVotes("TX38R", '5', v) == 3);
        } break; case 81: {
            countVotes("TX38R", '5', v);
            assert(v == 666);
        } break; case 82: {
            int r = countVotes("3#QQ## QQ####", '%', v);
            assert(r == 1  ||  r == 3);
        } break; case 83: {
            int r = countVotes("CA0D", '%', v);
            assert(r == 2  ||  r == 3);
        } break; case 84: {
            assert(countVotes("SD3R", 'R', v) == 0  &&  v == 3);
        } break; case 85: {
            assert(countVotes("SD3r", 'R', v) == 0  &&  v == 3);
        } break; case 86: {
            assert(countVotes("SD3R", 'r', v) == 0  &&  v == 3);
        } break; case 87: {
            assert(countVotes("SD3r", 'r', v) == 0  &&  v == 3);
        } break; case 88: {
            assert(countVotes("NY29D", 'D', v) == 0  &&  v == 29);
        } break; case 89: {
            assert(countVotes("NY29d", 'D', v) == 0  &&  v == 29);
        } break; case 90: {
            assert(countVotes("NY29D", 'd', v) == 0  &&  v == 29);
        } break; case 91: {
            assert(countVotes("NY29d", 'd', v) == 0  &&  v == 29);
        } break; case 92: {
            assert(countVotes("UT6L", 'D', v) == 0  &&  v == 0);
        } break; case 93: {
            assert(countVotes("WA11G", 'D', v) == 0  &&  v == 0);
        } break; case 94: {
            assert(countVotes("ND3RCT7DOR7DID4RSD3RRI4D", 'D', v) == 0  &&  v == 18);
        } break; case 95: {
            assert(countVotes("ND3RCT7DOR7DID4RSD3RRI4D", 'R', v) == 0  &&  v == 10);
        } break; case 96: {
            assert(countVotes("ND3RCT7DOR7DID4RSD3RRI4D", 'Z', v) == 0  &&  v == 0);
        } break; case 97: {
            assert(countVotes("CA55DWA12DTX38RMO10RTN11RMN10DNY29D", 'D', v) == 0  &&  v == 106);
        } break; case 98: {
            assert(countVotes("CA55DWA12DTX38RMO10RTN11RMN10DNY29D", 'R', v) == 0  &&  v == 59);
        } break; case 99: {
            assert(countVotes("CA55DWA12DTX38RMO10RTN11RMN10DNY29D", 'Z', v) == 0  &&  v == 0);
        } break; case 100: {
            assert(countVotes("CA55DWA12DTX38RMO10RTN11RMN10DNY29DND3RCT7DOR7DID4RSD3RRI4D", 'D', v) == 0  &&  v == 124);
        }
    }
}


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
    

    
    
    for (int i = 0; i < 100; i++) {
        testone(i);
        cout << "Passed!" << endl;
    }
    
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
                    if (pollData[i] == '0') {
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
