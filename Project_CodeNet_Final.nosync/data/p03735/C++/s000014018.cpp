#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=2e5+5;
pair<int,int>a[N];
int n,Maxs,Mins=1e9+5;
long long ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i].first,&a[i].second);
	rep(i,1,n){
		if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
		Maxs=max(Maxs,a[i].second);
		Mins=min(Mins,a[i].second);
	}
	sort(a+1,a+n+1);
	ans=1LL*(Maxs-Mins)*(a[n].first-a[1].first);
	Mins=a[1].first;
	int Max=max(a[1].second,a[n].first),Min=min(a[1].second,a[n].first);
	rep(i,2,n){
		Max=max(Max,a[i].second);
		Min=min(Min,a[i].second);
		if(i!=n) ans=min(ans,1LL*(Max-min(Min,a[i+1].first))*(Maxs-Mins));
	}
	printf("%lld\n",ans);
	return 0;
}
