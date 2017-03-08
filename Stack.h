#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <cstring>

#define DEBUG 0 // set to 1 to display debug information
#if DEBUG
#include <iostream>
#endif // DEBUG

class Stack {
    public:
        Stack();
        ~Stack();
        void push(int );
        void pop();
        int top();

        //counters for the expensive operations
        int numIncresed;
        int numDecresed;

    private:
        int *data;
        int aSize; // size of the stack
        int index; // no of elements in the stack
};

//--------------------------------------------
Stack::Stack(){
    aSize = 2;
    index = 0;
    numIncresed = 0;
    numDecresed = 0;
    data = new int[aSize];
}

//--------------------------------------------
Stack::~Stack(){
    delete[] data;
}

//--------------------------------------------
//adds an element to the array at the top/end
//if the array is full the size of the array is doubled
void Stack::push(int num){
    if (aSize == index){
        int* newArray = new int[aSize * 2];

        memcpy(newArray, data, (aSize * sizeof(int))); //copys the information in the old array and inserts it into the new one
        delete[] data;

        data = newArray;
        aSize *= 2;
        numIncresed++;
    }

    data[index] = num;
    index++;

    #if DEBUG
    for (int i = 0; i < aSize; i++){
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    #endif // DEBUG
}

//--------------------------------------------
//removes the last element from the array
//if the array is 1/4 full the size of the array is halved
void Stack::pop(){
    if (index == 0){
        return;
    }

    index--;

    #if DEBUG
    std::cout << "-----" << std::endl;
    for (int i = 0; i <= index; i++){
        std::cout << data[i] << std::endl;
    }
    std::cout << "-----" << std::endl;
    #endif // DEBUG

    if (index < (aSize / 4)){
        int* newArray = new int[aSize / 2];

        memcpy(newArray, data, ((aSize / 2) * sizeof(int))); //copys the information in the old array and inserts it into the new one
        delete[] data;

        data = newArray;
        aSize /= 2;
        numDecresed++;
    }


}

//--------------------------------------------
//returns the top/last element in the array
int Stack::top(){
    return data[index];
}


#endif // STACK_H_INCLUDED
