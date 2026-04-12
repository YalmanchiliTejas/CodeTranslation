#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
#define pb push_back
#define ft(i) (i&(-1*i))
#define arrIn(arr,size)		for(int i=0;i<size;i++){cin>>arr[i];}
#define arrOut(arr,size,seperater)	for(int i=0;i<size;i++){cout<<arr[i]<<seperater;}
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int n;
int arr[3005];
int dp[3005][3005];

int solve(int l, int r) {

	if (r - l <= 1) {
		return max(arr[l], arr[r]);
	}

	if (dp[l][r] != -1)	return dp[l][r];

	int ans;

	ans = max((arr[l] + min(solve(l + 2, r), solve(l + 1, r - 1))), (arr[r] + min(solve(l + 1, r - 1), solve(l, r - 2))));
	dp[l][r] = ans;
	return ans;
}

int32_t main() {

	fastIO();
	fo(i, 0, 3001, 1) {
		fo(j, 0, 3001, 1)
		dp[i][j] = -1;
	}
	cin >> n;
	arrIn(arr, n);
	int sum = 0;
	fo(i, 0, n, 1)	sum += arr[i];
	// cout << solve(0, n - 1) << endl;
	cout << 2 * solve(0, n - 1) - sum;

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;