#include <bits/stdc++.h>
using namespace std;


int main() {
    char c;
    cin >> c;
    string v="aeiou";
    if(v.find(c) != string::npos){
       cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}
