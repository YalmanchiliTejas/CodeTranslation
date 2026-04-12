#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int mod = 1e9+7;
const int maxn = 2e5+5;
ll n,m;
int dp[1005][15];
string s;
ll dfs1(ll pos,ll dep){
	if(dep==0) return 1;
	if(pos==s.length()) return 0;
	ll ans = 0;
	ans+=dfs1(pos+1,dep);
	ans%=mod;
	ans+=(9*dfs1(pos+1,dep-1)%mod);
	ans%=mod;
	return ans%mod;
}
ll dfs2(ll pos,ll dep){
	if(dep==0) return 1;
	if(pos==s.length()) return 0;
	ll ans = 0;
	if(s[pos]=='0') ans+=dfs2(pos+1,dep);
	if(s[pos]>'0')
		ans+=dfs1(pos+1,dep);
	ans%=mod;
	//cout<<ans<<endl;
	if(s[pos]>'0')
		ans+=dfs2(pos+1,dep-1);
	ans%=mod;
	if(s[pos]>'0')
		ans+=(dfs1(pos+1,dep-1)*(s[pos]-'0'-1)%mod);
	ans%=mod;
	return ans%mod;
}
int main() {
	cin>>s;
	cin>>n;
	ll ans = 0;
	ans+=dfs2(1,n-1);
	ans%=mod;
	ans+=(dfs1(1,n-1)*(s[0]-'0'-1)%mod);
	ans%=mod;
	ans+=dfs1(1,n);
	cout<<(ans+mod)%mod;
    return 0;
}

