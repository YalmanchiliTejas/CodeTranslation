#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string c;
    getline(cin,c);

    if ((c == "a")||(c == "i")||(c == "u")||(c == "e")||(c == "o")){
      cout << "vowel" << endl;
    }
    else {
      cout << "consonant" << endl;
    }
}