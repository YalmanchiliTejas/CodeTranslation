#include<bits/stdc++.h>
using namespace std;
struct yyy {
	long long x,y;
} ball[222222];
long long x[222222],y[222222],maxn[222222],minl[222222];
long long n,ans,ans1,ans2,bmax,bmin,rmax,rmin;
bool cmp(yyy a,yyy b) {
	return a.x<b.x;
}
int main() {
	cin>>n;
	bmax=rmax=-1;
	bmin=rmin=1999999999;
	for(int i=1; i<=n; ++i) {
		cin>>x[i]>>y[i];
		if(x[i]>y[i])
			swap(x[i],y[i]);
		ball[i].x=x[i];
		ball[i].y=y[i];
		bmax=max(bmax,y[i]);
		bmin=min(bmin,y[i]);
		rmax=max(rmax,x[i]);
		rmin=min(rmin,x[i]);
	}
	ans1=(bmax-bmin)*(rmax-rmin);
	bmin=rmin;
	sort(ball+1,ball+n+1,cmp);
	ans2=1999999999;
	maxn[1]=minl[1]=ball[1].y;
	for(int i=2; i<=n; ++i) {
		maxn[i]=max(maxn[i-1],ball[i].y);
		minl[i]=min(minl[i-1],ball[i].y);
		if(i!=n)
			ans2=min(ans2,max(maxn[i],ball[n].x)-min(minl[i],ball[i+1].x));
	}
	ans2*=(bmax-bmin);
	ans=min(ans1,ans2);
	cout<<ans<<endl;
	return 0;
}