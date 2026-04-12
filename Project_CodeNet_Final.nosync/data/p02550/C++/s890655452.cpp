#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using ml = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

void solve() {
    int N, X, M, S = 0;
    cin >> N >> X >> M;
    vector<pair<int, int>> memo(M);
    REP(i, N) {
        // 循環した場合
        if (memo[X].first) {
            // ループ間の長さ
            int t = i - memo[X].first;
            // ループが繰り返される回数
            int c = (N - i - 1) / t;
            i += t * c;
            S += (S - memo[X].second) * c;
        } else {
            memo[X] = {i, S};
        }
        S += X;
        X = X * X % M;
    }
    cout << S << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
