#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define exist(s,x) (s).find(x)!=(s).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
#define fi first
#define se second
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}
inline ll modpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y&1) res = mul(res,x);
        y >>= 1;
        x = mul(x,x);
    }
    return res;
}

int main(){
    string S; cin >> S;
    int K; cin >> K;
    ll dp[S.size()+1][K+1][2];
    memset(dp,0,sizeof(dp));
    dp[0][0][1] = 1;
    FOR(i,1,S.size()+1)REP(j,K+1) {
        dp[i][j][0] += dp[i-1][j][0];
        if(j) dp[i][j][0] += dp[i-1][j-1][0] * 9;
        if((int)(S[i-1]-'0')) dp[i][j][0] += dp[i-1][j][1];
        if(j && ((int)S[i-1]-'0')) dp[i][j][0] += dp[i-1][j-1][1] * ((ll)(S[i-1]-'0')-1);  
        if(S[i-1]=='0') dp[i][j][1] = dp[i-1][j][1];
        if(j && (int)(S[i-1]-'0')) dp[i][j][1] = dp[i-1][j-1][1];
    }
    cout << dp[S.size()][K][0]+dp[S.size()][K][1] << endl;
}