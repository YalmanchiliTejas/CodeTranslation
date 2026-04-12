#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#include<iomanip>
#define BUG puts("no bug")
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define ll long long
#define ull unsigned long long
#define REP(a,b,c) for(ll a=b;a<=c;a++)
#define PER(a,b,c) for(ll a=b;a>=c;a--)
#define lb(a) (a&(-a))
#define pp (p<<1)
#define ppp (p<<1|1)
#define pi pair<ll,ll>
#define pii pair<pair<ll,ll>,ll>
using namespace std;
const ll MAXN=1e6+5;
ll n,m,t;
ll ans;
ll v[MAXN];
ll dp[MAXN];
ll mod=998244353;
int main(){
    cin>>n>>m;
    REP(i,1,n)cin>>v[i];
    REP(i,1,n){
        PER(j,m,v[i])dp[j]=(dp[j]+dp[j-v[i]])%mod;
        dp[v[i]]=(dp[v[i]]+i)%mod;
        ans=(ans+(dp[m])*(n-i+1)%mod)%mod;
        dp[m]=0;
    }
    cout<<ans;
}