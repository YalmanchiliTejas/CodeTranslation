#include<bits/stdc++.h>
#define MAXN 200000+5
using namespace std;
typedef long long LL;
struct node
{
	LL x,y;
}P[MAXN];
LL n,minans=LLONG_MAX;
LL Rmax,Rmin,Lmax,Lmin;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&P[i].x,&P[i].y);
	}
	for(int k=1;k<=100;k++)
	{
		srand(time(0));
		random_shuffle(P+1,P+n+1);
		Rmax=Rmin=P[1].x,Lmax=Lmin=P[1].y;
		for(int i=2;i<=n;i++)
		{
			LL rmax=Rmax,rmin=Rmin,lmax=Lmax,lmin=Lmin,ans=0;
			rmax=max(rmax,P[i].x),rmin=min(rmin,P[i].x);
			lmax=max(lmax,P[i].y),lmin=min(lmin,P[i].y);
			ans=(rmax-rmin)*(lmax-lmin);
			rmax=Rmax,rmin=Rmin,lmax=Lmax,lmin=Lmin;
			swap(P[i].x,P[i].y);
			rmax=max(rmax,P[i].x),rmin=min(rmin,P[i].x);
			lmax=max(lmax,P[i].y),lmin=min(lmin,P[i].y);
			if(ans>(rmax-rmin)*(lmax-lmin))
			{
				Rmax=max(Rmax,P[i].x),Rmin=min(Rmin,P[i].x);
				Lmax=max(Lmax,P[i].y),Lmin=min(Lmin,P[i].y);
			}
			else
			{
				Rmax=max(Rmax,P[i].y),Rmin=min(Rmin,P[i].y);
				Lmax=max(Lmax,P[i].x),Lmin=min(Lmin,P[i].x);
			}
		}
		minans=min(minans,(Rmax-Rmin)*(Lmax-Lmin));
	}
	printf("%lld ",minans);
	return 0;
}
