#include<bits/stdc++.h>
#define ll long long
#define rg register
using namespace std;
const int MAXN=4e5+10;
const int Inf=2147483647;
int n,Ls,Maxs,Mins,A[MAXN],B[MAXN],Lsh[MAXN<<1];
ll Ans=1e18;
inline int Read()
{   rg int a=0,c=1;   rg char b=getchar();
	while(b!='-'&&(b<'0'||b>'9'))b=getchar();
	if(b=='-')c=-1,b=getchar();
	while(b>='0'&&b<='9')a=a*10+b-48,b=getchar();
	return a*c;
}
inline int Abs(rg int A){   return A>0?A:-A;   }
inline ll Max(rg ll A,rg ll B){   return A>B?A:B;   }
inline ll Min(rg ll A,rg ll B){   return A<B?A:B;   }
namespace Part1
{   int Mint[MAXN<<2],Lan[MAXN<<2];
	inline void Push_Lan(rg int S,rg int Num){   Mint[S]=Min(Mint[S],Num),Lan[S]=Min(Lan[S],Num);   }
	inline void Push_down(rg int S){   Push_Lan(S<<1,Lan[S]),Push_Lan(S<<1|1,Lan[S]),Lan[S]=Inf;   }
	inline int Modify(rg int S,rg int Le,rg int Ri,rg int Al,rg int Ar,rg int Num)
	{   if(Al>Ar) return 0;
		if(Al<=Le&&Ri<=Ar) return Push_Lan(S,Num),0;   rg int Mid=(Le+Ri)>>1;
		Push_down(S),Al<=Mid?Modify(S<<1,Le,Mid,Al,Ar,Num):0,Mid<Ar?Modify(S<<1|1,Mid+1,Ri,Al,Ar,Num):0;
	}
	inline int Query(rg int S,rg int Le,rg int Ri,rg int Aim)
	{   if(Le==Ri) return Mint[S];   rg int Mid=(Le+Ri)>>1;
		return Push_down(S),Aim<=Mid?Query(S<<1,Le,Mid,Aim):Query(S<<1|1,Mid+1,Ri,Aim);
	}
	inline void Get_Ans1()
	{   rg int Pos1=0,Pos2=0,Pos3=0,Pos4=0,Lim=0;
		for(rg int i=1;i<=n&&!Pos1;i++) if(A[i]==Ls||B[i]==Ls) Pos1=i;
		for(rg int i=1;i<=n&&!Pos4;i++) if(A[i]==1||B[i]==1) Pos4=i;
		for(rg int i=1;i<=n;i++) if(A[i]==Ls||B[i]==Ls) Pos3=i;
		for(rg int i=1;i<=n;i++) if(A[i]==1||B[i]==1) Pos2=i;
		if(Pos1==Pos3&&Pos2==Pos4&&Pos1==Pos2) return ;
		for(rg int i=1;i<=Ls<<2;i++) Mint[i]=Lan[i]=Inf;
		for(rg int i=1;i<=n;i++) Modify(1,1,Ls,A[i]+1,Ls,Lsh[A[i]]),Modify(1,1,Ls,B[i],A[i]-1,Lsh[B[i]]);
		for(rg int i=1;i<=n;i++) Lim=Max(Lim,B[i]);
		for(rg int i=Ls;i>=Lim;i--) Ans=Min(Ans,1ll*(Maxs-Mins)*(Lsh[i]-Query(1,1,Ls,i)));
	}
}using Part1::Get_Ans1;
inline void Get_Ans2()
{   rg int Minr=Inf,Maxb=0;
	for(rg int i=1;i<=n;i++) Minr=Min(Minr,A[i]),Maxb=Max(Maxb,B[i]);
	Ans=Min(Ans,1ll*(Maxs-Lsh[Minr])*(Lsh[Maxb]-Mins));
}
int main()
{   n=Read(),Mins=Inf;
	for(rg int i=1;i<=n;i++) A[i]=Read(),B[i]=Read(),A[i]<B[i]?swap(A[i],B[i]):(void)0;
	for(rg int i=1;i<=n;i++) Maxs=Max(Maxs,A[i]),Mins=Min(Mins,B[i]),Lsh[++Ls]=A[i],Lsh[++Ls]=B[i];
	sort(Lsh+1,Lsh+Ls+1),Ls=unique(Lsh+1,Lsh+Ls+1)-Lsh-1;
	for(rg int i=1;i<=n;i++) A[i]=lower_bound(Lsh+1,Lsh+Ls+1,A[i])-Lsh,B[i]=lower_bound(Lsh+1,Lsh+Ls+1,B[i])-Lsh;
	Get_Ans1(),Get_Ans2(),printf("%lld\n",Ans);
}
