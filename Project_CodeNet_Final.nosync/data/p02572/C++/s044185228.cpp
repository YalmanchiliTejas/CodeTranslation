#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INFLL = 1LL << 60;
const long long MOD = 1e9 + 7;
int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<ll> B(N + 1, 0);
    ll ans = 0;
    B[0] = 0;
    rep(i, N) {
        cin >> A[i];
        B[i + 1] = B[i] + A[i];
    }
    rep(i, N) {
        ll sum = (B[N] - B[i + 1]) % MOD;
        ans += A[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
}