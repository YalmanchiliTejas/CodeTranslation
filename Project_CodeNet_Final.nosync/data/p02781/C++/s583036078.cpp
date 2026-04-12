#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string n;
    cin >> n;
    int len = n.length();
    int k;
    cin >> k;
    if (len < k) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    if (k == 1) {
        for (int i = 1; i < len; ++i) {
            ans += 9;
        }
        ans += n[0] - '0';
    } else {
        if (k == 2) {
            for (int i = 2; i < len; ++i) {
                ans += 9 * (i - 1) * 9;
            }
            ans += (n[0] - '0' - 1) * (len - 1) * 9;
            bool small = false;
            for (int i = 1; i < len; ++i) {
                if (small == true) {
                    ans += 9;
                    continue;
                }
                ans += n[i] - '0';
                if (n[i] != '0') {
                    small = true;
                }
            }
        } else {
            for (int i = 3; i < len; ++i) {
                ans += 9 * (i - 1) * (i - 2) / 2 * 81;
            }
            ans += (n[0] - '0' - 1) * (len - 1) * (len - 2) / 2 * 81;
            bool small = false;
            for (int i = 1; i < len - 1; ++i) {
                if (small == true) {
                    ans += 9 * (len - i - 1) * 9;
                    continue;
                }
                if (n[i] > '0') {
                    ans += (n[i] - '0' - 1) * (len - i - 1) * 9;
                    bool small2 = false;
                    for (int j = i + 1; j < len; ++j) {
                        if (small2 == true) {
                            ans += 9;
                            continue;
                        }
                        ans += n[j] - '0';
                        if (n[j] != '0') small2 = true;
                    }
                }
                if (n[i] != '0') {
                    small = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

