#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long n = s.length(), k;
    cin >> k;
    long long res = 0;
    if (k == 1) {
        if (n > 1) res = (n - 1) * 9;
        res += s[0] - '0';
    } else if (k == 2) {
        if (n > 2) res = (((n - 1) * (n - 2)) / 2) * 81;
        if (n > 1) {
            res += (s[0] - '0' - 1) * (n - 1) * 9;
            int i = 1;
            while (i < n) {
                if (s[i] == '0') {
                    i++;
                } else break;
            }
            if (i != n) {
                res += s[i] - '0';
                res += (n - 1 - i) * 9;
            }
        }
    } else {
        if (n > 3) res = (((n - 1) * (n - 2) * (n - 3)) / 6) * 729;
        if (n > 2) {
            // cout << res << " 1" << endl;
            res += (s[0] - '0' - 1) * (((n - 1) * (n - 2))/2) * 81;
            // cout << res << " 2" << endl;
            int i = 1;
            while (i < n) {
                if (s[i] == '0') {
                    i++;
                } else break;
            }
            if (i != n) {
                // res += (n - 1 - i) * 9;
                res += ((n - 1 - i) * (n - 2 - i) / 2) * 81;
                res += (s[i] - '0' - 1) * (n - 1 - i) * 9;
                i++;
                while (i < n) {
                    if (s[i] == '0') {
                        i++;
                    } else break;
                }
                if (i != n) {
                    res += s[i] - '0';
                    res += (n - 1 - i) * 9;
                }
                // cout << res << " 4" << endl;
            }
            // i++;
            // if (i < n) res += (s[i] - '0');
            // cout << res << " 5" << endl;
            // while (i < n) {
            //     if (s[i] == '0') {
            //         i++;
            //     } else break;
            // }
            // if (i < n) {
            //     // res += (n - 1 - i) * 9;
            //     res += (n - 1 - i) *9;
            //     cout << res << " 6" << endl;
            // }
        }
    }
    cout << res;
    return 0;
} 