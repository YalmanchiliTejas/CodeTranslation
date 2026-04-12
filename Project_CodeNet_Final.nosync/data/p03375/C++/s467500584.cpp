// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=2e5+5;
int n,m;
int fac[maxn],inv[maxn],s[3005][3005];
int pw(int x,int y,int mod=m){if(y==0)return 1;if(y==1)return x;int mid=pw(x,y>>1,mod);if(y&1)return 1ll*mid*mid%mod*x%mod;return 1ll*mid*mid%mod;} 
int C(int x,int y){return 1ll*fac[x]*inv[y]%m*inv[x-y]%m;}
int f[maxn],p2[3005*3005];

signed main(){
	scanf("%lld%lld",&n,&m);
	fac[0]=inv[0]=1;
	for(int i=1;i<=maxn-5;i++)fac[i]=1ll*fac[i-1]*i%m;
	inv[maxn-5]=pw(fac[maxn-5],m-2,m);
	for(int i=maxn-6;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%m;
//	printf("%d\n",C(5,3));
	s[0][0]=1;for(int i=1;i<=n;i++){
		s[i][0]=1;
		for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+1ll*(j+1)*s[i-1][j]%m)%m;
	}
	p2[0]=1;for(int i=1;i<=n*n;i++)p2[i]=2ll*p2[i-1]%m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++)(f[i]+=1ll*s[i][j]*p2[(n-i)*j]%m)%=m;
		f[i]=1ll*f[i]*pw(2,pw(2,n-i,m-1),m)%m;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		if(i%2==0)(ans += 1ll*C(n,i)*f[i]%m)%=m;
		else (ans+=m-1ll*C(n,i)*f[i]%m)%=m;
	printf("%lld\n",ans);

	return 0;
}
