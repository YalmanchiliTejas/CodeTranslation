#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 3005
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define ff first
#define ss second

int n,m,mod;
int fac[maxn],inv[maxn],pp[maxn],p2[maxn];
int S[maxn][maxn];

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int power(int a,int k){
	int ret=1;
	for (;k;k>>=1,a=1ll*a*a%mod) if (k&1) ret=1ll*ret*a%mod;
	return ret;
}

int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}

int main(){
	n=read(),mod=read();
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[0]=1; inv[n]=power(fac[n],mod-2); for (int i=n-1;i;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	pp[0]=2; for (int i=1;i<=n;i++) pp[i]=1ll*pp[i-1]*pp[i-1]%mod;
	p2[0]=1; for (int i=1;i<=n;i++) p2[i]=(p2[i-1]<<1)%mod;
	for (int i=0;i<=n;i++){
		S[i][0]=1;
		for (int j=1;j<=i;j++) S[i][j]=(1ll*(j+1)*S[i-1][j]+S[i-1][j-1])%mod;
	}
	int ans=0;
	for (int i=0;i<=n;i++){
		int res=0,pps=1;
		for (int j=0;j<=i;j++){
			res=(res+1ll*S[i][j]*pps)%mod;
			pps=1ll*pps*p2[n-i]%mod;
		}
		res=1ll*res*pp[n-i]%mod;
		res=1ll*res*C(n,i)%mod;
		ans=(ans+res*((i&1)?-1:1))%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
