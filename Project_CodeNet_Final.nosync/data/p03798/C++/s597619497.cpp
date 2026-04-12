#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    //a[i] = 0:羊 a[i] = 1:狼

    for (int bit = 0; bit < 4; bit++) {
        vector<int> a(n, -1);
        if (bit&(1<<0)) a.at(0) = 0;
        else a.at(0) = 1;
        if (bit&(1<<1)) a.at(1) = 0;
        else a.at(1) = 1;

        if (a.at(0) == 0) {
            if (s.at(0) == 'o') a.at(n - 1) = a.at(1);
            else a.at(n - 1) = a.at(1) ^ 1;
        }
        else {
            if (s.at(0) == 'o') a.at(n - 1) = a.at(1) ^ 1;
            else a.at(n - 1) = a.at(1);
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (1 <= i && i <= n - 3) {
                if (a.at(i) == 0) {
                    if (s.at(i) == 'o') a.at(i + 1) = a.at(i - 1);
                    else a.at(i + 1) = a.at(i - 1) ^ 1;
                }
                else {
                    if (s.at(i) == 'o') a.at(i + 1) = a.at(i - 1) ^ 1;
                    else a.at(i + 1) = a.at(i - 1);
                }
            }

            if (i == n - 2) {
                if (a.at(i) == 0) {
                    if (s.at(i) == 'o') {
                        if (a.at(i - 1) != a.at(i + 1)) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        if (a.at(i - 1) == a.at(i + 1)) {
                            ok = false;
                            break;
                        }
                    }
                }
                else {
                    if (s.at(i) == 'o') {
                        if (a.at(i - 1) == a.at(i + 1)) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        if (a.at(i - 1) != a.at(i + 1)) {
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if (i == n - 1) {
                if (a.at(i) == 0) {
                    if (s.at(i) == 'o') {
                        if (a.at(i - 1) != a.at(0)) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        if (a.at(i - 1) == a.at(0)) {
                            ok = false;
                            break;
                        }
                    }
                }
                else {
                    if (s.at(i) == 'o') {
                        if (a.at(i - 1) == a.at(0)) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        if (a.at(i - 1) != a.at(0)) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }

        if (ok) {
            for (int i = 0; i < n; i++) {
                if (a.at(i) == 0) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}   