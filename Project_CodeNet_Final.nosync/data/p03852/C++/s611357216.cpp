// ABC049
// A - 居合を終え、青い絵を覆う / UOIAUAI
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "aiueo";
    char c;
    cin >> c;
    if(s.find(c) != string::npos) cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}
