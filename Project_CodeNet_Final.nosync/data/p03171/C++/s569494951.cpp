/////////////////////////////////TEST CASES////////////////////////////////////
/*
*/
/////////////////////////////////////CODE//////////////////////////////////////		
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define vl vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define FR(i,a) for(auto i:a)
#define what(A) cout<<#A<<" is "<<A<<endl;
ll dp[3005][3005][2];
void solve()
{
	IN(n);
	vl v;
	FOR(i, 0, n)
	{
		IN(in);
		v.push_back(in);
	}
	FOR(i, 0, n) dp[i][i][0] = v[i];
	FOR(i, 1, n)
	{
		FOR(j, 0, n)
		{
			if (j + i < n)
			{
			//	cout << j << " " <<i+ j<<endl;
				if (v[j + i] + dp[j][j+i-1][1] > v[j] + dp[j + 1][j + i][1])
				{
					dp[j][j + i][0] = v[j + i] + dp[j][j+i-1][1];
					dp[j][j + i][1] = dp[j][j+i-1][0];
				}
				else
				{
					dp[j][j + i][0] = v[j] + dp[j+1][j+i][1];
					dp[j][j + i][1] = dp[j+1][j+i][0];
				}
				//what(dp[j][j+i][0])
					//what(dp[j][j+i][1])
			}
		}
	}
	cout << dp[0][n-1][0] - dp[0][n-1][1];
}
int main()
{
	fastio
		//freopen("input.txt", "rt", stdin);
		//freopen("output.txt", "wt", stdout);
		ll test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}