#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    //cout << "Please input a letter you like." << endl;
    cin >> c;
    string vowel = "aiueo";
    if(vowel.find(c) != string::npos)
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}