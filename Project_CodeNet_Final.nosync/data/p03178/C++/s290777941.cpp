#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n;
string s;
ll d[10010][110];
ll dp[10010][110][2];
ll md=1e9+7;
ll res=0;
int main()
{
	cin >>s>>n;
	for (int i=0;i<s.size();i++) s[i]-='0';
	reverse(s.begin(),s.end());
	for (int i=0;i<10;i++) d[0][i%n]++;
	for (int i=1;i<s.size()-1;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<10;k++)
			{
				int it=j-k;
				while (it<0) it+=n;
				d[i][j]=(d[i][j]+d[i-1][it])%md;
			}
		}
	}
	if (s.size()>1) res=d[s.size()-2][0]-1;
	for (int i=1;i<s[s.size()-1];i++) dp[s.size()-1][i%n][0]++;
	dp[s.size()-1][s[s.size()-1]%n][1]++;
	for (int i=s.size()-2;i>=0;i--)
	{
		for (int j=0;j<n;j++)
		{
			//cout <<i<<" "<<j<<" ###############\n";
			for (int k=0;k<10;k++)
			{
				int it=j-k;
				while (it<0) it+=n;
				dp[i][j][0]=(dp[i][j][0]+dp[i+1][it][0])%md;
				if (k==s[i]) dp[i][j][1]=(dp[i][j][1]+dp[i+1][it][1])%md;
				if (k<s[i]) dp[i][j][0]=(dp[i][j][0]+dp[i+1][it][1])%md;
				//cout <<k<<" "<<(int)s[i]<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" ##\n"; 
			}
		}
	}
	res=(res+dp[0][0][0]+dp[0][0][1])%md;
	cout <<res;
	return 0;
} 