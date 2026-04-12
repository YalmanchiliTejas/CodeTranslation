#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MP make_pair
#define fi first
#define se second 
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=3010,maxn=3000;
int cj[N],inv[N];
int dp[N][N];
int f[N],g[N],h[N];
int ans;
int n,mod;

int power(int x,int y,int mod){
	int ret=1;
	for(;y;y>>=1,x=1ll*x*x%mod){
		if(y&1)	ret=1ll*ret*x%mod;
	}
	return ret;
}

void init(){
	int i;
	cj[0]=1;rep(i,1,maxn)	cj[i]=1ll*cj[i-1]*i%mod;
	inv[maxn]=power(cj[maxn],mod-2,mod);inv[0]=1;
	for(i=maxn-1;i;i--)	inv[i]=1ll*inv[i+1]*(i+1)%mod;
}

int C(int n,int m){
	if(n<m)	return 0;
	return 1ll*cj[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);	
	register int i,j;
	int now,cur,tot,x;
	scanf("%d%d",&n,&mod);
	init();
	dp[0][0]=1;
	rep(i,1,n)	rep(j,0,i){
		dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*(j+1))%mod;
		dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
	}
	rep(i,0,n){
		cur=0;
		f[0]=1;x=power(2,n-i,mod);f[1]=x;
		rep(j,2,i){
			x=(x-1+mod)%mod;
			f[j]=1ll*f[j-1]*x%mod;
		}
		g[0]=1;
		rep(j,1,i)	g[j]=(g[j-1]+1ll*f[j]*inv[j])%mod;
		tot=power(2,power(2,n-i,mod-1),mod);
		h[0]=1;x=power(2,n-i,mod);
		rep(j,1,i)	h[j]=1ll*h[j-1]*x%mod;
		rep(j,0,i){
			now=1ll*dp[i][j]%mod*h[j]%mod;
			now=1ll*now*tot%mod;
			//now=1ll*now*C(i,j)%mod;
			cur=(cur+now)%mod;
		}
		cur=1ll*C(n,i)*cur%mod;
		if(i&1)	ans=(ans-cur)%mod;
		else ans=(ans+cur)%mod;
	}
	//ans=(power(2,power(2,n,mod-1),mod)-ans)%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}