#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, dp[10001][2][101], mod = 1000000007;
vector<int> v;

LL solve(int pos, bool f1, int sum) {
	sum %= m;
	if(pos == v.size()) return sum == 0;
	LL &ret = dp[pos][f1][sum];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < 10; i++) {
		if(f1) ret += solve(pos+1, 1, sum + i);
		else {
			if(i == v[pos]) ret += solve(pos+1, 0, sum + i);
			else if(i < v[pos]) ret += solve(pos+1, 1, sum + i);
		}
		ret %= mod;
	}
	return ret;
}

int main() {
	string s;
	memset(dp, -1, sizeof(dp));
	cin>>s>>m;
	for(char c : s) v.push_back(c-'0');
	LL ans = solve(0, 0, 0);
	ans = (ans - 1 + mod) % mod;
	cout<<ans<<endl;
	return 0;
}
