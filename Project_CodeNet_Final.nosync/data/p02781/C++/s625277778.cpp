#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool check(string a, string b) {
    if (a.size() < b.size()) {
        return true;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

ll two(ll n) {
    return (n * (n - 1)) / 2;
}

ll three(ll n) {
    return (n * (n - 1) * (n - 2)) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string n;
    int k;
    cin >> n >> k;
    ll ans = 0;
    if (k == 1) {
        string cur(n.size(), '0');
        for (int i = 0; i < cur.size(); ++i) {
            for (int j = 1; j <= 9; ++j) {
                cur[i] = '0' + j;
                if (check(cur, n)) {
                    ans++;
                }
                cur[i] = '0';
            }
        }
    } else if (k == 2) {
        string cur(n.size(), '0');
        for (int i = 0; i < cur.size(); ++i) {
            for (int j = i + 1; j < cur.size(); ++j) {
                for (int a = 1; a <= 9; ++a) {
                    for (int b = 1; b <= 9; ++b) {
                        cur[i] = '0' + a;
                        cur[j] = '0' + b;
                        if (check(cur, n)) {
                            ans++;
                        }
                        cur[i] = '0';
                        cur[j] = '0';
                    }
                }
            }
        }
    } else {
        string cur(n.size(), '0');
        cur[0] = n[0];
        for (int i = 1; i < cur.size(); ++i) {
            for (int j = i + 1; j < cur.size(); ++j) {
                for (int a = 1; a <= 9; ++a) {
                    for (int b = 1; b <= 9; ++b) {
                        cur[i] = '0' + a;
                        cur[j] = '0' + b;
                        if (check(cur, n)) {
                            ans++;
                        }
                        cur[i] = '0';
                        cur[j] = '0';
                    }
                }
            }
        }
        ans += (cur[0] - '0' - 1) * two(n.size() - 1) * 81;
        ans += three(n.size() - 1) * 729;
    }
    cout << ans;
    return 0;
}