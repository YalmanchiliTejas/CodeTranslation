#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
int d;

int dp[10001][101][2];
int pwr[10001] = {1};

signed main()
{
	
 	FLASH

 	cin>>s>>d;
 	fr(i,1,10001) pwr[i] = (10*pwr[i -1])%d;

 	int l = s.size();
 	reverse(s.begin(), s.end());

 	dp[0][0][0] = dp[0][0][1] = 1;
 	
 	fr(i,1,l + 1)
 	{
 		int dig = s[i-1] - '0';
 		fr(j,0,d)
 		{
 			fr(k,0,dig)
 			{
 				dp[i][j][0] += dp[i-1][(j - k + mod*d)%d][1];
 				dp[i][j][0] %= mod;
 			}

 			dp[i][j][0] += dp[i - 1][(j - dig + mod*d)%d][0];
 			dp[i][j][0] %= mod;
 			
 			fr(k,0,10)
 			{
 				dp[i][j][1] += dp[i - 1][(j - k + mod*d)%d][1];
 				dp[i][j][1] %= mod;
 			}
 		}
 	}
 	int ans = (dp[l][0][0] - 1 + mod)%mod;
 	while(ans >= mod) ans -= mod;
 	while(ans < 0) ans += mod;

 	cout<<ans<<'\n';
}
