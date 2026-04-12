#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n;
    cin >> n;
    string s;
    int alpha = 26;
    vector<int> a(alpha, INT_MAX);
    for (int i = 0; i < n; i++) {
        vector<int> tmp(alpha, 0);
        cin >> s;
        for (int j = 0; j < (int)s.size(); j++) {
            tmp[(int)(s[j] - 'a')]++;
        }
        for (int j = 0; j < alpha; j++) {
            a[j] = min(a[j], tmp[j]);
        }
    }
    for (int i = 0; i < alpha; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}