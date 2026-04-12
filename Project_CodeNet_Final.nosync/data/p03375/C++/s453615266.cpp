#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int Mod;
int qpow(int x,int y,int p=Mod){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%p)
		if (y&1) res=1LL*res*x%p;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}
int C[3100][3100],S[3100][3100];
void init(int x){
	C[0][0]=S[0][0]=1;
	for (int i=1;i<=x;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++){
			C[i][j]=upd(C[i-1][j]+C[i-1][j-1]-Mod);
			S[i][j]=(S[i-1][j-1]+1LL*j*S[i-1][j])%Mod;
		}
	}
}

int n;
int main()
{
	scanf("%d%d",&n,&Mod);
	init(n+10);
	int res=0;
	for (int i=0,a=1;i<=n;i++,a=upd(-a)){
		int subres=0;
		for (int j=0,b=qpow(2,n-i),c=1;j<=i;j++,c=1LL*c*b%Mod){
			subres=(subres+1LL*S[i+1][j+1]*c)%Mod;
		}
		subres=1LL*subres*a%Mod*C[n][i]%Mod*qpow(2,qpow(2,n-i,Mod-1))%Mod;
		res=upd(res+subres-Mod);
	}
	printf("%d\n",res);
	return 0;
}