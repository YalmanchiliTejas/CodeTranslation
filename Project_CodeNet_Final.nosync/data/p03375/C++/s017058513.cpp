#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=3005;
int n,mod,ans;
int fac[maxn],ifac[maxn],f[maxn][maxn];

int C(int a,int b){
	if(a<0||b<0||a<b)return 0;
	return 1LL*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int power(int x,int pow,int mod){
	int res=1;
	for(;pow;pow>>=1){
		if(pow&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&mod);
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[mod%i]*(mod-mod/i)%mod;
	}
	REP(i,n)ifac[i]=1LL*ifac[i-1]*ifac[i]%mod;
	f[0][0]=1;
	REP(i,n)rep(j,n+1){
		f[i][j]=f[i-1][j];
		if(j){
			f[i][j]+=f[i-1][j-1];
			if(f[i][j]>=mod)f[i][j]-=mod;
		}
		f[i][j]+=1LL*f[i-1][j]*j%mod;
		if(f[i][j]>=mod)f[i][j]-=mod;
	}
	rep(i,n+1){
		int cur=power(2,n-i,mod),coef=1LL*C(n,i)*power(2,power(2,n-i,mod-1),mod)%mod,now=1;
		if(i&1)coef=(mod-coef)%mod;
		rep(j,i+1){
			ans+=1LL*f[i][j]*now%mod*coef%mod;
			if(ans>=mod)ans-=mod;
			now=1LL*now*cur%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}