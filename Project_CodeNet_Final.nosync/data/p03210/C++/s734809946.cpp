// https://atcoder.jp/contests/abc114/tasks/abc114_a
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (n == 3 || n == 5 || n == 7 ? "YES\n" : "NO\n");

    return 0;
}
