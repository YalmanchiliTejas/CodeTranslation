#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define F first
#define S second
#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a, a);
}

ll lcm(ll a, ll b){
	return (a/gcd(a, b))*b;
}

ll n,a[3004],dp[3000][3000];

ll solve(ll i,ll j)
{
	if(dp[i][j] != -1)
		return dp[i][j];

	if(i==j)
		return dp[i][j] = a[i];

	return dp[i][j] = max(a[i] - solve(i+1,j) , a[j] - solve(i,j-1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll i;

	cin >> n;

	for(i=0;i<n;i++)
	{
		cin >> a[i+1];
	}

	memset(dp,-1,sizeof(dp));

	cout << solve(1,n) << endl;
}