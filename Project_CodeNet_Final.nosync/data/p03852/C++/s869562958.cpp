#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    string T = "aiueo";
    if (T.find(S) == string::npos) cout << "consonant" << endl;
    else cout << "vowel" << endl;
    return 0;
}