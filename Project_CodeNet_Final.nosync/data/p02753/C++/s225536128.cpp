#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool yes = false;
    if(s[0] != s[1])yes = true;
    if(s[1] != s[2])yes = true;
    if(yes)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}