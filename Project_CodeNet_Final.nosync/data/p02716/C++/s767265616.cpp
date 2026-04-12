#include<iostream>
#include<algorithm>
using namespace std;
int N;
long A[2<<17];
long dp[2<<17][3];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<=N;i++)for(int j=0;j<3;j++)dp[i][j]=-9e18;
	dp[0][0]=0;
	for(int i=0;i<N;i++)for(int j=0;j<3;j++)
	{
		if(dp[i][j]<-1e18)continue;
		dp[min(i+2,N)][j+(i+2==N)]=max(dp[min(i+2,N)][j+(i+2==N)],dp[i][j]+A[i]);
		if(j<2)dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
	}
	cout<<dp[N][N%2?2:1]<<endl;
}