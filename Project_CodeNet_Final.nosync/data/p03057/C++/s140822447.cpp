#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define X 1000000007
using namespace std;
int n,m,t,a[N+5],f[N+5],g[N+5];char s[N+5];
int w[N+5][2];I void Work()
{
	#define DP() for(RI i=2;i<=n;++i) w[i][0]=w[i-1][1],w[i][1]=(w[i-1][0]+w[i-1][1])%X;
	w[1][1]=1;DP();RI t=(w[n][0]+w[n][1])%X;
	w[1][0]=1,w[1][1]=0;DP();printf("%d\n",(t+w[n][1])%X);
}
int main()
{
	RI i;for(scanf("%d%d%s",&n,&m,s+1),i=1;i<=m;++i) s[i]^s[i-1]&&++t,++a[t];
	if(t&1&&--t,!t) return Work(),0;if(n&1) return puts("0"),0;
	RI p=a[1]+(a[1]&1^1);for(i=3;i<=t;i+=2) a[i]&1&&(p=min(p,a[i]));
	for(f[0]=g[0]=1,i=2;i<=n;++i) f[i]=(g[i-2]+(i-p-3>=0?X-g[i-p-3]:0))%X,g[i]=(g[i-2]+f[i])%X;
	RI res=0;for(i=2;i<=p+1&&i<=n;++i) res=(1LL*i*f[n-i]+res)%X;return printf("%d\n",res),0;
}