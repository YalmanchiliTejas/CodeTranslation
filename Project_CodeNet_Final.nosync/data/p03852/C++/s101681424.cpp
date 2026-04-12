#include<bits/stdc++.h>
using namespace std;

int main(){
    char c;
    const string s = "aeiou";
    cin >> c;
    if(s.find(c)!=string :: npos) cout << "vowel" << endl;
    else cout << "consonant" << endl;
    //cout << s.find(c) == string::npos ? "vowel" : "consonant" <<endl;

    return 0;
}
