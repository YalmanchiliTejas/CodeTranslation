//problem:arc096C
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=3005;
int n,MOD,fac[MAXN],invf[MAXN],S[MAXN][MAXN];
inline int mod(int x){return x<MOD?(x<0?x+MOD:x):x-MOD;}
inline int pow_mod(int x,int i,int m=MOD){int y=1;while(i){if(i&1)y=(ll)y*x%m;x=(ll)x*x%m;i>>=1;}return y;}
inline int comb(int n,int k){if(n<k)return 0;return (ll)fac[n]*invf[k]%MOD*invf[n-k]%MOD;}
int main() {
	n=read();MOD=read();
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(ll)fac[i-1]*i%MOD;
	invf[n]=pow_mod(fac[n],MOD-2);
	for(int i=n-1;i>=0;--i)invf[i]=(ll)invf[i+1]*(i+1)%MOD;
	for(int i=0;i<=n+1;++i){
		S[i][0]=0;S[i][i]=1;
		for(int j=1;j<i;++j){
			S[i][j]=mod((ll)j*S[i-1][j]%MOD+S[i-1][j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		int x=(ll)comb(n,i)*pow_mod(2,pow_mod(2,n-i,MOD-1))%MOD,s=0;
		if(i&1)x=mod(MOD-x);
		for(int j=0;j<=i;++j){
			s=mod(s+(ll)pow_mod(2,(n-i)*j)*S[i+1][j+1]%MOD);
		}
		ans=mod(ans+(ll)x*s%MOD);
	}
	cout<<ans<<endl;
	return 0;
}