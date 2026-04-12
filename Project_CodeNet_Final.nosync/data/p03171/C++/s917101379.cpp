#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n;
long long dp[3007][3007], a[3007];
bool vis[3007][3007];

long long solve(int l, int r, int turn){
	if(vis[l][r]) return dp[l][r];
	vis[l][r] = true;
	if(l == r){
		if(turn == 0) dp[l][r] = a[l];
		else dp[l][r] = -a[l];
		return dp[l][r];
	}
	long long ans = 0, nxt = turn ^ 1;
	if(turn == 0) ans = max(solve(l + 1, r, nxt) + a[l], solve(l, r - 1, nxt) + a[r]);
	else ans = min(solve(l + 1, r, nxt) - a[l], solve(l, r - 1, nxt) - a[r]);
	dp[l][r] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << solve(1, n, 0);
}
