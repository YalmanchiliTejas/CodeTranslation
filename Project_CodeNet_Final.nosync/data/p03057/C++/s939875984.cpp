#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define NO() {puts("0");return 0;}
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=2e5+50;
int n,m,tag=0,mx,ans=0;
char s[N];
int val[N],dp[N],sum[N];
int q(int l,int r)
{
	if(l>r) return 0;
	int ras=sum[r];
	if(l!=0) ras=sub(ras,sum[l-1]);
	return ras;
}
int main()
{
	
	int i,x,pos;
	scanf("%d%d",&n,&m);	
	
	scanf("%s",s+1);
	if(s[1]=='B') tag=1;
	for(i=1;i<=m;i++)
	{
		if(s[i]=='R') val[i]=(1^tag);
		else val[i]=(0^tag);
	}
	for(x=1;x<=m&&val[x]==1;x++);
	x--;
	if(x==m)
	{
		mx=n;ans=1;
		dp[0]=1;sum[0]=1;
		for(i=1;i<=n;i++)
		{
			dp[i]=q(max(i-mx,0),i-2);
			sum[i]=add(sum[i-1],dp[i]);
		}
		//printf("%d %d\n",dp[1],dp[2]);
		for(i=2;i<=mx;i++)
		{
			ans=add(ans,mul(i,dp[n-i]));
		}
	}
	else
	{
		if(n&1) NO();
		if(x&1) mx=x;
		else mx=x+1;
		for(i=x+1;i<=m;)
		{
			if(val[i]==0) 
			{
				i++;continue;
			}
			pos=i;
			while(val[pos]==1) pos++;
			pos--;
			if(pos==m) break;
			if((pos-i+1)&1) mx=min(mx,pos-i+1);
			i=pos+1;
		}
		n=(n+1)/2;mx=(mx+1)/2;
		dp[0]=1;sum[0]=1;
		for(i=1;i<=n;i++)
		{
			dp[i]=q(max(i-mx,0),i-1);
			sum[i]=add(sum[i-1],dp[i]);
		}
		for(i=1;i<=mx;i++)
		{
			ans=add(ans,mul(i<<1,dp[n-i]));
		}
	}
	//printf("n%d mx%d\n",n,mx);
	
	
	printf("%d",ans);
	return 0;
}