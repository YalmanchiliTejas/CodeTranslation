#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
	ll a,b,c,d;
	cin >>  a ;
	vector<ll> v;
	for(ll i=0;i<a;i++)
	{
		cin >> b;
		v.push_back(b);
	}
	
	ll dp[a][a];
	dp[a-1][a-1]=v[a-1];
	
	for(ll i=a-1;i>=0;--i)
	{
		for(ll j=i;j<a;j++)
		{
			if(i==j)
			{
				dp[i][j]=v[i];
			}
			else
			dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
		}
	}
	cout << dp[0][a-1];
}