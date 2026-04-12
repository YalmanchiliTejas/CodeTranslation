#include<cstdio>
const int md=1e9+7,N=1007;
typedef long long LL;
int n,A,B,C,D,F[N][N],fac[N],iv[N];
inline int pow(int a,int b){
	int ret=1;
	for(;b;b>>=1,a=(LL)a*a%md)if(b&1)ret=(LL)ret*a%md;
	return ret;
}
int main(){
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	for(int i=*fac=1;i<=n;++i)fac[i]=(LL)fac[i-1]*i%md;
	iv[n]=pow(fac[n],md-2);
	for(int i=n-1;~i;--i)iv[i]=(i+1LL)*iv[i+1]%md;
	F[A-1][0]=1;
	for(int i=A;i<=B;++i)
	for(int j=0;j<=n;++j){
		int&f=F[i][j];f=F[i-1][j];
		for(int k=C,g=pow(iv[i],C);k<=D&&k*i<=j;++k,g=(LL)g*iv[i]%md){
			int L=n-j+k*i;
			f=(f+(LL)F[i-1][j-k*i]*fac[L]%md*iv[k*i]%md*iv[L-k*i]%md*fac[k*i]%md*g%md*iv[k])%md;
		}
	}
	printf("%d\n",F[B][n]);
	return 0;
}