#include<iostream>
#include<algorithm>
using namespace std;
int N;
int dp[2000][2000],X[2000],Y[2000],nX[2000],nY[2000];
int A[3];
int tmp[2000];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=-1e9;
	for(int i=0;i<N;i++)X[i]=Y[i]=-1e9;
	cin>>A[0]>>A[1];
	A[0]--,A[1]--;
	dp[A[0]][A[1]]=0;
	X[A[0]]=0;
	Y[A[1]]=0;
	int ans=0;
	for(int i=1;i<N;i++)
	{
		int T[3];
		for(int j=0;j<3;j++)
		{
			cin>>A[j];
			A[j]--;
			T[j]=dp[A[j]][A[j]];
		}
		if(A[0]==A[1]&&A[1]==A[2])
		{
			ans++;
			continue;
		}
		int MX=0;
		for(int j=0;j<N;j++)
		{
			nX[j]=X[j];
			nY[j]=Y[j];
			if(MX<X[j])MX=X[j];
			if(MX<Y[j])MX=Y[j];
		}
		for(int j=0;j<3;j++)
		{
			int a=A[j],b=A[(j+1)%3],c=A[(j+2)%3];
			if(a==b)
			{
				for(int k=0;k<N;k++)tmp[k]=max(dp[a][k],dp[k][a]);
				for(int k=0;k<N;k++)
				{
					int now=dp[k][c]=max(dp[k][c],tmp[k]+1);
					if(nX[k]<now)nX[k]=now;
					if(nY[c]<now)nY[c]=now;
				}
			}
		}
		for(int j=0;j<3;j++)
		{
			int b=A[(j+1)%3],c=A[(j+2)%3];
			int now=dp[b][c]=max(dp[b][c],T[j]+1);
			if(nX[b]<now)nX[b]=now;
			if(nY[c]<now)nY[c]=now;
		}
		for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(j!=k)
		{
			int a=A[j],b=A[k];
			int now=dp[a][b]=max(dp[a][b],MX);
			if(nX[a]<now)nX[a]=now;
			if(nY[b]<now)nY[b]=now;
		}
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<3;k++)
			{
				int a=A[k];
				int now=dp[j][a]=max(dp[j][a],max(X[j],Y[j]));
				if(nX[j]<now)nX[j]=now;
				if(nY[a]<now)nY[a]=now;
				now=dp[a][j]=max(dp[a][j],max(X[j],Y[j]));
				if(nX[a]<now)nX[a]=now;
				if(nY[j]<now)nY[j]=now;
			}
			X[j]=nX[j];
			Y[j]=nY[j];
		}
	}
	int x;cin>>x;x--;
	int MX=0;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		MX=max(MX,dp[i][j]+(i==j&&j==x));
	}
	cout<<MX+ans<<endl;
}
