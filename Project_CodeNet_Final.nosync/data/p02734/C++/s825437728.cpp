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
const int MOD=998244353;

void add(int &x,int y){
    x+=y;
    x%=MOD;
}

int n,s;
int a[3001],dp[3001][3001][3];
signed main(){
    cin>>n>>s;
    REP(i,n)cin>>a[i];
    dp[0][0][0]=1;
    REP(i,n){
        REP(j,s+1){
            add(dp[i+1][j][0],dp[i][j][0]);
            add(dp[i+1][j][1],dp[i][j][0]+dp[i][j][1]);
            add(dp[i+1][j][2],dp[i][j][0]+dp[i][j][1]+dp[i][j][2]);
            if(j-a[i]>-1){
                add(dp[i+1][j][1],dp[i][j-a[i]][0]+dp[i][j-a[i]][1]);
                add(dp[i+1][j][2],dp[i][j-a[i]][0]+dp[i][j-a[i]][1]);
            }
        }
    }
    cout<<dp[n][s][2]<<endl;
}