#include<iostream>
#include<algorithm>
using namespace std;
int dp[1<<16];
int N;
int h[16],w[16];
string s[4];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>h[i]>>w[i];
	}
	for(int i=0;i<4;i++)cin>>s[i];
	for(int i=0;i<1<<16;i++)dp[i]=114514;
	dp[(1<<16)-1]=0;
	for(int i=1<<16;i--;)
	{
		for(int j=0;j<N;j++)
		{
			for(int x=-3;x<4;x++)for(int y=-3;y<4;y++)
			{
				char c=0;
				int take=0;
				for(int I=0;I<h[j];I++)for(int J=0;J<w[j];J++)
				{
					if(x+I<0||x+I>=4||y+J<0||y+J>=4)continue;
					int now=(x+I)*4+y+J;
					take|=1<<now;
					if(i>>now&1)
					{
						if(c==0)c=s[x+I][y+J];
						else if(c!=s[x+I][y+J])c=1;
					}
				}
				if(c>1)
				{
					dp[i&~take]=min(dp[i&~take],dp[i]+1);
				}
			}
		}
	}
	cout<<dp[0]<<endl;
}

