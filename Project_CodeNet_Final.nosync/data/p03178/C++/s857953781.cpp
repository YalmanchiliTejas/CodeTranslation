#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int d, ile;
long long int dp[10010][110][14], wynik;
string k;
int main()
{
	cin >> k;
	scanf("%d", &d);
	for (int i=0; i<=9; i++)
	{
		dp[1][i%d][i]=1;
	}
	for (int i=1; i<=(int)k.size(); i++)
	{
		for (int j=0; j<d; j++)
		{
			for (int o=0; o<=8; o++)
			{
				dp[i][j][o+1]=(dp[i][j][o+1]+dp[i][j][o])%M;
			}
			for (int o=0; o<=9; o++)
			{
				dp[i+1][(j+o)%d][o]=(dp[i+1][(j+o)%d][o]+dp[i][j][9])%M;
			}
		}
	}
	int dl=(int)k.size();
	for (int i=0; i<(int)k.size(); i++)
	{
		if (k[i]=='0' && dl!=1) 
		{
			dl--;
			continue;
		}
		if (dl!=1)
		{
			wynik=(wynik+dp[dl][ile][k[i]-'0'-1])%M;
			//printf("[%d][%d][%d]\n", dl, ile, k[i]-'0'-1);
		}
		if (dl==1)
		{
			wynik=(wynik+dp[dl][ile][k[i]-'0'])%M;
			//printf("[%d][%d][%d]\n", dl, ile, k[i]-'0');
		}
		dl--;
		ile=(ile+((k[i]-'0')/d+1)*d-k[i]+'0')%d;
	}
	wynik=(wynik+M-1)%M;
	printf("%lld", wynik);
}
