#include<bits/stdc++.h>

using namespace std;

#define sp << " " <<

long long dp[10000][100][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int d;
    cin >> s >> d;
	for(int i=0;i<s[0]-'0';i++)
    {
		dp[0][i%d][0]++;
	}
	dp[0][(s[0]-'0')%d][1]=1;
	for(int i=1;i<s.length();i++)
    {
		for(int k=0;k<10;k++)
		{
			for(int j=0;j<d;j++)
			{
				dp[i][(j+k)%d][0]+=dp[i-1][j][0];
				dp[i][(j+k)%d][0]%=1000000007;
				if(k<s[i]-'0')
				{
					dp[i][(j+k)%d][0]+=dp[i-1][j][1];
					dp[i][(j+k)%d][0]%=1000000007;
				}
				if(k==s[i]-'0')
				{
					dp[i][(j+k)%d][1]+=dp[i-1][j][1];
					dp[i][(j+k)%d][1]%=1000000007;
				}
			}
		}
	}
	cout << (dp[s.length()-1][0][0]+dp[s.length()-1][0][1]-1+1000000007)%1000000007;
    return 0;
}
