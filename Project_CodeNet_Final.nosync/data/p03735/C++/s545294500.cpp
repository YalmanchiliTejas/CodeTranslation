#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
struct Card
{
	int x,y;
	inline friend bool operator < (Card a,Card b)
		{
			if(a.x==b.x) return a.y<b.y;
			return a.x<b.x;
		}
}card[maxn];
int Rmax,Rmin,Bmax,Bmin,maxpos,minpos;
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&card[i].x,&card[i].y);
		if(card[i].x>card[i].y) swap(card[i].x,card[i].y);
	}
	sort(card+1,card+n+1);
	int maxy=card[1].y,minx=card[1].x;
	for(int i=1;i<=n;++i)
	{
		if(card[i].x<=minx&&card[i].y>=maxy)
		{
			maxpos=minpos=i;
			minx=card[i].x,maxy=card[i].y;
		}
		else if(card[i].x<minx)
		{
			minpos=i;
			minx=card[i].x;
		}
		else if(card[i].y>maxy)
		{
			maxpos=i;
			maxy=card[i].y;
		}
	}
	Rmax=maxy,Bmin=minx;
	Rmin=card[minpos].y,Bmax=card[maxpos].x;
	for(int i=1;i<=n;++i)
	{
		Rmin=min(Rmin,card[i].y);
		Bmax=max(Bmax,card[i].x);
	}
	long long ans=1ll*(Rmax-Rmin)*(Bmax-Bmin);
	if(maxpos!=minpos)
	{
		Bmax=maxy,Bmin=minx;
		Rmax=max(card[n].x,card[1].y);
		int premin=card[1].y;
		Rmin=min(card[1].y,card[2].x);
		int tmp=Rmax-Rmin;
		for(int i=2;i<n;++i)
		{
			Rmax=max(card[i].y,Rmax);
			Rmin=min(min(card[i].y,premin),card[i+1].x);
			premin=min(premin,card[i].y);
			if(Rmax-Rmin<tmp) tmp=Rmax-Rmin;
		}
		ans=min(ans,1ll*tmp*(Bmax-Bmin));
	}
	printf("%lld\n",ans);
	return 0;
}