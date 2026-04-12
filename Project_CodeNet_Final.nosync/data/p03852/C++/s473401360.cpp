#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string C;
    string vowel = "aiueo";
    cin >> C;
    if (vowel.find(C) != string::npos){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }
}
