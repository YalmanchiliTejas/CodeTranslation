#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define frst first
#define sec second
#define fast cin.tie(0) , ios_base :: sync_with_stdio(0)
#define db double
#define mod 1000000007
void online_judge()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}

vector<ll> pyr;
void cal()
{
	for (ll h = 1; h < 100001; ++h)
	{
		ll val = (3 * h * h + h) / 2;
		pyr.pb((val));
	}
}

ll dp[4001][4001][2];
ll go_(ll a[] , ll be , ll en , ll player)
{
	if (be > en)return 0;
	ll ans = 0;
	if (dp[be][en][player] != -1e12)return dp[be][en][player];
	if (player == 0)
	{
		ans = max(go_(a , be + 1 , en , 1) + a[be] , go_(a , be , en - 1 , 1) + a[en]);
	}
	else {
		ans = min(go_(a , be + 1 , en , 0) - a[be] , - a[en] + go_(a , be , en - 1 , 0));
	}
	return dp[be][en][player] = ans;
}

void go() {
	fast;
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < 4001; ++i)for (int j = 0; j < 4001; ++j)dp[i][j][0] = dp[i][j][1] = -1e12;
	cout << go_(a , 0 , n - 1 , 0);
}


int main() {
	fast;
	//online_judge();
	//cout << 2332;
	go();
}