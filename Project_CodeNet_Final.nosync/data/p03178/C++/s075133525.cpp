#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;
string k;
int dp[10005][100][2] , d , ans;

int add(int a , int b)
{
	return ( (a%mod) + (b%mod) ) % mod;
}

int go(int pos , int sum , int pref)
{
	if(pos == (int)k.size() )return sum == 0;
		
	int &res = dp[pos][sum][pref];
	if(res != -1)
	{
		return res;
	}
	res = 0;	
	
	if(pref)
	{
		for(int i = 0; i <= (k[pos] - '0'); i++)
		{
			res = add(res , go(pos + 1 , (sum+i) % d , (i == k[pos] - '0')));
		}
	}
	else 
	{
		for(int i = 0; i <= 9; i++)
		{
			res = add(res , go(pos + 1 , (sum+i) % d , 0));
		}
	}
	return res;
}


main()
{
	memset(dp , -1 , sizeof dp);
	
	cin >> k >> d;
	
	
	for(int i = 1; i <= k.size(); i++)
	{
		if(i == 1)
		{
			for(int j = 1; j <= k[i - 1] - '0'; j++)
			{
				ans = add(ans , go(i , j % d , (j == k[i-1] - '0')));
			}
		}
		else
		{
			for(int j = 1; j <= 9; j++)
			{
				ans = add(ans , go(i , j % d , 0));
			}
		}
	}
	
	cout << ans << endl;
}
