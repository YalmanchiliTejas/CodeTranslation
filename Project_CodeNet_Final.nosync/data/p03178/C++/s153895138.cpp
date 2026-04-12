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
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int d, a[N];
char s[N];
ll dp[N][105]; 
ll dfs(int pos,int limit, int state) 
{
	if(pos==-1) return state==0;
	if(!limit&&dp[pos][state]!=-1) return dp[pos][state];
	int up = limit ? a[pos] : 9;
	ll ans = 0;
	for(int i=0;i<=up;i++)
	{
		ans = (ans + dfs(pos-1,limit&&i==a[pos], (state+i)%d))%mod;
	}
	if(!limit) dp[pos][state] = ans;
	return ans;	
}
ll solve() 
{
	memset(dp, -1, sizeof(dp));
	int pos = strlen(s);
	reverse(s, s+pos);
	for(int i=0; i<pos; i++) a[i] = s[i] - '0';
	return (dfs(pos-1, 1, 0)-1+mod)%mod;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> s >> d;
 	cout << solve();
	return 0;
}
