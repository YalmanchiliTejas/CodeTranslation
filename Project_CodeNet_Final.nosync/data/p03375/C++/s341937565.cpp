#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 3333
LL n,mod,s[N][N],c[N][N];
LL mul(LL a,LL b,LL p){
	LL res=0;
	for (;b;b>>=1,a=(a+a)%p){
		if (b&1) res=(res+a)%p;
	}
	return res;
}
inline LL read(){
    LL x=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9'){
        x=x*10+ch-'0';ch=getchar();
    }
    return x*f;
}
LL fastpow(LL a,LL b,LL p){
	LL res=1;
	for (;b;b>>=1,a=mul(a,a,p)){
		if (b&1) res=mul(res,a,p);
	}
	return res;
}
int main(){
	n=read(),mod=read();
	for (int i=1;i<=n;++i){
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;++j){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for (int i=0;i<=n;++i){
		s[i][0]=1;
		for (int j=1;j<=i;++j){
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*(j+1)%mod)%mod;
		}
	}
	LL ans=0;
	for (int i=0;i<=n;++i){
		LL k=c[n][i];
		if (i&1) k=(mod-k)%mod;
		LL x=fastpow(2,n-i,mod-1);
		x=fastpow(2,x,mod);
		LL tmp=fastpow(2,n-i,mod);
		LL cnt=0,y=1;
		for (int j=0;j<=i;++j){
			cnt=(cnt+(s[i][j]*y%mod))%mod;
			y=tmp*y%mod;
		}
		ans=(ans+(k*cnt%mod*x%mod))%mod;
	}
	cout<<ans<<endl;
}