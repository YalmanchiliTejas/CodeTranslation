#include <cstdio>
typedef long long ll;

const int N=3005;
int n,P,S[N][N],C[N][N],Ans;
inline int Mod(const int x){return x>=P?x-P:x;}
ll Pow(ll a,ll b,ll p,ll s=1){for(;b;b>>=1,a=a*a%p)if(b&1)s=s*a%p;return s;}

int main()
{
	scanf("%d%d",&n,&P);
	for(int i=**S=**C=1;i<=n+1;++i)for(int j=C[i][0]=1;j<=i;++j)
		C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]),S[i][j]=(S[i-1][j-1]+(ll)S[i-1][j]*j)%P;
	for(int i=0;i<=n;++i)
	{
		int c=0,u=Pow(2,Pow(2,n-i,P-1),P),v=Pow(2,n-i,P),vs=1;
		for(int j=0;j<=i;++j)c=(c+(ll)S[i+1][j+1]*u%P*vs)%P,vs=(ll)vs*v%P;
		Ans=i&1?(Ans-(ll)c*C[n][i]%P+P)%P:(Ans+(ll)c*C[n][i])%P;
	}
	return printf("%d\n",Ans),0;
}
