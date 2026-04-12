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

long long fastpow(long long n, long long x, long long m) {
    long long ret = 1;
    while (x) {
        if (x & 1)
            (ret *= n) %= m;
        x >>= 1;
        (n *= n) %= m;
    }
    return ret;
}

void solve() {
    int N, X, M;
    cin >> N >> X >> M;
    int sum = X;
    unordered_map<int, int> mp, su;
    REP(i, N - 1) {
        X = fastpow(X, 2, M);
        sum += X;
        if (mp.count(X) > 0) {
            int loopSize = i - mp[X];
            int t = (N - i - 2) / loopSize;
            sum += (sum - su[X]) * t;
            i += loopSize * t;
            mp.clear();
        } else {
            mp[X] = i;
            su[X] = sum;
        }
    }
    cout << sum << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
