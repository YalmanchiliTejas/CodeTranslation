#include "bits/stdc++.h"

using namespace std;

//typedef pair<int, int> P;
#define int long long
#define ll long long
#define mod 1000000007
#define INF (1LL<<60)

int N;
int a[3001];
// 手番－相手番
int dp[3001][3001];

int solve(int l, int r){
	if (dp[l][r] != 0) return dp[l][r];

	if (r - l == 1) return dp[l][r] = a[l];

	return dp[l][r]=max(-solve(l + 1,r) + a[l], -solve(l,r - 1) + a[r - 1]);
}

signed main(){

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}

	cout << solve(0, N) << endl;

	return 0;
}
