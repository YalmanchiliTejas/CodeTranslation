#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0; i<n; ++i) cin >> A[i];
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));
	vector<int> psum(n+1);
	for (int i=0; i<n; ++i){
		psum[i+1] += A[i];
		psum[i+1] += psum[i];
		dp[i][i] = {A[i],0};
	}
	vector<tuple<int,int,int>> order;
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			order.emplace_back(j-i+1,i,j);
		}
	}
	sort(order.begin(),order.end());
	for (auto i:order){
		int a,b,c;
		tie(c,a,b) = i;
		dp[a][b].first = max(dp[a+1][b].second+A[a],dp[a][b-1].second+A[b]);
		dp[a][b].second = psum[b+1] - psum[a] - dp[a][b].first;
	}
/*	for (auto i:dp){
		for (auto j:i) cout << j.first << ' ';
		cout << '\n';
	}
*/	cout << dp[0][n-1].first-dp[0][n-1].second;
	return 0;
}