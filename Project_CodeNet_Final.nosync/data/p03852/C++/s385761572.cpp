#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    string s = "aeiou";
    char c; 
    cin >> c;

    if(s.find(c) == string::npos)
        cout << "consonant" << endl;
    else 
        cout << "vowel" << endl;
   

    return 0;
}