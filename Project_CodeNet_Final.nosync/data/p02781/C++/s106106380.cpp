#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 7;
int dig[N];
int dp[150][150][2], k;

int dfs(int pos, int num, bool ismax){
	if(pos == 0) return num == k;
	int &v = dp[pos][num][ismax];
	if(v != -1) return v;
	v = 0;
	int mx = ismax ? dig[pos] : 9;
	for(int i = 0; i <= mx; ++ i){
		if(i) v += dfs(pos - 1, num + 1, ismax && i == mx);
		else v += dfs(pos - 1, num, ismax && i == mx);
	}
	return v;
}

int solve(string &s){
	memset(dp, -1, sizeof dp);
	int len = 0;
	for(int i = s.size() - 1; ~i; -- i){
		dig[++ len] = s[i] - '0';
	}
	return dfs(len, 0, 1);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s; cin >> s >> k;
	cout << solve(s) << '\n';
	return 0;
}