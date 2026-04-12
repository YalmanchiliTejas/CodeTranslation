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
const int MAXN=2e5+10;
int N;
ll A[MAXN];
ll dp[MAXN];
ll opre[MAXN];
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int u=1;u<=N;u++)cin>>A[u];
    for(int u=1;u<=N;u+=2){
        if(u==1)opre[u]=A[u];
        else opre[u]=opre[u-2]+A[u];
    }
    for(int u=1;u<=N;u++){
        if(u==1){
            dp[u]=0;
        }
        else if(u==2){
            dp[u]=max(A[u],A[u-1]);
        }
        else if(u&1){
            dp[u]=max(dp[u-1],dp[u-2]+A[u]);
        }
        else {
            dp[u]=max(dp[u-2]+A[u],opre[u-1]);
        }
    }
    cout<<dp[N];
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}