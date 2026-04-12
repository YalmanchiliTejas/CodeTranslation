#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v)    ((v.begin()),(v.end()))
#define sz(v)     ((int)(v.size()))
#define forv(i, v) for(int i = 0; i < sz(v); ++i)
#define forn(i,n)   for(int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector< vi >    vii;
typedef vector< vd >    vdd;
typedef vector<string>  vs;


int main()
{
	int n;
	scanf("%d", &n);
	ll a[n  + 5];
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

	ll dp[n  + 4][n  + 4];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) dp[i][j] = a[i];
			else {
				dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
			}
		}
	}
	printf("%lld\n", dp[0][n - 1]);
	return 0;
}
