#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    // Here your code !
    char c;
    cin >> c;
    if([&](){
    for( char a : {'a','i','u','e','o'} ) if(a==c) return true;
    return false;
    }()) cout << "vowel" << endl;
    else
    cout << "consonant" << endl;
    
}
