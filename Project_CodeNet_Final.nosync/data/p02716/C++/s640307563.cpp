#include <bits/stdc++.h>
using namespace std;
long long dp[200200][2][4];
int vis[200200][2][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	const long long inf = 1ll<<60;
	function<long long(int,int,int)> solve = [&](int p, int last, int q){
		if(q > 3) return -inf;
		if(q < 0) return -inf;
		int selec = (p + 1) / 2 - q;
		if(p == n){
			if(selec == (p / 2)) return 0ll;
			return -inf;
		}
		if(vis[p][last][q]) return dp[p][last][q];
		vis[p][last][q] = 1;
		if(last){
			return  dp[p][last][q] = solve(p + 1, 0, (p + 2) / 2 - selec);
		}
		long long ans = solve(p + 1, 0, (p + 2) / 2 - selec);
		ans = max(ans, solve(p + 1, 1, (p + 2) / 2 - selec - 1) + a[p]);
		return dp[p][last][q] = ans;
	};
	cout << solve(0, 0, 0) << endl;
	return 0;
}
