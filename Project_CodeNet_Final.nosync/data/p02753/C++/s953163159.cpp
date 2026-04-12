#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    char c1 = S[0], c2 = S[1], c3 = S[2];

    if (c1 == c2) {
        if (c1 == c3) {
            cout << "No" << endl;
            return 0;
        } else {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        cout << "Yes" << endl;
        return 0;
    }


}