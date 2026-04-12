#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> pii;
const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll inf = 1e18;
const ll mod = 1000000007;
char s[maxn]; int n;
int k;
int ena;
ll dp[110][4][2];
ll dfs(int dep, int k) {
	if (n - dep + 1 < k)return 0;
	if (dep == n) {
		if (k == 0) {
			return 1;
		}
		else {
			if (ena)return 9;
			else return s[n] - '0';
		}
	}
	if (k == 0)return 1;
	if (dp[dep][k][ena] != -1)return dp[dep][k][ena];
	ll res = 0;
	if (ena) {
		res = 9*dfs(dep + 1, k - 1) % mod;
		res = (res + dfs(dep + 1, k)) % mod;
	}
	else {
		if (s[dep] - '0' > 0) {
			ena = 1;
			res = (s[dep] - '0' - 1)*dfs(dep + 1, k - 1) % mod;
			res = (res + dfs(dep + 1, k)) % mod;
			ena = 0;
			res = (res + dfs(dep + 1, k - 1)) % mod;
		}
		else {
			res = dfs(dep + 1, k) % mod;
		}
	}
	return dp[dep][k][ena] = res;
}
int main() {
	scanf("%s", s + 1);
	cin >> k;
	n = (int)strlen(s + 1);
	memset(dp, -1, sizeof(dp));
	ena = 0;
	cout << dfs(1, k) << endl;
	return 0;
};