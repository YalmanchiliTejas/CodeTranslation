#include <bits/stdc++.h>                       
#include <stdio.h>

#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
                                           	
const int N = 5e5 + 123, M = 3e3 + 123, inf = 1e9 + 123, mod = 1e9 + 7;
const ll INF = 1e18;

ll dp[3][M][M];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int l = 1; l + i - 1 <= n; l++) {
			int r = l + i - 1;
			dp[1][l][r] = max(dp[2][l + 1][r] + a[l], dp[2][l][r - 1] + a[r]);
			dp[2][l][r] = min(dp[1][l + 1][r] - a[l], dp[1][l][r - 1] - a[r]);
		}   	
	}
	cout << dp[1][1][n];
	return 0;   	
}                                                         