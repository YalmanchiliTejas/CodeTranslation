// https://atcoder.jp/contests/abc078/tasks/abc078_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;

    return 0;
}
