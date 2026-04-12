#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
//#define MOD (ll)(998244353)
#define MOD (ll)(1e9+7)
#define INF (1e17)
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int dp[3010][3010];
int v[3010];

int dfs(int l,int r,int f){
	if(l>=r) return (f?v[l]:-v[l]);
	if(dp[l][r]!=-1) return dp[l][r];
	if(f) dp[l][r]=max(dfs(l+1,r,!f)+v[l],dfs(l,r-1,!f)+v[r]);
	else  dp[l][r]=min(dfs(l+1,r,!f)-v[l],dfs(l,r-1,!f)-v[r]);
	//cerr<<l<<" "<<r<<" "<<dp[l][r]<<"\n";
	return dp[l][r];
}

int32_t main() {
#ifdef LOCAL_TEST
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\input.in","r",stdin);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\output.out","w",stdout);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	//code...
	int n; cin>>n;
	For(i,0,n-1) For(j,0,n-1) dp[i][j]=-1;
	For(i,0,n-1) cin>>v[i];
	cout<<dfs(0,n-1,true)<<"\n";
	return 0;
}
