#include <bits/stdc++.h>
using namespace std;
int main(){
    char s;
    cin >> s;
    bool isVowel = false;
    if(s=='a'|| s=='i'||s=='u'||s=='e'||s=='o') isVowel = true;
    cout << (isVowel ? "vowel" : "consonant") << endl;
}