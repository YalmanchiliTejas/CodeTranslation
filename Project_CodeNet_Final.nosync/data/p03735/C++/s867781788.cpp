#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct each{
	int x,y;
}a[N];
int bm[N],bi[N];
int n,_max,_min=INT_MAX,ak,ik;
bool com(each x,each y){
	return x.x<y.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)	swap(a[i].x,a[i].y);
		if(_max<a[i].y)	_max=a[i].y;
		if(_min>a[i].x)	_min=a[i].x;
	}
	int ml=_max,mr=_min;
	for(int i=1;i<=n;i++){
		ml=min(ml,a[i].y);
		mr=max(mr,a[i].x);
	}
	long long ans=1LL*(_max-ml)*(mr-_min);
	sort(a+1,a+n+1,com);
	ml=INT_MAX,mr=0;
	for(int i=1;i<=n;i++){
		ans=min(ans,1LL*(_max-_min)*(max(mr,a[n].x)-min(ml,a[i].x)));
		ml=min(ml,a[i].y),mr=max(mr,a[i].y);
	}

	printf("%lld\n",ans);
	return 0;
}
