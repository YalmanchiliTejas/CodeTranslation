#include <cstring>
#include <cstdio>
const int N=10005,mo=998244353;
long long f[N],fac[N],inv[N];
char a[N],b[N];
int ksm(int x,int y){
	int i=1;
	for (;y;y>>=1,x=1ll*x*x%mo)
		if (y&1) i=1ll*i*x%mo;
	return i;
}
void Pre(int n){
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mo;
	inv[n]=ksm(fac[n],mo-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mo;
}
int C(int n,int m){
	return fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int main(){
	scanf("%s%s",a,b);
	int len=strlen(a),n=0,m=0;
	for (int i=0;i<len;i++)
		if (a[i]=='1') b[i]=='1'?n++:m++;
	f[0]=1;
	for (int j=1;j<=m;j++){
		f[0]=f[0]*j*j%mo;
		for (int i=1;i<=n;i++)
			f[i]=(f[i]*j+f[i-1]*i)*j%mo;
	}
	Pre(n+m);
	int ans=0;
	for (int i=0;i<=n;i++)
		ans=(ans+C(n,i)*fac[i]%mo*fac[i]%mo*f[n-i]%mo*C(n+m,i))%mo;
	printf("%d\n",ans);
}