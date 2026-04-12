#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef double db;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) (int)(x.size())
#define sci(x) scanf("%d",&(x))
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define syn ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
ll modpow(ll x,ll n,ll mod){ll res=1;for(;n;n>>=1,x=x*x%mod)if(n&1)res=res*x%mod;return res;}
const db eps=1e-8,PI=acos(-1.0);
const int N=2e5+10,M=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;//998244353
int n;
ll a[N],dp[N][2];
int main(){
	sci(n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
		if(i&1){
			dp[i][0]=max((i-2<0?0:dp[i-2][0])+a[i],dp[i-1][1]);
			dp[i][1]=(i-2<0?0:dp[i-2][1])+a[i];
		}
		else{
			dp[i][0]=max(dp[i-2][0]+a[i],dp[i-1][0]);
			dp[i][1]=max(dp[i-2][1]+a[i],dp[i-1][1]);
		}
	}
	if(n&1)printf("%lld\n",dp[n][0]);
	else printf("%lld\n",dp[n][1]);
    return 0;
}