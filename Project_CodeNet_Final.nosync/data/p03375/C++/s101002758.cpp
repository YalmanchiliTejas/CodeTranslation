#include <cstdio>
using namespace std;
const int N=3010;
int n;
int MOD;
int fact[N],iact[N];
int s[N][N];
int fastPow(int x,int y,int MOD=::MOD){
	int res=1;
	for(;y;x=1ll*x*x%MOD,y>>=1)
		if(y&1)
			res=1ll*res*x%MOD;
	return res;
}
void readData(){
	scanf("%d%d",&n,&MOD);
}
void initMath(int n){
	fact[0]=fact[1]=1;
	for(int i=2;i<=n;i++) fact[i]=1ll*fact[i-1]*i%MOD;
	iact[0]=iact[1]=1;
	iact[n]=fastPow(fact[n],MOD-2);
	for(int i=n-1;i>=2;i--) iact[i]=1ll*iact[i+1]*(i+1)%MOD;
}
inline int C(int n,int m){
	return (0<=m&&m<=n)?1ll*fact[n]*iact[m]%MOD*iact[n-m]%MOD:0;
}
void initStirling(int n){ // prefix of each line
	for(int i=0;i<=n;i++) s[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=(1ll*s[i-1][j]*(j+1)%MOD+s[i-1][j-1])%MOD;
}
void calc(){
	int ans=fastPow(2,fastPow(2,n,MOD-1));
	int f;
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=0;j<=i;j++)
			(f+=1ll*s[i][j]*fastPow(fastPow(2,n-i),j)%MOD)%=MOD;
		f=1ll*f*fastPow(2,fastPow(2,n-i,MOD-1))%MOD;
		(ans+=((i&1)?-1ll:1ll)*C(n,i)*f%MOD)%=MOD;
	}
	printf("%d\n",ans>=0?ans:ans+MOD);
}
int main(){
	readData();
	initMath(n);
	initStirling(n);
	calc();
	return 0;
}
