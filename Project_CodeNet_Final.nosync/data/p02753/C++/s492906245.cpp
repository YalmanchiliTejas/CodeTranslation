#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int cnt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (S.at(i) == 'A' && S.at(j) == 'B') {
                cnt++;
            }
        }
    }

    if (cnt > 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}