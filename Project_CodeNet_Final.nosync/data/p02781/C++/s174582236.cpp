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
int dp[101][2][4];
bool vis[101][2][4];
string n;
int k;
int dfs(int ind, int small, int cur){
	if(ind>sz(n)){
		if(cur==0) return 1;
		else return 0;
	}
	if(vis[ind][small][cur]) return dp[ind][small][cur];
	int ans = 0;
	if(small==0){
		if(n[ind-1]-'0'!=0) ans = (ans+dfs(ind+1,1,cur));
		else ans = dfs(ind+1,0,cur);
		// trace(ind,small,cur,ans);
		if(cur>0) if(n[ind-1]-'0'!=0) ans = (ans+(n[ind-1]-'0'-1)*dfs(ind+1,1,cur-1));
		// trace(ind,small,cur,ans);
		if(cur>0) if(n[ind-1]-'0'!=0) ans += dfs(ind+1,0,cur-1);
		// trace(ind,small,cur,ans);
	}
	else{
		// trace(ind,small,cur,ans);
		ans = (ans+dfs(ind+1,1,cur));
		// trace(ind,small,cur,ans);
		if(cur>0) ans += 9*dfs(ind+1,1,cur-1);
		// trace(ind,small,cur,ans);
	}
	// trace(ind,small,cur,ans);
	vis[ind][small][cur] = 1;
	dp[ind][small][cur] = ans;
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	int TESTS=1;
	// cin>>TESTS;
	while(TESTS--)
	{   
		cin >> n;
		cin >> k;
		dfs(1,0,k);
		int ans = dp[1][0][k];
		int cnt = 0;
		// rep(i,0,sz(n)) if(n[i]!='0') cnt++;
		// if(cnt==k) ans++;
		cout<<ans;
	}
}