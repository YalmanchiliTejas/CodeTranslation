#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1e9+7;
char s[maxn];
inline int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(ll)res*x%mod;
		y>>=1;
		x=(ll)x*x%mod;
	}
	return res;
}
int dp[maxn],sum[maxn];
int main(){
	int n=read(),m=read();
	scanf("%s",s+1);
	int Min=inf;
	for(int i=1,j;i<=m;i++) if(s[i]==s[1]){
		j=i;
		while(j<m && s[j+1]==s[1]) ++j;
		if(j!=m){
			if((j-i+1)%2==1) chkmin(Min,j-i+1);
			else if(i==1) chkmin(Min,j-i+2);
		}
		i=j;
	}
	int flag=1;
	REP(i,2,m) flag&=(s[i]==s[1]);
	dp[1]=sum[1]=1;
	REP(i,2,n+1){
		if(flag){
			dp[i]=sum[i-2];
			sum[i]=(sum[i-1]+dp[i])%mod;
		}
		else{
			dp[i]=(sum[i-2]-sum[max(i-Min-3,0)]+mod)%mod;
			sum[i]=(sum[i-2]+dp[i])%mod;
		}
	}
	int ans=(dp[n+1]*2+flag)%mod;
	REP(i,1,n-2) if(((n-i)%2==1 && n-i<=Min) || flag) ans=(ans+(ll)dp[i]*(n-i-1))%mod;
	printf("%d\n",ans);
	return 0;
}
