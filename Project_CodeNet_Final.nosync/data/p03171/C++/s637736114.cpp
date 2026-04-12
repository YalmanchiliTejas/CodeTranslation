// -_-
#include <bits/stdc++.h>
#define int long long
#define read(a) int a; cin >> a;
#define readarr(a, n) int a[(n) + 1] = {}; fori(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; fori(i, 1, n) {fori(j, 1, m) cin >> a[i][j];}
#define pb push_back
#define fi first
#define se second
#define rz resize
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define mod 1000000007
#define  sort1(v) sort(v.begin(), v.end()) 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair <int, int>> vpi;
 
 
signed main() 
{
 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	read(n);
	readarr(a, n);
	int dp[n+1][n+1][3];
 
	int sum[n+1];
	sum[0] = 0;
	fori(i, 1, n) sum[i] = sum[i-1]+a[i];
 
	fori(i, 1, n-1)
	{
		fori(j, 1, n-i)
		{
			int k = j+i;
			if(k-j == 1) {dp[j][k][1] = max(a[j], a[k]); dp[j][k][2] = min(a[j], a[k]);}
			else
			{
				dp[j][k][1] = max(a[j] + dp[j+1][k][2], a[k] + dp[j][k-1][2]);
				dp[j][k][2] = (sum[k] - sum[j-1]) - dp[j][k][1];
			}
		}
	}
	if(n == 1) cout << a[1];
	else 
	cout << dp[1][n][1]-dp[1][n][2];
	return 0;
}
