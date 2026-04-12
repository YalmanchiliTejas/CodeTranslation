#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for (int i=a;i>=b;i--)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=a;i<b;i++)
#define maxn 10000005
int n;
#define mod 998244353
void add(int&x,int y){
	x=(x+y)%mod;
}
int pw2[maxn],fac[maxn],inv[maxn];
int power(int a,int b,int p){
	int s=1,w=a;while (b){
		if (b&1)s=1ll*s*w%p;
		w=1ll*w*w%p;b>>=1;
	}
	return s;
}
int C(int a,int b){
	return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
	scanf("%d",&n);int res=0;
	pw2[0]=1;rep(i,1,n)pw2[i]=2*pw2[i-1]%mod;
	fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power(fac[n],mod-2,mod);
	per(i,n,1)inv[i-1]=1ll*inv[i]*i%mod;
	rep(i,n/2+1,n)
		add(res,2ll*C(n,i)*pw2[n-i]%mod);
	res = (power(3,n,mod)-res+mod)%mod;
	printf("%d\n",res);
	return 0;
}