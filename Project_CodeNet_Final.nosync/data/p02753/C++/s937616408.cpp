// https://atcoder.jp/contests/abc158/tasks/abc158_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto &x : s) {
        if (x == 'A')
            a++;
        else if (x == 'B')
            b++;
    }
    if (a == 0 || b == 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}
