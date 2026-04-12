#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long int 
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A') {
        cout << "No" << endl;
    } else if (s[0] == 'B' && s[1] == 'B' && s[2] == 'B') {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

