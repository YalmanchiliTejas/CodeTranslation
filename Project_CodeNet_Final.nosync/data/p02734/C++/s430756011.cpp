#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define add(a,b) if ((a+=b)>=998244353)a-=998244353

int main() {
    ll N, S, ans = 0; cin >> N >> S;
    vl dp(3001, 0);
    rep(i,N) {
        ll a; scanf("%ld",&a);
        vl ndp(3001, 0);
        ndp[0] = ndp[a] = 1;
        rep(j,3001) {
            add(ndp[j], dp[j]);
            if (j+a > S) continue;
            add(ndp[j+a], dp[j]);
        }
        add(ans, ndp[S]);
        dp = ndp;
    }
    cout << ans << endl;
    return 0;
}
