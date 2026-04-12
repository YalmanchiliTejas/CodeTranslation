#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200006
using namespace std;
struct arr{int x,y;}e[N];
int n,mi,ma,mima,mami;long long ans;
bool cmp(arr x,arr y)
{
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	scanf("%d",&n);
	mi=mami=1000000000;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&e[i].x,&e[i].y);
		if(e[i].x>e[i].y)swap(e[i].x,e[i].y);
		mi=min(mi,e[i].x);ma=max(ma,e[i].y);
		mima=max(mima,e[i].x);mami=min(mami,e[i].y);
	}
	sort(e+1,e+n+1,cmp);ans=1LL*(mima-mi)*(ma-mami);
	for(int i=1;i<=n;i++){
		if(e[i].x>mami){
			ans=min(ans,1LL*(ma-mi)*(mima-mami));
			break;
		}
		ans=min(ans,1LL*(ma-mi)*(mima-e[i].x));
		mima=max(mima,e[i].y);
	}
	printf("%lld\n",ans);
}