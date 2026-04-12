#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define eps 0.000001
#define ll long long
#define INF 1e18
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define uint unsigned int

const int mod = 1000000000+7;
const int N = 10000+5;
string s;

ll dp[2][100][N];
ll pw[N];

main()
{ 
	SPEED;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int d;
	cin >> s;
	cin >> d;
	dp[0][0][0] = 1;
	dp[1][0][0] = 1;
	for(int i = 1 ; i <=s.size(); i++)
	{
		for(int j = 0; j<d; j++)
		{
			int num = s[s.size()-i]-'0';
			for(int k = 0; k<num; k++)
			{
				dp[0][j][i] += dp[1][(j+k)%d][i-1];
			}
			dp[0][j][i] += dp[0][(j+num)%d][i-1];
			for(int k = 0; k<10; k++){
				dp[1][j][i] += dp[1][(j+k)%d][i-1];
			}
			dp[0][j][i] %= mod;
			dp[1][j][i] %= mod;
		}
	}
	cout <<(dp[0][0][s.size()]+mod-1)%mod << endl;
}