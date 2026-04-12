#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 105;
const ll LINF = 1e18 + 5;
int k;
string s;
ll dp[N][2][4];
ll dfs(int pos, int limit, int state) 
{
	if(pos==-1) return !state;
	if(~dp[pos][limit][state]) return dp[pos][limit][state];
	int up = limit ? s[pos]-'0' : 9;
	ll ans = 0;
	for(int i=0;i<=up;i++)
	{
		if(i&&state) ans += dfs(pos-1, limit&&i==s[pos]-'0', state-1);
		else if(i==0) ans += dfs(pos-1, limit&&i==s[pos]-'0', state);
	}
	return dp[pos][limit][state] = ans;	
}
ll solve() 
{
	memset(dp, -1, sizeof(dp)); 
	reverse(all(s));
	int pos = sz(s);
	return dfs(pos-1, 1, k);
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> s >> k;
 	cout << solve();
	return 0;
}
