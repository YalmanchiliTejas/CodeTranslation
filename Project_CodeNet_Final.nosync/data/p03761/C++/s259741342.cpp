#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> ans(26, 100);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<int> tmp(26, 0);
        for (char c : s) ++tmp[c - 'a'];
        for (int i = 0; i < 26; ++i) ans[i] = min(ans[i], tmp[i]);
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}