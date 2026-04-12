#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define in inline
#define get getchar()
in int read()
{
	int t=0; char ch=get;
	while (ch<'0' || ch>'9') ch=get;
	while (ch<='9' && ch>='0') t=t*10+ch-'0',ch=get;
	return t;
}
const int _=2e5+5;
ll n,maxb,maxr,minb,minr,maxx[_],minn[_];
struct yzx{
	ll x,y;
}a[_];
in ll cmp(yzx a,yzx b)
{
	return a.x<b.x;
}
int main()
{
	n=read();
	minr=minb=0x3f3f3f3f3f3f3f3f;
	for(re int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(x>y)swap(x,y);
		a[i].x=x,a[i].y=y;
		minr=min(minr,a[i].x);
		maxr=max(maxr,a[i].x);
		maxb=max(maxb,a[i].y);
		minb=min(minb,a[i].y);
	}
	ll ans1=(maxb-minb)*(maxr-minr),ans2=0x3f3f3f3f3f3f3f3f;
	minb=minr;
	sort(a+1,a+n+1,cmp);
	maxx[1]=minn[1]=a[1].y;
	for (re int i=2;i<=n;i++)
	{
		maxx[i]=max(maxx[i-1],a[i].y);
		minn[i]=min(minn[i-1],a[i].y);
		if(i!=n) ans2=min(ans2,max(maxx[i],a[n].x)-min(minn[i],a[i+1].x));
	}
	ans2=ans2*(maxb-minb);
	cout<<min(ans1,ans2)<<endl;
	return 0;
}
