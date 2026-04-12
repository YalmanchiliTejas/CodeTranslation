#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int N,M;
const int MN=3005;
int fac[MN],inv[MN],pw[9000005];
int Mul(int x,int y){return (1ll*x*y)%M;}
int Add(int x,int y){return (x+y)%M;}
int C(int x,int y){return Mul(fac[x],Mul(inv[y],inv[x-y]));}
int f[MN][MN],g[MN],ans;
int main()
{
	N=read();M=read();
	reg int i,j;
	for(pw[0]=i=1;i<=N*N;++i) pw[i]=Mul(2,pw[i-1]);
	for(fac[0]=i=1;i<=N;++i)fac[i]=Mul(fac[i-1],i);
	for(inv[0]=inv[1]=1,i=2;i<=N;++i)inv[i]=Mul(inv[M%i],(M-M/i));
	for(i=2;i<=N;++i)inv[i]=Mul(inv[i-1],inv[i]);
	f[0][0]=1;
	for(i=1;i<=N;++i)for(f[i][0]=1,j=1;j<=i;++j)
		f[i][j]=Add(f[i-1][j],Add(f[i-1][j-1],Mul(f[i-1][j],j)));
	reg int tmp=2;
	for(i=N;~i;--i,tmp=Mul(tmp,tmp))for(j=0;j<=i;++j)
		g[i]=Add(g[i],Mul(f[i][j],Mul(tmp,pw[(N-i)*j])));
	for(i=0;i<=N;++i)
		ans=Add(ans,Mul((i&1?M-1:1),Mul(C(N,i),g[i])));
	return 0*printf("%d\n",ans);
}