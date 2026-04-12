#include<bits/stdc++.h>
#define ll long long int
#define inf 1000000000000
#define MOD 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define for0(i, n) for (int i = 0; i < n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define ps(x,y)         fixed<<setprecision(y)<<x
using namespace std;
int main()
{
	IOS
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	int n;
	cin >> n;
	ll arr[n];
	ll dp[n][n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int l = n - 1; l >= 0; l--)
	{
		for (int r = l; r < n; r++)
		{
			if (r == l)
				dp[l][r] = arr[l];
			else
				dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
		}
	}
	cout << dp[0][n - 1] << endl;
}