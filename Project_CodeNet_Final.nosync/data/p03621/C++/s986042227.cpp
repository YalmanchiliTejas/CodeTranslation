/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define cs const int &
const int N=1e4+10,MOD=998244353;

inline int Mul(cs a,cs b){return 1ll*a*b%MOD;}
inline int Add(cs a,cs b){return a+b>=MOD? a+b-MOD:a+b;}
inline int Pow(int a,int b){int r=1;while(b){if(b&1)r=Mul(r,a);a=Mul(a,a),b>>=1;}return r;}

char strA[N],strB[N];
int cmo,uco;
int f[2][N],h[N],g[N],pw2[N];
int fac[N],ifac[N];

int Comb(cs a,cs b){return a>b? 0:Mul(fac[b],Mul(ifac[a],ifac[b-a]));}
int main(){
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=Mul(fac[i-1],i);
	ifac[N-1]=Pow(fac[N-1],MOD-2);
	for(int i=N-2;i>=0;i--) ifac[i]=Mul(ifac[i+1],i+1);
	pw2[0]=1;
	for(int i=1;i<N;i++) pw2[i]=Add(pw2[i-1],pw2[i-1]);
	scanf("%s%s",strA,strB);
	int len=strlen(strA);
	for(int i=0;i<len;i++){
		if(strA[i]=='1' && strB[i]=='1') cmo++;
		if(strA[i]=='1' && strB[i]=='0') uco++;
	}
	int ans=0;
	for(int i=0;i<=cmo;i++){
		int I=i&1,J=!I;
		if(i) f[I][0]=0;
		else f[I][0]=1;
		for(int j=1;j<=uco;j++)
			f[I][j]=Add(Mul(Mul(i,j),f[J][j]),Mul(Mul(j,j),f[I][j-1]));
		int res=f[I][uco];
		res=Mul(res,Mul(Mul(fac[cmo-i],fac[cmo-i]),Mul(Comb(i,cmo),Comb(cmo-i,cmo+uco))));
		ans=Add(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}