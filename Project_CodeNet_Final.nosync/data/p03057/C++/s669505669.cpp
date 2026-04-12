#pragma GCC optimize("Ofast,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
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