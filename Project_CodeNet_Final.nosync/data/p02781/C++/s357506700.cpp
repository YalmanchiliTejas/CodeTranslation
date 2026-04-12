#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

vector<vector<vector<ll>>> memo(1005, vector<vector<ll>>(4, vector<ll>(2, -1)));
string s;
ll dp(int i, int k, bool p){
	if(i >= s.size() && k == 0)
		return 1;
	if(i >= s.size())
		return 0;
	if(k == 0)
		return 1;
	if(memo[i][k][p] != -1)
		return memo[i][k][p];
	memo[i][k][p] = 0;
	memo[i][k][p] += dp(i+1, k, p && s[i] == '0');
	if(p){
		for(int j= 1; j +'0'< s[i]; j++)
			memo[i][k][p] += dp(i+1, k-1, 0);
		if(s[i] != '0')
		memo[i][k][p] += dp(i+1, k-1, 1);
	}else{
		for(int j = 1; j < 10; j++)
			memo[i][k][p] += dp(i+1, k-1, 0);
	}
	
	return memo[i][k][p];
}

signed main() { 
	cin.tie(0);
	cin.sync_with_stdio();
	cin>>s;
	int k;
	cin>>k;
	cout<<dp(0, k, 1);
}
