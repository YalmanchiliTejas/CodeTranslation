#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
char s[10010];
int d,l,f[10010][110];
void upd(int &x,int v)
{
	x=(x+v)%Mod;
}
int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	scanf("%d",&d);
	int sum=0;
	for (int i=1;i<=l;i++)
	{
		for (int j=0;j<s[i]-'0';j++)
		{
			upd(f[i][(sum+j)%d],1);
		}
		sum=(sum+s[i]-'0')%d;
		for (int j=0;j<d;j++)
		{
			for (int k=0;k<10;k++)
			{
				upd(f[i][(j+k)%d],f[i-1][j]);
			}
		}
		/*
		for (int j=0;j<d;j++)
		{
			cerr<<f[i][j]<<" ";
		}
		cerr<<endl;
		*/
	}
	int res=f[l][0];
	if (sum)
	{
		upd(res,Mod-1);
	}
	cout<<res<<endl;
	return 0;
}
