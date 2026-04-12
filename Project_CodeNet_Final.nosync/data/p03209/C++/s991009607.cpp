#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 200000000;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

// level i : patty: 2**(n+1) - 1
vector<ll> patty, all;

ll solve(ll level, ll x) {
    if (level == 0) {
        return 1;
    }

    if (x <= 1) {
        return 0;
    } else if (x <= 1 + all[level - 1]) {
        return solve(level - 1, x - 1);
    } else if (x == 2 + all[level - 1]) {
        return 1 + patty[level - 1];
    } else if (x <= 2 + 2 * all[level - 1]) {
        return 1 + patty[level - 1] + solve(level - 1, x - 2 - all[level - 1]);
    } else if (x == 3 + 2 * all[level - 1]) {
        return patty[level];
    }

    cout << "error\n";
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;

    patty.push_back(1);
    all.push_back(1);
    REP(i, 55) {
        patty.push_back(2 * patty[i] + 1);
        all.push_back(2 * all[i] + 3);
    }

    cout << solve(n, x) << endl;

    return 0;
}
