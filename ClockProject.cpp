// ClockProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string twoDigitString(unsigned int n) {
    /**
     * You may wish to change this function when you bring it into your program.
     * For now please get it to work here with the existing function signature.
     * You may assume <string> has been included.
     */
     // TODO: your code here to implement the method
     // Numbers between 10 and 59 just need to be converted to a string
     // Numbers from 0 to 9 need a "O" tacked onto the front of the string representation of the number

    int number = n;

    if (number >= 0 && number < 10) {
        return "0" + std::to_string(number);
    }
    else if (number >= 10 && number < 60) {
        return "" + std::to_string(number);
    }
    else {
        return "00";
    }

    // Return the two digit string representation of n
}

std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // You may assume <string> has been imported and the method twoDigitString works
    // for example, twoDigitString(7) returns "07" and twoDigitString(59) returns "59"
    // That should simplify your work here and help you not repeat code.
    // You need a colon betweeh hours and minutes and between minutes and seconds.
    // Tests will pass in (7, 24, 9) and (23, 0, 59) and expect 07:24:09 and 23:00:59
    // You may change this function in the program you submit, but please get it to work
    // here first, with this function signature.
    // TODO: Your code here

    std::string hour = twoDigitString(h);
    std::string mins = twoDigitString(m);
    std::string secs = twoDigitString(s);

    std::string time = "";
    time.append(hour);
    time.append(":");

    time.append(mins);
    time.append(":");

    time.append(secs);

    return time;
    // return time as hh:mm:ss
}

//  You may assume include<string> has been included
/**
 * Formats the time in am/pm format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
 */
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    /**
     * When adding your code below, please leave the method signature alone.
     *
     * You may assume that twoDigitString(n) exists and returns a two-digit string repesenation of n.
     * For example, twoDigitString(7) returns "07" and twoDigitString(12) returns "12".
     *
     * Include colons as separators, add one space after seconds then  A M or P M as appropriate
     */

     // TODO: Your code here
    std::string hours;
    std::string min;
    std::string sec;
    std::string time = "";
    std::string ending;

    if (h < 12) {
        if (h == 0) {
            h = 12;
        }
        hours = twoDigitString(h);
        ending = "A M";
    }
    else if (h >= 12) {
        if (h != 12) {
            h = h - 12;
        }
        hours = twoDigitString(h);
        ending = "P M";
    }

    min = twoDigitString(m);
    sec = twoDigitString(s);

    time.append(hours);
    time.append(":");
    time.append(min);
    time.append(":");
    time.append(sec);
    time.append(" ");
    time.append(ending);

    return time; // replace this placeholder with return of your formatted string
}

std::string nCharString(size_t n, char c) {
    /**
     * You may wish to change this function when you bring it into your program
     * For now please get it to work here with the existing function signature
     * You may assume <string> has been included
     */
     // TODO: your code here to implement the method

    int size = n;
    std::string letter(1, c);
    std::string returnLine = "";
    for (int i = 0; i < size; i++) {
        returnLine.append(letter);
    }

    return returnLine;
    // return the n character string
}

void addOneSecond() {
    /** assume you have working getSecond(), setSecond(s), and addOneMinute()
     * addOneMinute will take care of the hours if necessary
     * Feel free to change things around in your program, but for now please make this work with these function signatures.
     * if getSecond() is between 0 and 58 inclusive, add 1 and setSecond()
     * if getSecond() is 59, seconds wrap around to 0 and you need to call addOneMinute()
     * test will set minutes to 4 and seconds to 0, then addOneSecond 60 times
     */

     // TODO: your code here
    int sec = getSecond();
    if (sec < 59) {
        sec = sec + 1;
        setSecond(sec);
    }
    else {
        sec = 0;
        setSecond(sec);
        addOneMinute();
    }

    // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}

/**
 * Adds one minute
 */
void addOneMinute() {
    /**assume you have working getMinute(), setMinute(m), and addOneHour()
     * Feel free to change these in your program, but for now please get things to work with
     * these function signatures.
     * if getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
     * if getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
     * test will set hours and minutes to 0, then addOneMinute 60 times
     */
     //TODO: Your code here

    int min = getMinute();

    if (min < 59) {
        min = min + 1;
        setMinute(min);
    }
    else {
        min = 0;
        setMinute(min);
        addOneHour();
    }

    // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}

/**
 * Adds one hour
 */
void addOneHour() {
    /** Assume you have a working getHour() and setHour(h)
     * Feel free to change things around in your code, but first please get it working here
     * with these function signatures.
     * if getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
     * if getHour() is 23 the next value for hour is 0 so setHour() to that
     * test will check values of hours from 0 to 23 from getHour()
     */
     // TODO: Your code here

    int hour = getHour();

    if (hour < 23) {
        hour = hour + 1;
        setHour(hour);
    }
    else {
        hour = 0;
        setHour(hour);
    }

    // nothing to return, just setHour to the appropriate value
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // The code in your submitted program may vary. For now, please get this to work with the given
    // function signature.
    // You may assume you have a working nCharString and formatTime24 and formatTime12 and <iostream> has been imported
    //
    // nCharString(27,'*') gives a string of 27 stars. nCharString(3,' ') gives 3 spaces
    // formatTime12(h, m, s) and formatTime24(h, m, s) give the formatted time as specified in the assignment	
    // test will pass in (0, 59, 9)
    // TODO: Your code here, follow the comments for each line

    std::string time12 = formatTime12(h, m, s);
    std::string time24 = formatTime24(h, m, s);

    // cout 27 stars + 3 spaces + 27 stars + endl
    std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
    std::cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
    std::cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    // cout an endl for a blank line
    std::cout << endl;
    // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
    std::cout << nCharString(1, '*') << nCharString(6, ' ') << time12 << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
    std::cout << nCharString(1, '*') << nCharString(8, ' ') << time24 << nCharString(9, ' ') << nCharString(1, '*') << endl;
    // cout 27 stars + 3 spaces + 27 stars + endl
    std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

unsigned int getMenuChoice(unsigned int maxChoice) {
    /**
     * You may change this in your program, but first please get it working here with this function signature.
     * TIPS: take the input in a loop, check that it is in range, and exit the loop only once it is.
     * You will handle clearing the screen and printing the menu elsewhere,
     * so here just get character(s) or number(s) from the user and do not print error messages.
     */
     // TODO: your code here, 

    int userNum;

    std::cin >> userNum;

    while ((userNum >= 1 && userNum <= maxChoice) || (userNum >= 2 && userNum <= 9)) {
        std::cin >> userNum;
    }

    return userNum;

    // return the value
}

int main()
{
    int userInput;
    std::cin >> userInput;

    while (userInput != 4) {
        if (userInput == 1) {
            addOneHour();
        }
        else if (userInput == 2) {
            addOneMinute();
        }
        else if (userInput == 3) {
            addOneSecond();
        }
        getMenuChoice(userInput);
        std::cin >> userInput;
    }
    
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
