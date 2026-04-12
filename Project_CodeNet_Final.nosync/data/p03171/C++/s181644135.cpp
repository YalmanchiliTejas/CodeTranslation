
//													\[T]/ Praise
//													 (*)  The
//													 / \  Sun



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double dbl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<long long> vl;
typedef vector< pair<int, int> > vii;
#define mp make_pair
#define pb push_back
#define invec(a, n) for(ll i = 0; i < n; i++) {cin >> a[i];}
#define rep(n) for(ll i = 0; i < n; i++)
#define fr(i,j,k) for(ll i = j; i < k; i++)
#define FR(i,j,k) for(ll i = j; i >= 0; i--)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define INF 1e18
#define xx first
#define yy second

void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
ll dp[3000][3000];
vl a;

ll rec(int l, int r, int turn)
{
	if(dp[l][r] != INF)
		return dp[l][r];

	// printf("%d %d %d\n", l, r, turn);

	if(l == r)
	{
		if(turn)
			dp[l][r] = a[l];
		else
			dp[l][r] = -a[l];
		return dp[l][r];
	}

	ll x = rec(l+1, r, turn^1);
	ll y = rec(l, r-1, turn^1);

	if(turn)
	{
		dp[l][r] = max(x + a[l], y + a[r]);
		return dp[l][r];
	}
	else
	{
		dp[l][r] = min(x - a[l], y - a[r]);
		return dp[l][r];
	}
}

int main()
{
	cin >> n;
	a.resize(n,0);

	invec(a,n);

	fr(i,0,n)
		fr(j,0,n)
			dp[i][j] = INF;

	rec(0,n-1,1);

	// fr(i,0,n)
	// {
	// 	fr(j,0,i)
	// 		cout << "\t\t";
	// 	fr(j,i,n)
	// 		cout << dp[i][j] << "\t\t";
	// 	cout << "\n";
	// }

	cout << dp[0][n-1];
}