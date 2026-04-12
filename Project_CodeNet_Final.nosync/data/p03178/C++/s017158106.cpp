#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
char s[100005];
int n,d;
int a[100005];
ll f[10005][105][2];
void add(ll &x,ll v)
{
	x+=v;
	if(x>=mod) x-=mod;
}
int main()
{
	scanf("%s%d",s+1,&d);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	f[0][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int p=j-k;
				while(p<0) p+=d;
				//printf("j=%d k=%d p=%d\n",j,k,p);
				add(f[i][j][0],f[i-1][p][0]);
				if(k==a[i]) add(f[i][j][1],f[i-1][p][1]);
				else if(k<a[i]) add(f[i][j][0],f[i-1][p][1]);
			}
			//printf("f(%d,%d)=(%d,%d)\n",i,j,f[i][j][0],f[i][j][1]);
		}
	}
	ll ans=(f[n][0][0]+f[n][0][1]-1+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}