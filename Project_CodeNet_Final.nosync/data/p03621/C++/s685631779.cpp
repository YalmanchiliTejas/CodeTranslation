#include<cstdio>
#include<cstring>
using int64=long long;
constexpr int N=10001,mod=998244353;
char a[N],b[N];
int fact[N],factinv[N],f[N][N];
void exgcd(const int &a,const int &b,int &x,int &y) {
	if(!b) {
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
inline int inv(const int &x) {
	int ret,tmp;
	exgcd(x,mod,ret,tmp);
	return (ret%mod+mod)%mod;
}
inline int C(const int &n,const int &m) {
	if(n<m||n<0||m<0) return 0;
	return (int64)fact[n]*factinv[m]%mod*factinv[n-m]%mod;
}
int main() {
	scanf("%s%s",a,b);
	const int n=strlen(a);
	for(register int i=fact[0]=1;i<=n;i++) {
		fact[i]=(int64)fact[i-1]*i%mod;
	}
	factinv[n]=inv(fact[n]);
	for(register int i=n;i;i--) {
		factinv[i-1]=(int64)factinv[i]*i%mod;
	}
	int s1=0,s2=0;
	for(register int i=0;i<n;i++) {
		if(a[i]=='1'&&b[i]=='1') s1++;
		if(a[i]=='1'&&b[i]=='0') s2++;
	}
	for(register int i=0;i<=s2;i++) {
		f[0][i]=(int64)fact[i]*fact[i]%mod;
	}
	for(register int i=1;i<=s1;i++) {
		for(register int j=1;j<=s2;j++) {
			f[i][j]=((int64)f[i-1][j]*i%mod*j%mod+(int64)f[i][j-1]*j%mod*j%mod)%mod;
		}
	}
	int ans=0;
	for(register int i=0;i<=s1;i++) {
		(ans+=(int64)f[s1-i][s2]*fact[i]%mod*fact[i]%mod*C(s1,i)%mod*C(s1+s2,i)%mod)%=mod;
	}
	printf("%d\n",ans);
	return 0;
}