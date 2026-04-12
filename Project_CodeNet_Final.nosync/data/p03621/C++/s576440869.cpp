#include<bits/stdc++.h>
#define ll long long
#define rg register
using namespace std;
const int MAXN=66e3+10;
const int Mod=998244353;
char Sa[MAXN],Sb[MAXN];
int Ls,Ys,Gs,G[MAXN],Invf[MAXN],Fac[MAXN]={1};
int Ans,F[MAXN],Help[MAXN],Di[MAXN];
inline int Read()
{   rg int a=0,c=1;   rg char b=getchar();
    while(b!='-'&&(b<'0'||b>'9'))b=getchar();
    if(b=='-')c=-1,b=getchar();
    while(b>='0'&&b<='9')a=a*10+b-48,b=getchar();
    return a*c;
}
inline int Fast(rg int Di,rg int Mi)
{   rg int Back=1;
    for(;Mi>=1;Mi>>=1,Di=1ll*Di*Di%Mod)
	if(Mi&1) Back=1ll*Back*Di%Mod;
    return Back;
}
namespace Poly
{   int Len,Ms,Invl,A[MAXN],B[MAXN],Rader[MAXN];
    inline void NTT(int *P,rg int opt)
    {   for(rg int i=0;i<Len;i++)
	    if(i<Rader[i]) swap(P[i],P[Rader[i]]);
	for(rg int i=1;i<Len;i<<=1)
	{   rg int Euler=Fast(3,(Mod-1)/(i<<1));
	    if(opt<0) Euler=Fast(Euler,Mod-2);
	    for(rg int Pos=i<<1,j=0;j<Len;j+=Pos)
	    {   rg int Wi=1;
		for(rg int k=0;k<i;k++,Wi=1ll*Wi*Euler%Mod)
		{   rg int X=P[j+k],Y=1ll*Wi*P[i+j+k]%Mod;
		    P[j+k]=(X+Y)%Mod,P[i+j+k]=(1ll*X-Y+Mod)%Mod;
		}
	    }
	}
	if(opt>0) return ;   Invl=Fast(Len,Mod-2);
	for(rg int i=0;i<Len;i++) P[i]=1ll*P[i]*Invl%Mod;
    }
    inline void Prepare(rg int Lx)
    {   Ms=-1;
	for(Len=1;Len<=Lx;Len<<=1) Ms++;
	for(rg int i=0;i<Len;i++) Rader[i]=(Rader[i>>1]>>1)|((i&1)<<Ms);
    }
    inline void Get_Mul(int *X,int *Y,int *T,rg int Lx)
    {   Prepare(Lx<<1);
	for(rg int i=0;i<Lx;i++) A[i]=X[i],B[i]=Y[i];
	for(rg int i=Lx;i<Len;i++) A[i]=B[i]=0;
	NTT(A,1),NTT(B,1);
	for(rg int i=0;i<Len;i++) A[i]=1ll*A[i]*B[i]%Mod;
	NTT(A,-1);
	for(rg int i=0;i<Len;i++) T[i]=A[i];
    }
    inline void Get_Fast(int *X,int *T,rg int Lx,rg int Mi)
    {   if(!Mi)
	{   for(rg int i=0;i<Lx;i++) T[i]=0;
	    return T[0]=1,(void)0;
	}
	Prepare(Lx<<1),Mi--;
	for(rg int i=0;i<Len;i++) Help[i]=Di[i]=X[i];
	for(;Mi>=1;Mi>>=1,Get_Mul(Di,Di,Di,Lx))
	    if(Mi&1) Get_Mul(Help,Di,Help,Lx);
	for(rg int i=0;i<Lx;i++) T[i]=Help[i];
    }
}using Poly::Get_Fast;using Poly::Get_Mul;using Poly::Prepare;
int main()
{   scanf("%s\n%s",Sa+1,Sb+1),Ls=strlen(Sa+1);
    for(rg int i=1;i<=Ls;i++)
	Ys+=Sa[i]=='1'&&Sb[i]!='1',Gs+=Sa[i]=='1'&&Sb[i]=='1';
    for(rg int i=1;i<=2*Ls;i++) Fac[i]=1ll*Fac[i-1]*i%Mod;
    Invf[2*Ls]=Fast(Fac[2*Ls],Mod-2);
    for(rg int i=2*Ls-1;i>=0;i--) Invf[i]=1ll*Invf[i+1]*(i+1)%Mod;
    for(rg int i=0;i<=Gs;i++) G[i]=Invf[i+1];
    F[0]=1,Get_Fast(G,G,Gs+1,Ys),Get_Mul(F,G,F,Gs+1);
    for(rg int i=0;i<=Gs;i++) Ans=(Ans+F[i])%Mod;
    printf("%lld\n",1ll*Ans*Fac[Ys]%Mod*Fac[Gs]%Mod*Fac[Ys+Gs]%Mod);
}
