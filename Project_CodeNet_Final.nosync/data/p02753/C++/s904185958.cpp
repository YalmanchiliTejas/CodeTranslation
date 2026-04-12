#include <bits/stdc++.h>
using namespace std;

int main() { 
    int f = 0;
    string s;
    cin >> s;
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A') f = 1;
    if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B') f = 1;

    if(!f) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
