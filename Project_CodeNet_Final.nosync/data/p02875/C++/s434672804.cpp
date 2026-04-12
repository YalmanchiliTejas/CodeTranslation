#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 10000000
#define X 998244353
#define C(x,y) (1LL*Fac[x]*IFac[y]%X*IFac[(x)-(y)]%X)
using namespace std;
int n,Fac[N+5],IFac[N+5];
I int Qpow(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,t=0;for(scanf("%d",&n),Fac[0]=i=1;i<=n;++i) Fac[i]=1LL*Fac[i-1]*i%X;
	for(IFac[n]=Qpow(Fac[n],X-2),i=n-1;~i;--i) IFac[i]=1LL*IFac[i+1]*(i+1)%X;
	for(i=n/2+1;i<=n;++i) t=(1LL*C(n,i)*Qpow(2,n-i)+t)%X;
	return printf("%d",(Qpow(3,n)-2*t%X+X)%X),0;
}