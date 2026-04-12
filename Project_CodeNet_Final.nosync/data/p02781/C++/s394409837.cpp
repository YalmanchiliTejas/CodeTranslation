#include "bits/stdc++.h"
using namespace std;
#define all(v) (v).begin(), (v).end()
#define io ios::sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rson rt << 1 | 1, mid + 1, r
#define lson rt << 1, l, mid
#define lll __int128
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
const int mod = 1e9 + 7;
inline int ksm(int a, int b)
{
	int ans = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1)
			ans = ans * a % mod;
	return ans;
}
int dp[200][22];int n,k;
int a[2000],top;
int dfs(int d,int lim,int s){
	if(d<1)return s==k;
	if(!lim && ~dp[d][s])return dp[d][s];
	int up=9;if(lim)up=a[d];
	int res=0;
//	cout<<d<<" "<<lim<<" "<<s<<endl;
	rep(i,0,up){
		if(s + (i>0)<=k)
		res += dfs(d-1,lim&&i==up,s+(i>0));
	}
//	cout<<d<<" "<<lim<<" "<<s<<" "<<res<<endl;
	return dp[d][s] = res;
}
signed main()
{
	memset(dp,-1,sizeof dp);
	string s;cin>>s;
	cin>>k;
	int top=s.size();
	rep(i,1,top){
		a[i] = s[top-i+1-1]-'0';
	}
	//rep(i,1,top)cout<<a[i]<<" ";cout<<endl;
//
//	cout<<top<<endl;

	cout<<dfs(top,1,0)<<endl;
	getchar(); //
	getchar();
}
