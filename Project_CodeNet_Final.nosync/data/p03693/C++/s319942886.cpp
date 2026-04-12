// https://atcoder.jp/contests/abc064/tasks/abc064_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int t = a * 100 + b * 10 + c;
    if (t % 4 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
