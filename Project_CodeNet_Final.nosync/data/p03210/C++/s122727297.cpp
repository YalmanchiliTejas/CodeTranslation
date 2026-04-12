// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int age;
    cin >> age;
    if(age == 7 || age == 5 || age == 3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}