#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    for(int i = 0; i < 4; i++) {
        if(s[i] == 'A' && s[i + 1] == 'C') {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}