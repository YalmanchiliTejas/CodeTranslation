#include<bits/stdc++.h>
using namespace std;
char p[10005];
long long kn[10005][105];
main()
{
	int t,r;
	scanf("%s%d",&p[1],&r);
	kn[0][0]=1;
	int si=strlen(&p[1]);
	for(int i = 0;i < si;i++)
	{
		for(int j = 0;j < r;j++)
		{
			for(int k = 0;k < 10;k++)
			{
				//if(i==0 && (j!=0 || k!=0))
				//kn[i+1][(j+k)%r]+=kn[i][j];
				//else if(i!=0)
				kn[i+1][(j+k)%r]+=kn[i][j];
				kn[i+1][(j+k)%r]%=1000000007;
			}
			//printf("%d ",kn[i][j]);
		}
		//printf("\n");
	}
	int to=0;
	int sm=0;
	for(int i = 1;i <= si;i++)
	{
		for(int j = 0;j < p[i]-'0';j++)
		{
			to+=kn[si-i][(r-sm-j+r)%r];
			to%=1000000007;
		}
		sm+=p[i]-'0';
		sm%=r;
	}
	if(sm!=0)
	{
		to--;
		to+=1000000007;
		to%=1000000007;
	}
	//to++;
	//to%=1000000007;
	printf("%d",to);
}