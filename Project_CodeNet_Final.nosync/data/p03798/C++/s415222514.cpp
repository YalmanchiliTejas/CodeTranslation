// https://atcoder.jp/contests/arc069/tasks/arc069_b
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s[n] = s[0], s[n + 1] = s[1];
    REP(i, 4) {
        bitset<100005> a;
        a[0] = i & 1, a[1] = (i >> 1) & 1;
        FOR(j, 2, n + 2) a[j] = (s[j - 1] == 'x') ^ a[j - 1] ^ a[j - 2];
        if (a[0] == a[n] && a[1] == a[n + 1]) {
            REP(j, n) cout << (a[j] ? "W" : "S");
            cout << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
