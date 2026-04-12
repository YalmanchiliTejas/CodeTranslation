#include <bits/stdc++.h>
using namespace std;

int main() {
    //input
    string c;
    cin >> c;

    if(c == "a" || c == "i" ||c == "u" ||c == "e" ||c == "o"){
        cout << "vowel";
    }else{
        cout << "consonant";
    }

    return 0;
}