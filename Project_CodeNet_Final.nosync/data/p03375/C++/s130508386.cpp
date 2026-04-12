#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

const int N=3005;

int n,mod,tag,ans,w;
int s[N][N],c[N][N];

void init(int n){
	int i,j;
	s[0][0]=1;
	for (i=1;i<=n;i++)
		for (j=1;j<=i;j++) s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j%mod)%mod;
	c[0][0]=1;
	for (i=1;i<=n;i++){
		c[i][0]=1;
		for (j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}

int quickpow(int x,int y,int p){
	int s=1;
	for (;y;y>>=1,x=1ll*x*x%p)
		if (y&1) s=1ll*s*x%p;
	return s;
}

int main(){
	int i,j;
	scanf("%d%d",&n,&mod);
	init(n+1);
	tag=1; ans=0;
	for (i=0;i<=n;i++){
		w=quickpow(2,quickpow(2,n-i,mod-1),mod);
		for (j=0;j<=i;j++)
			(ans+=1ll*tag*w*quickpow(2,(n-i)*j,mod)%mod*c[n][i]%mod*s[i+1][j+1]%mod)%=mod;
		tag*=-1;
	}
	ans=(ans%mod+mod)%mod; 
	printf("%d\n",ans);
	return 0;
}