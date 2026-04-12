#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[200010][3],n,a[200005];
int maxi=1e17;
int dfs(int p,int f){
	if(p>n||(p==n&&f==2))RE 0;
	if(dp[p][f]!=-maxi)RE dp[p][f];
	int re=-maxi;
	FOR(i,2,2+f){
		gmax(re,dfs(p+i,f+2-i));
	}
	re=re+a[p];
	RE dp[p][f]=re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int ans=-1e17;
	FOR(i,0,n+5)FOR(j,0,2)dp[i][j]=-maxi;
	if(n&1){
		FOR(i,0,2){
			gmax(ans,dfs(i+1,2-i));
		}
	}else{
		FOR(i,0,1){
			gmax(ans,dfs(i+1,1-i));
		}
	}
	cout<<ans<<'\n';
	RE 0;
}


