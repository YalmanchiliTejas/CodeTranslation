#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for( int i = l; i <= r; i++ )
#define vi vector<int>
#define vvi vector<vi>
#define st string

int mod = 1e9+7;

void addMod( int & a, int b ) {
    a += b;
    if( a >= mod ) a -= mod;
}

int main() {
    st k; cin>>k;
    int d; cin>>d;
    vvi dp(d,vi(2,0));
    int len = k.length();
    FOR(digit,0,k[0]-'0') {
        dp[digit%d][(digit<k[0]-'0')] += 1;
    }
    FOR(i,1,len-1) {
        vvi n_dp(d,vi(2,0));
        FOR(smaller_already,0,1) {
            FOR(digit,0,9) {
                if( !smaller_already && digit > k[i]-'0' ) break;
                FOR(rems,0,d-1) {
                    addMod(n_dp[(rems+digit)%d][smaller_already||(digit<k[i]-'0')],dp[rems][smaller_already]);
                }
            }
        }
        dp = n_dp;
    }
    // FOR(i,0,d-1) FOR(j,0,1) cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
    int ans = (dp[0][0]+dp[0][1]-1+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}