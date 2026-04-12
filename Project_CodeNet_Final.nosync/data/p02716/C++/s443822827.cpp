
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define SZ(x) ((int)(x).size())
#define MEM(x,a) memset(x,a,sizeof(x))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const ll mod=1000000007,N=1e5+5,M=1e5+5,INF=0x3f3f3f3f;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head

int main(void){
    int n;
    cin>>n;
    VI a(n+1);
    VL dp(n+1),sum(n+1);
    rep(i,1,n+1){
        cin>>a[i];
    }
    sum[1]=a[1];
    rep(i,2,n+1)sum[i]=a[i]+sum[i-2];
    rep(i,2,n+1){
        if(i&1)dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else dp[i]=max(a[i]+dp[i-2],sum[i-1]);
    }
    cout<<dp[n];
    return 0;
}
