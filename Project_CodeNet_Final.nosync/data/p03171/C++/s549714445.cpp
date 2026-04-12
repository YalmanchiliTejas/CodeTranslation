#include <bits/stdc++.h>
#define N 3010
#define pb push_back
#define fi first
#define se second
#define si size()
#define ll long long
#define mp make_pair
#define iter ::iterator
#define all(v) v.begin(), v.end()
#define pp pop_back
#define mapiter map<int, int>::iterator
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forn1(i, n) for(int i = 1; i <= n; ++i)
#define forr(i, n)	for(int i = n - 1; i >= 0; --i)
#define forr1(i, n)	for(int i = n; i >= 1; --i)
#define form(l, r, i)	for(int i = l; i <= r; ++i)
#define forv(r, l, i)	for(int i = r; i >= l; --i)
#define r0 return 0
#define barnarnar ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lld long double
#define elif else if
 
const int inf = 1e9 + 7;
const lld EPS = 0.00000001;
const ll modw = 998244353ll;

using namespace std;

ll dp[N][N];
ll a[N];

int main()
{
	barnarnar
	int n;
	cin >> n;
	forn1(i, n)	cin >> a[i];
	for(int l = n; l >= 1; l--)
	{
		for(int r = l; r <= n; r++)
		{
			dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	cout << dp[1][n];
	return 0;
}



