#include <bits/stdc++.h>

using namespace std;

int k=0,res=0;
string n="";
int dp[101][4][2];

int main()
{
	cin >> n >> k;	
	dp[0][0][0] = 1;
	for (int i=0; i<n.size(); i++)	
	{
		int x = (n[i]-'0');
		for (int j=0; j<4; j++)
		{
			for (int s=0; s<2; s++)
			for (int l=0; l<10; l++)
			{
				int ni=i+1,nj=j, ns=s;
				if (l!=0)
					nj++;	
				if (nj>k)
					continue;
				if (ns==0)
				{
					if (l>x)
						continue;
					if (l<x)
						ns = 1;
				}
				dp[ni][nj][ns]+=dp[i][j][s];
			}
		}
	}
	cout << dp[n.size()][k][0]+dp[n.size()][k][1];
	return 0;
}
