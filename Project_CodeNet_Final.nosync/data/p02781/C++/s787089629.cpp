#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

const int N = 100 + 10;

int num[N];
lli f[N][4][2];

int main()
{
	int n, k, i, j;
	string s;
	cin>>s;
	cin>>k;
	n = s.size();
	for (i=1; i<=n; i++) num[i] = s[i-1] - '0';
	f[0][0][1] = 1;
	for (i=1; i<=n; i++)
	{
		if (num[i] == 0) 
		{
			f[i][0][0] = f[i-1][0][0];
			f[i][0][1] = f[i-1][0][1];
		}
		else
		{
			f[i][0][0] = f[i-1][0][0] + f[i-1][0][1];
			f[i][0][1] = 0;
		}
		for (j=1; j<=k; j++) 
		{
			f[i][j][0] = f[i-1][j-1][0] * 9 + (num[i] == 0 ? 0 : f[i-1][j-1][1] * (num[i] - 1)) + f[i-1][j][0] + (num[i] == 0 ? 0 : f[i-1][j][1]);
			if (num[i] == 0) f[i][j][1] = f[i-1][j][1]; else f[i][j][1] = f[i-1][j-1][1];
		}
//		cout<<f[i][0][0]<<" "<<f[i][0][1]<<" "<<f[i][1][0]<<" "<<f[i][1][1]<<endl;
	}
	cout<<f[n][k][0] + f[n][k][1]<<endl;
	return 0;
}