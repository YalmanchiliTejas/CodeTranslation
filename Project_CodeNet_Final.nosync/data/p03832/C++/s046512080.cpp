#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ff first
#define ss second
using namespace std;
const int N=1005;
const long long M=1e9+7;
typedef long long ll;
typedef long double lb;
inline void read(int &x){x=0; char ch=getchar();while(ch<'0') ch=getchar();while(ch>='0'){x=x*10+ch-48; ch=getchar();}}
//------------------------------------------head---------------------------------------------------//
ll f[N][N],C[N][N],fac[N],inv[N];
inline ll po(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%M;
		x=x*x%M; y>>=1;
	}return ans;
}
int main()
{
	int n,a,b,c,d;read(n);read(a);read(b);read(c);read(d);
	fac[0]=1;rep(i,1,1000)
	{
		fac[i]=fac[i-1]*(ll)i%M;
		inv[i]=po(fac[i],M-2ll);
	}
	C[0][0]=1;rep(i,1,1000) 
	{
		C[i][0]=1;
		rep(j,1,i)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=M;
		}
	}
	f[a][0]=1;
	rep(i,a,b)
	{
		rep(j,0,n)
		{
			ll tot=1;if(j+i*c<=n) rep(tt,1,c-1) tot=tot*C[n-j-(tt-1)*i][i]%M;
			for(int k=j+i*c;k<=n && k<=j+i*d;k+=i)
			{
				tot*=C[n-k+i][i]; tot%=M; f[i+1][k]+=f[i][j]*tot%M*inv[(k-j)/i]; 
				f[i+1][k]%=M;//printf("%d %d %d %lld\n",i,j,k,tot);
			}//puts("");
			f[i+1][j]+=f[i][j];
			if(f[i+1][j]>=M) f[i+1][j]-=M;
		}
	}
	printf("%d\n",(int)f[b+1][n]);return 0;
}