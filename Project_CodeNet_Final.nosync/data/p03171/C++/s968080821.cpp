// In His Name

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define gcd __gcd
#define int long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> pii;

const int MAX = 3010;
int a[MAX], dp[MAX][MAX][2];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for (int i = 0 ; i < n ; i++){
		dp[i][i][0] = a[i];
		dp[i][i][1] = - a[i];
	}
	for (int i = 1 ; i < n ; i++){
		for (int j = 0 ; j + i < n ; j++){
			dp[j][j + i][0] = max (dp[j][j + i - 1][1] + a[j + i] , dp[j + 1][j + i][1] + a[j]);
			dp[j][j + i][1] = min (dp[j][j + i - 1][0] - a[j + i] , dp[j + 1][j + i][0] - a[j]);
		}
	}
	cout << dp[0][n - 1][0];
}