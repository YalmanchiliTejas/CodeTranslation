#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=105;
const int MOD=1e9+7;

int n,m;
char a[N];
int dp[2][N][M];
void Add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

int main()
{
	
	scanf("%s%d",&a,&m);
	while(a[n]!='\0') n++;
	for(int i=0;i<n;i++)
		a[i]-='0';
	
	dp[1][0][0]=1;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<10;k++)
	{
		Add(dp[0][i+1][(j+k)%m],dp[0][i][j]);
		if(k>a[i]) continue;
		if(k==a[i]) Add(dp[1][i+1][(j+k)%m],dp[1][i][j]);
		else Add(dp[0][i+1][(j+k)%m],dp[1][i][j]);
	}
	printf("%d\n",(dp[0][n][0]+dp[1][n][0]-1+MOD)%MOD);
	
	return 0;
}