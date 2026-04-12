#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define pii pair<int,int>
using namespace std;
const int maxn = 200100;
ll dp[maxn][2][2];
ll arr[maxn], n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
	}

	dp[2][0][0] = arr[1];
	dp[2][1][0] = arr[2];

	dp[2][0][1] = 0LL;

	for(int i=4;i<=n;i+=2) {
		dp[i][0][0] = arr[i-1] + dp[i-2][0][0];
		dp[i][1][0] = arr[i] + max(dp[i-2][0][0], dp[i-2][1][0]);

		dp[i][0][1] = arr[i-1] + dp[i-2][0][1];
		dp[i][1][1] = arr[i] + max(dp[i-2][0][1], dp[i-2][1][1]);

		dp[i][0][1] = max(dp[i][0][1], max(dp[i-2][0][0], dp[i-2][1][0]));
		dp[i][1][1] = max(dp[i][1][1], max(dp[i-2][0][0], dp[i-2][1][0]));
	}

	if(n % 2 == 0) {
		cout<<max(dp[n][0][0], dp[n][1][0])<<"\n";
		return 0;
	}

	cout<<max(max(dp[n-1][0][0], dp[n-1][1][0]), arr[n] + dp[n-1][0][1])<<"\n";
}