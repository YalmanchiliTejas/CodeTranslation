#include<bits/stdc++.h>
using namespace std;
#define N 11116
#define mod 998244353

int n,x,y,f[N][N],ans;
char a[N],b[N];
long long fac[N],inv[N];

long long C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	scanf(" %s %s",a,b);n=strlen(a);
	for (int i=0;i<n;i++)
		if (a[i]=='1')
		(b[i]=='0')?x++:y++;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=2;i<N;i++) inv[i]=-(mod/i)*inv[mod%i]%mod;
	for (int i=2;i<N;i++) inv[i]=inv[i-1]*inv[i]%mod;
	for (int i=0;i<=x;i++) f[i][0]=fac[i]*fac[i]%mod;
	for (int i=1;i<=x;i++)
		for (int j=1;j<=y;j++)
			f[i][j]=(1ll*f[i-1][j]*i*i+1ll*f[i][j-1]*i*j)%mod;
	for (int i=0;i<=y;i++)
		ans=(ans+1ll*f[x][y-i]*fac[i]%mod*fac[i]%mod*C(y,i)%mod*C(x+y,i))%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}