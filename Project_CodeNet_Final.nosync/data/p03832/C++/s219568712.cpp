#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
ll dp[1005][1005];
int n,a,b,c,d;
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[100005],R[100005];
void make(){
	F[0] = 1;
	for(int i=1;i<100005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<100005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	cin>>n>>a>>b>>c>>d; make();
	dp[0][a-1] = 1;
	for(int i=a;i<=b;i++){
		for(int j=0;j<=n;j++){
			if(dp[j][i-1] == 0) continue;
			dp[j][i] += dp[j][i-1];
			while(dp[j][i]>=mod) dp[j][i]-=mod;
			ll hoge = 1;
			for(int k=1;k<=d;k++){
				if(j+i*k > n) break;
				hoge *= C(n-j-i*(k-1),i); hoge%=mod;
				hoge *= modpow(k,mod-2); hoge%=mod;
				if(k>=c){
    				dp[j+i*k][i] += dp[j][i-1]*hoge%mod;
    				while(dp[j+i*k][i]>=mod) dp[j+i*k][i]-=mod;
				}
				//cout<<j+i*k<<" "<<i<<endl;
				//cout<<dp[j+i*k][i]<<endl;
			}
		}
	}
	cout<<dp[n][b]<<endl;
}