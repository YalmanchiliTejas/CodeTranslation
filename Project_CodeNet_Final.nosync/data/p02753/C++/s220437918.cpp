#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main () {
    
    string s; cin >> s;

    int counta = 0, countb = 0;
    if(s[0] == 'A') counta++;
    else countb++;
    if(s[1] == 'A') counta++;
    else countb++;
    if(s[2] == 'A') counta++;
    else countb++;

    if(counta == 3 || counta == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}