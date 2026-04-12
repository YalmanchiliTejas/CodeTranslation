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
const int MAXN=3010;
const ll MOD=998244353;
int N,S;
int A[MAXN];
ll cnt[MAXN];
ll pre[MAXN][MAXN];
void read()
{
    cin>>N>>S;
    for(int u=1;u<=N;u++)cin>>A[u];
}
void solve()
{
    read();
    ll ans=0;
    for(int u=1;u<=N;u++){
        if(A[u]>S)continue;
        if(A[u]==S){
            ans=(ans+(ll)u*(N-u+1)%MOD)%MOD;
            continue;
        }
        ans=(ans+cnt[S-A[u]]*(N-u+1)%MOD)%MOD;
        for(int v=S;v>=A[u];v--){
            cnt[v]=(cnt[v]+cnt[v-A[u]])%MOD;
        }
        cnt[A[u]]=(cnt[A[u]]+u)%MOD;
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}