#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<ll> A;
vector<vector<vector<ll>>> DP;

ll solve(int start, int end, int player){
	if (start > end){
		return 0;
	}
	
	ll &dp = DP.at(start).at(end).at(player);
	if (dp != -1){
		return dp;
	}

	if (player == 1){
		ll ans1 = solve(start + 1, end, 2) + A.at(start);
		ll ans2 = solve(start, end - 1, 2) + A.at(end);
		return (dp = max(ans1, ans2));
	} else if (player == 2){
		ll ans1 = solve(start + 1, end, 2) + A.at(start);
		ll ans2 = solve(start, end - 1, 2) + A.at(end);
		return (dp = -max(ans1, ans2));
	}
	exit(2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	A = vector<ll>(n);
	for (ll &a: A) cin >> a;
	DP = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(3, -1)));
	ll ans = solve(0, n - 1, 1);
	cout << ans;
	
	return 0;
}
