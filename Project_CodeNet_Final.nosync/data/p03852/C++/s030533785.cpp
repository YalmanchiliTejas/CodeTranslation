#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string letter;
    cin >> letter;

    if (letter == "a" 
        || letter == "e"
        || letter == "i" 
        || letter == "o" 
        || letter == "u") 
    {
       cout << "vowel" << endl;
    }
    
    else
    {
        cout << "consonant" << endl;
    }
    
}