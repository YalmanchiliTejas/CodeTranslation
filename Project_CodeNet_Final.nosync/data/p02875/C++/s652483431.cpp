#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 998244353
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu_alter
const int N=1e7+5;
int pw2[N],pw3[N],fac[N],inv[N],n;
//
inline void add(int &x,int y){
	x+=y;if(x>=MOD)x-=MOD;
}	
inline void sub(int &x,int y){
	x-=y;if(x<0)x+=MOD;
}
inline int mul(int x,int y){
	ll ans=1ll*x*y;
	return ans%MOD;
}
inline int c(int x,int y){
	return mul(fac[x],mul(inv[y],inv[x-y]));
}
inline int modpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
inline int modinv(int x){return modpow(x,MOD-2);}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=getint();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	inv[n]=modinv(fac[n]);
	for(int i=n-1;i>=0;i--)inv[i]=mul(inv[i+1],i+1);
	pw3[0]=1;
	for(int i=1;i<=n;i++)pw3[i]=mul(pw3[i-1],3);
	pw2[0]=1;
	for(int i=1;i<=n;i++)pw2[i]=mul(pw2[i-1],2);
	int res=pw3[n];
	for(int i=n/2+1;i<=n;i++)sub(res,mul(c(n,i),pw2[n-i+1]));
	cout<<res<<endl;
	return 0;
}
