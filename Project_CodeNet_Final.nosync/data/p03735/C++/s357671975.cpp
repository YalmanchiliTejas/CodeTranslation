#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define N 200002
using namespace std;
struct ball{
	int x,y;
}a[N];
int n,i,maxx,minx=1<<30,r[N],b[N];
int my_comp(const ball &a,const ball &b)
{
	return a.x<b.x;
}
signed main()
{
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		maxx=max(maxx,a[i].y);
		minx=min(minx,a[i].x);
	}
	int rmax=0,bmin=1<<30,bmax,tmp=1<<30;
	for(i=1;i<=n;i++){
		rmax=max(rmax,a[i].x);
		bmin=min(bmin,a[i].y);
	}
	int ans=(maxx-bmin)*(rmax-minx);
	sort(a+1,a+n+1,my_comp);
	for(i=1;i<=n;i++) b[i]=a[i].x,r[i]=a[i].y;
	bmax=b[n];
	for(i=1;i<n;i++){
		bmax=max(bmax,r[i]);
		tmp=min(tmp,r[i]);
		bmin=min(tmp,b[i+1]);
		ans=min(ans,(maxx-minx)*(bmax-bmin));
	}
	cout<<ans<<endl;
	return 0;
}
