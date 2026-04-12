#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


ll dp[3005][3005];
ll a[3005];

ll solve(int l, int r, int turn){
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	if (turn % 2 == 0){
		return dp[l][r] = max(solve(l + 1, r, turn + 1) + a[l], solve(l, r - 1, turn + 1) + a[r]);
	}
	else{
		return dp[l][r] = min(solve(l + 1, r, turn + 1) - a[l], solve(l, r - 1, turn + 1) - a[r]);
	}
 }

void init(){
	for (int i = 0 ; i< 3005; i++){
		for (int j = 0; j < 3005; j++)
			dp[i][j] = -1;
	}
}

int main(){
	int n; cin >> n;
	for (int i = 0; i  < n; i++) cin >> a[i];
	init();
	ll ans = solve(0, n - 1, 0);
	cout << ans << endl;
	return 0;
}
