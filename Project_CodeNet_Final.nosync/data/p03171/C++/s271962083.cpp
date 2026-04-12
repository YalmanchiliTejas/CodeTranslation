#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<ll> v;
//primeiro a escolher
ll dp[3005][3005];
//segundo a escolher
ll s[3005][3005];


void solve(int i, int j)
{
	if(dp[i][j] >= 0)
		return;

	if(i == j)
	{
		dp[i][j] = v[i];
		s[i][j] = 0;
		return;
	}

	solve(i+1, j);
	solve(i, j-1);


	ll t1 = v[i] + s[i+1][j];
	ll t2 = v[j] + s[i][j-1];

	if(t1 > t2)
	{
		dp[i][j] = t1;
		s[i][j] = dp[i+1][j];
	}
	else
	{
		dp[i][j] = t2;
		s[i][j] = dp[i][j-1];
	}


}


int main()
{

	cin >> n;

 	memset(dp, -1, sizeof(dp));
 
 	ll num;
 	for (int i = 0; i < n; ++i)
 	{
 		cin >> num;
 		v.push_back(num);
 	}

 
 	solve(0, n - 1);


 	cout << dp[0][n-1] - s[0][n-1] << endl;














    return 0;
}