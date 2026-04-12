#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<map>
#include<stack>
//#include<bits/stdc++.h>		
#include<string.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define f first
#define respr(fir,sec) for(int i=0;i<=fir;i++){for(int j=0;j<=sec;j++){cout << res[i][j] << " ";}cout << "\n";}
#define pb push_back
#define vint vector<int>
const int mod = 1000000007;
using namespace std;
const int maxsize=3005;



void assignee(int &x, int ans)
{
	x += ans;
	x %= mod;
}



int32_t main()
{
	//freopen("input.txt", "r" , stdin);
	int d;	
	string s;
	cin >> s >> d;
	vector<vector<int>> dp(d,vector<int>(2));
	dp[0][0]=1;
	for(int len=0;len<(int)s.length();len++)
	{
		vector<vector<int>> n_dp(d, vector<int>(2));
		for(int sum=0;sum<d;sum++)
		{
			for(bool last_trace : {false, true})
			{
				for(int i=0;i<=9;i++)
				{
					if(i>s[len]-'0' && !last_trace)
						break;
				
				assignee(n_dp[(sum+i)%d][last_trace || i<s[len]-'0'], dp[sum][last_trace]);
				}
			}
		}
		dp =  n_dp;
	}
	int ans;
	ans = (dp[0][0]+dp[0][1])%mod;
	--ans;
	if(ans == -1)
		ans = mod-1;
	
	cout << ans <<"\n";
	return 0;
}
