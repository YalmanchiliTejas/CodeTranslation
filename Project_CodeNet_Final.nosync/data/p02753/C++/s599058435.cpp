#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool a = false;
    bool b = false;
    for (auto c = S.begin(); c != S.end(); c++) {
        if (*c == 'A') {
            a = true;
        } else {
            b = true;
        }
        if (a && b) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
