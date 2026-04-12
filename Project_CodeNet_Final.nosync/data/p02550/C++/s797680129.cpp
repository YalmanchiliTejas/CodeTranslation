#include <bits/stdc++.h>
// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    ll a0 = X % M;
    vector<ll> A;
    set<ll> used;
    A.push_back(X);
    ll last = -1;
    ll ans = 0;
    ans += X;
    rep(i, N-1) {
        ll a = A.back();
        ll v = (a * a) % M;
        if (used.count(v)) {
            last = v;
            break;
        } else {
            ans += v;
            A.push_back(v);
            used.insert(v);
        }
        if (i == N - 2) {
            cout << ans << '\n';
            return;
        }
    }
//    print(A);
//    print(A.back());
//    print((ll) A.size());

    ll idx = -1;
    rep(i, A.size()) {
        if (A[i] == last) {
            idx = i;
            break;
        }
    }
    ll v = 0;
    rep2(i, idx, A.size()) {
        v += A[i];
    }
    ll cnt = A.size() - idx;
    ll R = N - A.size();
    ll r = R / cnt;
    ans += r * v;
    rep(i, R - (cnt * r )) {
        ans += A[idx + i];
    }
    cout << ans << '\n';
    // 492443256176507
    // 492443256042188
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
