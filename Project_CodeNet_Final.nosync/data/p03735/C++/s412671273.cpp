#include<bits/stdc++.h>
#define PAIR pair<int,int>
#define N 200005
#define oo (1<<30)
#define LL long long
using namespace std;
int n,mx,mn,Min,Max; PAIR a[N]; LL ans;
int main()
{
	int i;
	scanf("%d",&n),mx=-oo,mn=oo;
	for(i=1;i<=n;i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
		mx=max(mx,a[i].second);
		mn=min(mn,a[i].second);
	  }
	sort(a+1,a+n+1);
	ans=1LL*(a[n].first-a[1].first)*(mx-mn);
	Min=Max=a[1].second;
	for(i=2;i<=n;i++){
		ans=min(ans,1LL*(mx-a[1].first)*(max(Max,a[n].first)-min(Min,a[i].first)));
		Min=min(Min,a[i].second);
		Max=max(Max,a[i].second);
	  }
	cout<<ans;
	return 0;
}
