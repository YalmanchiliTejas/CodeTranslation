#include <iostream>
#include <cstdio>

using namespace std;

const int P=998244353;
const int G=3;
const int L=16384;

int fact[L],invf[L],f[L],g[L],h[L],t[L],trs[L];
int omega[L+5];
int n,m,len,ans;

inline int quick_power(int x,int y)
{
	int ret=1;
	for (;y;y>>=1,x=1ll*x*x%P) if (y&1) ret=1ll*ret*x%P;
	return ret;
}

void pre()
{
	fact[0]=1;
	for (int i=1;i<L;++i) fact[i]=1ll*fact[i-1]*i%P;
	invf[L-1]=quick_power(fact[L-1],P-2);
	for (int i=L-1;i>=1;--i) invf[i-1]=1ll*invf[i]*i%P;
}

inline int C(int n,int m){return n>=m?1ll*fact[n]*invf[m]%P*invf[n-m]%P:0;}

void NTT_pre()
{
	for (len=1;len<=n<<1;len<<=1);
	for (int i=0,ret;i<len;++i)
	{
		ret=0;
		for (int x=i,j=1;j<len;j<<=1,x>>=1) ret=(ret<<1)|(x&1);
		trs[i]=ret;
	}
	int g=quick_power(G,(P-1)/len);omega[0]=1;
	for (int i=1;i<=len;++i) omega[i]=1ll*omega[i-1]*g%P;
}

void DFT(int *a,int sig)
{
	for (register int i=0;i<len;++i) t[trs[i]]=a[i];
	for (register int l=2;l<=len;l<<=1)
		for (register int h=l>>1,j=0,wn=omega[sig>0?len/l:len-len/l];j<len;j+=l)
			for (register int i=0,w=1;i<h;++i,w=1ll*w*wn%P)
			{
				register int u=t[i+j],v=1ll*t[i+j+h]*w%P;
				t[i+j]=(u+v)%P,t[i+j+h]=(u-v+P)%P;
			}
	for (register int i=0;i<len;++i) a[i]=t[i];
	if (sig<0) for (register int i=0,inv=quick_power(len,P-2);i<len;++i) a[i]=1ll*a[i]*inv%P;
}

int main()
{
	//freopen("trinity.in","r",stdin),freopen("trinity.out","w",stdout);
	scanf("%d%d",&n,&m),pre(),NTT_pre();
	f[0]=1;
	for (int i=1;i<=n;++i) g[i]=invf[i+2];
	DFT(g,1);
	for (int i=1;i<=m;++i)
	{
		for (int j=0;j<=n;++j) h[j]=1ll*f[j]*invf[j]%P;
		for (int j=n+1;j<len;++j) h[j]=0;
		DFT(h,1);
		for (int j=0;j<len;++j) h[j]=1ll*h[j]*g[j]%P;
		DFT(h,-1);
		for (int j=0;j<=n;++j) f[j]=(1ll*fact[j+2]*h[j]%P+1ll*(C(j+1,2)+1)*f[j]%P)%P;
	}
	ans=0;
	for (int i=0;i<=n;++i) (ans+=1ll*C(n,i)*f[i]%P)%=P;
	printf("%d\n",ans);
	//fclose(stdin),fclose(stdout);
	return 0;
}