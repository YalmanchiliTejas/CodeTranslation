#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

void add(int &x,int y){
    x+=y;
    x%=MOD;
    return;
}

signed main(){
    string k;int d;cin>>k>>d;
    int dp[SZ(k)+1][d][2];
    REP(i,SZ(k)+1)REP(j,d)REP(s,2) dp[i][j][s] = 0;
    dp[0][0][0] = 1;
    REP(i,SZ(k)){
        int z = k[i] - '0';
        REP(j,z) REP(s,d) add(dp[i+1][(s+j)%d][1],dp[i][s][0]);
      	REP(j,10) REP(s,d) add(dp[i+1][(s+j)%d][1],dp[i][s][1]);
        REP(s,d) dp[i+1][(s+z)%d][0] = dp[i][s][0];
    }
    int ans = (dp[SZ(k)][0][0]+dp[SZ(k)][0][1]-1)%MOD;
    if(ans < 0) ans += MOD;
    cout<<ans<<endl;
}
