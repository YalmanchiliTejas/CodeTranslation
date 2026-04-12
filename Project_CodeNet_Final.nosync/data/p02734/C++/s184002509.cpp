#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const ll MOD=998244353;
const int MAXN=3010;
int N,S;
int A[MAXN];
ll dp[MAXN][MAXN];
void read()
{
    cin>>N>>S;
    for(int u=0;u<N;u++)cin>>A[u];
}
void solve()
{
    read();
    ll ans=0;
    for(int u=0;u<N;u++){
        memcpy(dp[u+1],dp[u],sizeof(dp[0]));
        dp[u+1][A[u]]=(dp[u+1][A[u]]+u+1)%MOD;
        for(int v=0;v+A[u]<=S;v++){
            dp[u+1][v+A[u]]=(dp[u+1][v+A[u]]+dp[u][v])%MOD;
        }
        ans=(ans+dp[u+1][S])%MOD;
    }
    cout<<ans<<"\n";
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}