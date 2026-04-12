#include<bits/stdc++.h>
int d, dp[10005][2][105];
std::string s;

int dp_solve(int idx, bool lim, int mod) {
	if(idx == (int) s.size()) return (int) mod == 0;
	int &ans = dp[idx][lim][mod];
	if(~ans) return ans;
	ans = 0;
	for(int i = 0; i <= (lim ? 9 : s[idx] - '0'); i++) ans = (ans + dp_solve(idx+1, lim || i < s[idx] - '0', (mod + i) % d)) % 1000000007;
	return ans;
}

int main() {
	std::cin >> s >> d;
	memset(dp, -1, sizeof dp);
	std::cout << (dp_solve(0, 0, 0) - 1 + 1000000007) % 1000000007 << '\n';
	return 0;
}
