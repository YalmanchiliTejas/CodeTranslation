#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define U 998244353
#define N 1000005
#define int long long
#define sz(c) (int)c.size()
#define fr first
#define ll long long 
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define r0 return 0;
#define endl '\n'
#define INF (int)1e15
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
bool vis[10001][100][2];
int dp[10001][100][2];
string k;
int d;
int dfs(int i, int small, int rem){
	if(i>sz(k)){
		if(rem==0) return 1;
		else return 0;
	}
	if(vis[i][rem][small]) return dp[i][rem][small];
	vis[i][rem][small] = 1;
	int ans = 0;
	if(small==0){
		rep(j,0,k[i-1]-'0') ans = (ans+dfs(i+1,1,(rem+j)%d))%M;
		ans = (ans+dfs(i+1,0,(rem+k[i-1]-'0')%d))%M;
	}
	else{
		rep(j,0,10) ans = (ans+dfs(i+1,1,(rem+j)%d))%M;
	}
	dp[i][rem][small] = ans;
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	int TESTS=1;
	// cin>>TESTS;
	while(TESTS--)
	{   
		cin >> k >> d;
		cout<<(M+dfs(1,0,0)-1)%M;
	}
}