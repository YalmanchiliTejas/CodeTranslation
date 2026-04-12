#include<bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int md=1000000007;
const int mxn=200005;
int n,m,mx,ans,dp[mxn],f[mxn];
char s[mxn];
inline void add(int&x,int y){
	x+=y;
	if(x>=md)x-=md;
}
signed main(){
	int i,j,t;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=m;++i)if(s[i]!=s[1])break;mx=i-1;
	if(mx==m){
		dp[0]=f[i]=ans=1;
		for(int i=0;i<=n;++i){
			if(i>=2)dp[i]=f[i-2];
			f[i]=(f[i-1]+dp[i])%md;
			if(n-i>1)add(ans,(ll)dp[i]*(n-i)%md);
		}
		printf("%d\n",ans);
		return 0;
	}
	if(n&1)return 0*puts("0");
	if(!(mx&1))++mx;
	for(t=0;i<=m;++i){
		if(s[i]==s[1])++t;
		else{
			if(t&1)mx=min(mx,t);
			t=0;
		}
	}
	n>>=1,mx=mx+1>>1;
	dp[0]=f[0]=1;
	for(i=0;i<=n;++i){
		if(i){
			dp[i]=(md+f[i-1]-(i-mx-1>=0?f[i-mx-1]:0))%md;
			f[i]=(f[i-1]+dp[i])%md;
		}
		if(n-i<=mx) add(ans,(ll)(n-i)*dp[i]*2ll%md);
	}
	printf("%d\n",ans);
}