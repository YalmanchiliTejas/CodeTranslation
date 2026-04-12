#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;
const int mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void add(ll& a, ll b) { (a += b) %= mod; }

int main() {
    ll N, S, ans = 0; cin >> N >> S;
    vl A(N), dp(3030, 0);
    rep(i,N) cin >> A[i];
    rep(i,N) {
        vl ndp(3030, 0);
        ndp[0] = ndp[A[i]] = 1;
        rep(j,3030) {
            add(ndp[j], dp[j]);
            if (j+A[i] > S) continue;
            add(ndp[j+A[i]], dp[j]);
        }
        add(ans, ndp[S]);
        dp = ndp;
    }
    cout << ans << endl;
    return 0;
}
