#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=10000+10,mo=998244353;
char s[maxn];
int f[maxn][maxn],fac[maxn],inv[maxn],bz[maxn];
int i,j,k,l,t,n,m,ans,x,y;
int qsm(int x,int y){
	if (!y) return 1;
	int t=qsm(x,y/2);
	t=(ll)t*t%mo;
	if (y%2) t=(ll)t*x%mo;
	return t;
}
int C(int n,int m){
	if (n<m||m<0) return 0;
	return (ll)fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n)
		if (s[i]=='1') y++,bz[i]++;
	scanf("%s",s+1);
	fo(i,1,n)
		if (s[i]=='1'&&bz[i]) x++;
	y-=x;
	fac[0]=1;
	fo(i,1,n) fac[i]=(ll)fac[i-1]*i%mo;
	inv[n]=qsm(fac[n],mo-2);
	fd(i,n-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mo;
	f[0][0]=1;
	fo(i,1,y) f[0][i]=(ll)fac[i]*fac[i]%mo;
	fo(i,1,x)
		fo(j,1,y)
			f[i][j]=(ll)((ll)f[i-1][j]*i%mo+(ll)f[i][j-1]*j%mo)*j%mo;
	fo(i,0,x)
		(ans+=(ll)f[x-i][y]*qsm(fac[i],2)%mo*C(x,i)%mo*C(x+y,i)%mo)%=mo;
	(ans+=mo)%=mo;
	printf("%d\n",ans);
}