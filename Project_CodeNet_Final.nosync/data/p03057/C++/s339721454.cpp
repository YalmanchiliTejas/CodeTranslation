#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
typedef long long s64;
const int N=2e5+5,D=1e9+7;
char s[N];
s64 dp[N],sum[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	scanf("%s",s+1);
	if(s[1]=='B')
	rep(i,1,m)s[i]="RB"[s[i]=='R'];
	int mn[2]={N,N},now=0;
	rep(i,1,m)
	if(s[i]=='R')++now;
	else 
	{
		if(now)chmin(mn[now%2],now);
		now=0;
	}
	if(now==m)
	{
		dp[0]=1;
		rep(i,2,n+2)dp[i]=(dp[i-1]+dp[i-2])%D;
		cout<<(dp[n]+dp[n+2])%D<<endl;
	}
	else
	{
		int fir=1;
		while(s[fir]=='R')++fir;
		if(fir%2)chmin(mn[1],fir);
		if(n%2){puts("0");exit(0);}
		dp[0]=sum[0]=1;
		rep(i,2,n)
		{
			dp[i]=sum[i-2];
			int j=i-mn[1]-1-2;
			if(j>=0)dp[i]-=sum[j];
			dp[i]%=D;
			sum[i]=(sum[i-2]+dp[i])%D;
		}
		s64 ans=0;
		rep(x,0,min(n/2-1,mn[1]/2))
		{
			ans+=sum[n-2*x-2];
			if(mn[1]+3<=n)ans-=sum[n-mn[1]-1-2];
		}
		cout<<(ans*2%D+D)%D<<endl;
	}
}