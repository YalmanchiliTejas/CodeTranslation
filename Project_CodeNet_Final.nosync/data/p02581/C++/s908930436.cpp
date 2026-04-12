#include<bits/stdc++.h>
using namespace std;
int n,a[6060],dp[2020][2020],mx[2020],gx[101010][3],sz,mmxx,al;
void ggxx(int x,int y,int vl)
{
	gx[sz][0]=x;
	gx[sz][1]=y;
	gx[sz][2]=vl;
	sz++;
}
void gggxxx(int x,int y,int vl)
{
	dp[x][y]=max(dp[x][y],vl);
	mx[x]=max(mx[x],vl);
	swap(x,y);
	dp[x][y]=max(dp[x][y],vl);
	mx[x]=max(mx[x],vl);
	mmxx=max(mmxx,vl);
}
void ggggxxxx()
{
	for(int i=0;i<sz;i++)
	{
		gggxxx(gx[i][0],gx[i][1],gx[i][2]);
	}
	sz=0;
}
int main()
{
	memset(dp,-0x3f3f3f,sizeof(dp));
	memset(mx,-0x3f3f3f,sizeof(mx));
	mmxx=-0x3f3f3f;
	cin>>n;
	for(int i=0;i<n*3;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	gggxxx(a[0],a[1],0);
	for(int i=0;i<n-1;i++)
	{
		int x[3];
		x[0]=a[3*i+2];
		x[1]=a[3*i+3];
		x[2]=a[3*i+4];
		if(x[0]==x[1] && x[1]==x[2])
		{
			al++;
			continue;
		}
		for(int tt=0;tt<3;tt++)
		{
			ggxx(x[0],x[1],max(mmxx,dp[x[2]][x[2]]+1));
			for(int j=0;j<n;j++)
			{
				if(x[0]==x[1])
				{
					ggxx(j,x[2],dp[j][x[0]]+1);
				}
				ggxx(j,x[2],mx[j]);
			}
			swap(x[0],x[1]);
			swap(x[1],x[2]);
		}
		ggggxxxx();
	}
	cout<<max(mmxx,dp[a[3*n-1]][a[3*n-1]]+1)+al<<endl;
	return 0;
}