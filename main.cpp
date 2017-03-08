#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack test;
    for (int i = 0; i < 100000; i++){
        test.push(i);
    }

    for (int i = 0; i < 100000; i++){
        test.pop();
    }

    // I do not know how to answer question 2 but here are some stats
    cout << "number of times the stack shrunk: " << test.numDecresed << endl;
    cout << "number of times the stack grew: " << test.numIncresed << endl;
}
