#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n_A = 0;
    int n_B = 0;
    for(int i=0; i<3; ++i) {
        if (s[i] == 'A') n_A++;
        else if (s[i] == 'B') n_B++;
    }

    if(n_A == 3 || n_B == 3) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}