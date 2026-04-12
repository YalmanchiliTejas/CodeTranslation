#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

ll n, a[3005], dp[3005][3005];

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];	
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			if (i == j)	dp[i][j] = a[i];
			else dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}
	}
	cout << dp[0][n-1];
	return 0;
}
