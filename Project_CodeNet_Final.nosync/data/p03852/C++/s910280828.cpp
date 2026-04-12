#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    cin >> c;
    string ans = "vowel"; 
    if (c == 'a') {
    } else if ( c == 'i') {
    } else if ( c == 'u') {
    } else if ( c == 'e') {
    } else if ( c == 'o') {
    } else {
        ans = "consonant";
    }
    cout << ans << endl;
}