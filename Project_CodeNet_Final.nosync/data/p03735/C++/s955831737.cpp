#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int,int> mp;
const int maxn = 200005;
const int inf = 1<<30;
#define fi first
#define se second

mp c[maxn*2];int n,minx,miny,maxx,maxy;LL ans;
int bac[maxn],cnt[maxn],sum;
void insert(int x) {if (!cnt[x]++) sum++;}
void remove(int x) {if (!--cnt[x]) sum--;}
int main()
{
	#ifdef Amberframe
		freopen("arc073e.in","r",stdin);
		freopen("arc073e.out","w",stdout);
	#endif
	scanf("%d",&n);
	minx=miny=inf;maxx=maxy=-inf;
	for (int x,y,i=1;i<=n;i++) {
		scanf("%d %d",&x,&y);if (x>y) swap(x,y);
		minx=min(minx,x);maxx=max(maxx,x);
		miny=min(miny,y);maxy=max(maxy,y);
		c[i*2-1]=mp(x,i);c[i*2]=mp(y,i);
	}
	sort(c+1,c+n*2+1);
	ans=(LL)(maxx-minx)*(maxy-miny);
	for (int i=2,pos=1;i<=2*n;i++)
	{
		while (pos<=2*n&&sum<n) ++pos,insert(c[pos].se);
		if (pos>2*n) break;
		ans=min(ans,(LL)(maxy-minx)*(c[pos].fi-c[i].fi));
		remove(c[i].se);
	}
	printf("%lld",ans);
	return 0;
}