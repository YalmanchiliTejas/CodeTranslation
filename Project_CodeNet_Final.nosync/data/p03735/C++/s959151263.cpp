#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	ll x,y;
}a[500001];
ll n,rmx,rmn,bmx,bmn,ans,mx[500001],mn[500001];
bool cmp(aaa a,aaa b){
	return a.x<b.x;
}
int main(){
	ll i,hh;
	bmx=rmx=-1;
	bmn=rmn=2e9;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
	 scanf("%lld%lld",&a[i].x,&a[i].y);
	 if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	 rmx=max(rmx,a[i].x);rmn=min(rmn,a[i].x);
	 bmx=max(bmx,a[i].y);bmn=min(bmn,a[i].y);
  }
  ans=(bmx-bmn)*(rmx-rmn);
  sort(a+1,a+n+1,cmp);
  hh=2e9;
  mx[1]=mn[1]=a[1].y;
  for(i=2;i<n;i++){
  	mx[i]=max(mx[i-1],a[i].y);
  	mn[i]=min(mn[i-1],a[i].y);
  	hh=min(hh,max(mx[i],a[n].x)-min(mn[i],a[i+1].x));
  }
  //printf("%lld\n",hh);
  printf("%lld",min(ans,hh*(bmx-rmn)));
}
/*
对于最大最小的都在一起的情况只会一个有点麻烦的移动队列扫过去的做法
看完题解才知道可以贪心 
*/