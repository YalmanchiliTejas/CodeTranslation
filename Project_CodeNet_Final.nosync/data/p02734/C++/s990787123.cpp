#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;
const int mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void add(ll& a, ll b) { (a += b) %= mod; }

int main() {
    int N, S; cin >> N >> S;
    vl A(N);
    rep(i,N) cin >> A[i];
    vvl dp(3030, vl(3, 0));
    dp[0][0] = 1;
    rep(i,N) {
        vvl ndp(3030, vl(3, 0));
        rep(j,S+1) {
            add(ndp[j][0], dp[j][0]);
            add(ndp[j][1], dp[j][0]+dp[j][1]);
            add(ndp[j][2], dp[j][0]+dp[j][1]+dp[j][2]);
            if(j+A[i] > S) continue;
            add(ndp[j+A[i]][1], dp[j][0]+dp[j][1]);
            add(ndp[j+A[i]][2], dp[j][0]+dp[j][1]);
        }
        dp = ndp;
    }
    cout << dp[S][2] << endl;
    return 0;
}
