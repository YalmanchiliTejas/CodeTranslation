#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int (i)=(l);(i)<(r);i++)
#define erep(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define MOD 1000000007
using namespace std;
ll K;

int N;
ll f(string S) {
    N = S.length();
    ll dp[N+1][K+3][2];
    rep(dgt, 0, N + 1) rep(nz, 0, K+2) rep(isless, 0, 2) dp[dgt][nz][isless] = 0;
    dp[0][0][0] = 1;
    rep(dgt, 0, N)rep(nz, 0, K+1)rep(isless, 0, 2) {
        int c = S[dgt] - '0';

        rep(x, 0, 10) {
            int dgt2 = dgt + 1;
            int nz2 = nz;
            if (x != 0) nz2++;
            
            if (isless == 1) {
                dp[dgt2][nz2][isless] += dp[dgt][nz][isless];
            } else {
                if (x < c) dp[dgt2][nz2][1] += dp[dgt][nz][isless];
                else if (x == c) dp[dgt2][nz2][0] += dp[dgt][nz][isless];
            }
        }
    }

    ll res = 0;
    rep(i,K,K+1)rep(isless, 0, 2){
        res += dp[N][i][isless];
       // cout<<dp[N][i][isless]<<endl;
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    cin >> K;
    ll ans = f(S);

    printf("%lld\n", ans);
}