#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 3e3+5;

int dp[N][N][2];
bool ismemo[N][N][2];
int arr[N];
int n;

int solve(int l, int r, int player) {
	if(l==r) {
		if(player==0) {
			return arr[l];
		}
		else {
			return -arr[l];
		}
	}
	if(ismemo[l][r][player]) {
		return dp[l][r][player];
	}
	ismemo[l][r][player]=1;
	if(player == 0) {
		return dp[l][r][player] = max(arr[l]+solve(l+1, r, 1), arr[r]+solve(l, r-1, 1));
	}
	return dp[l][r][player] = min(solve(l+1, r, 0)-arr[l], solve(l, r-1, 0)-arr[r]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	cout<<solve(0, n-1, 0);

	return 0;
}