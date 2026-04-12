// https://atcoder.jp/contests/abc177/tasks/abc177_c
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
// using cpp_dec = boost::multiprecision::cpp_dec_float_50;
using cpp_int = boost::multiprecision::cpp_int;

using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)
const int MOD = 1e9 + 7;

// 参考
// https://atcoder.jp/contests/abc177/submissions/16384020
void solve() {
    int N;
    cin >> N;
    cpp_int x = 0, y = 0;
    REP(i, N) {
        cpp_int t;
        cin >> t;
        x += t;
        y += t * t;
    }
    // (A + B + C)^2 = A^2 + B^2 + C^2 + 2*AB + 2*AC + 2*BC
    // 2*AB + 2*AC + 2*BC = (A + B + C)^2 - (A^2 + B^2 + C^2)
    // AB + AC + BC = ((A + B + C)^2 - (A^2 + B^2 + C^2)) / 2
    // = (x^2 - y) / 2
    cout << (x * x - y) / 2 % MOD << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
