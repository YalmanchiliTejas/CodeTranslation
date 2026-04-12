#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<19, mod = 1e9 + 7;
int n, m, pr = 0, dp[maxn], p[maxn][2];
string s;
int corner() {
	dp[0] = 2, dp[1] = 1;
	for(int i = 2; i <= n; i++) dp[i] = (dp[i-1] + dp[i-2])%mod;
	return dp[n];
}
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
int normal() {
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(i) {
			add(p[i][0], p[i-1][0]);
			add(p[i][1], p[i-1][1]);
		}
		dp[i] = p[i][i&1];
		if(i == 1) {
			dp[i] = 1;
		}
		add(p[i+2][i&1], dp[i]);
		add(p[i+pr+2][i&1], mod - dp[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(i + pr < n || ((i+pr)&1) != (n&1)) continue;
		ans = (ans + (n-i+1)*1ll*dp[i])%mod;
	}
	return ans;
}
bool check(int msk, int f = 0) {
	if((msk&1) && ((msk>>(n-1))&1)) return 0;
	if(msk == 0) return 0;
	int prev = -1, streak = 0, i = 0;
	if(f) while(!(msk&1)) {
		msk = (msk/2);}
	for(; i < n; i++) {
		int cur = (msk>>i)&1;
		if(prev == cur) streak++;
		else {
			if(prev == 1 && streak > 1) return 0;
			if(prev == 0 && (streak > pr || (streak&1) == 0)) return 0;
			streak = 1;
		}
		//cout << i << " " << cur << " " << streak << '\n';
		prev = cur;
	}
	if(prev == 1 && streak > 1) return 0;
			if(prev == 0 && (streak > pr || (streak&1) == 0)) return 0;
	
	return true;
}
int brute() {
	int ans = 0;
	for(int i = 0; i < 1<<n; i++) {
		ans += check(i, 1);
	}
	return ans;
}
int main() {
	cin >> n >> m >> s;
	if(s[0] == 'R')
		for(auto &i : s) i ^= 'B'^'R';
	while(pr < m && s[pr] == 'B') pr++;
	if(m == pr) return cout << corner(), 0;
	pr += pr%2 == 0;
	int cur = 0;
	for(auto &i : s) {
		if(i == 'B') cur++;
		else {
			if(cur&1) pr = min(cur, pr);
			cur = 0;
		}
	}
	cout << normal();
}
