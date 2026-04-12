#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define jmp cout<<"\n"
#define vl vector<ull>
#define vi vector<int>
#define vvl vector<vl>
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define printv(v) for(auto x:v) cout<<x<<" "; jmp;
#define endll "\n"
#define SORT(v) sort(v.begin(),v.end())
#define REV(x)  reverse(x.begin(),x.end())
#define UNI(a) a.erase( unique( a.begin(), a.end() ), a.end() )
#define all(a) a.begin(), a.end()
#define si(x) x.size()
#define ff first
#define ss second
#define iin insert
using namespace std;

ll dp[3005][3005];
ll maxAmount(ll l, ll r, ll a[])

{
	if (l > r)
		return 0;
	if (l == r)
		return a[l];
	if (dp[l][r] != -1)
		return dp[l][r];
	else
		return dp[l][r] = max((a[l] - maxAmount(l + 1, r, a)), (a[r] - maxAmount(l, r - 1, a)));
}
void solve()
{

	ll n, k;
	cin >> n ;
	ll a[n];
	for (ull i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	// for (ll i = n - 1; i >= 0; i--)
	// {
	// 	for (ll j = i; j < n; j++)
	// 	{
	// 		if (i == j)
	// 			dp[i][j] = a[i];
	// 		else
	// 			dp[i][j] = max((a[i] - dp[i + 1][j]), ( a[j] - dp[i][j - 1]));
	// 	}
	// }

	cout << maxAmount(0, n - 1, a) << endll;
}
signed main()
{

	fast;
	solve();
	return 0;
}
