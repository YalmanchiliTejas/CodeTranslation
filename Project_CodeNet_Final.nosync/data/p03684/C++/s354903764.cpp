#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
const int MaxN = 1e5;
typedef long long LL;
using namespace std;
queue <int> que;
struct NODE{
	int x , y , w;
	int pos;
}a[MaxN + 5] , b[MaxN + 5];
bool cmp(NODE x , NODE y){
	return x.x < y.x;
}
bool cmp1(NODE x , NODE y){
	return x.y < y.y;
}
bool cmp2(NODE x , NODE y){
	return x.w < y.w;
}
int n  , fa[MaxN + 5];
int Find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = Find(fa[x]);
}
int main()
{
	while(~scanf("%d" , &n)){
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= n;i++){
			scanf("%d%d" , &a[i].x , &a[i].y);
			a[i].pos = i;
		}
		int tot = 0;
		sort(a + 1 , a + n + 1 , cmp);
		for(int i = 2;i <= n;i++){
			int w = a[i].x - a[i - 1].x;
			int u = min(a[i - 1].pos , a[i].pos) , v = max(a[i].pos , a[i - 1].pos);
			b[++tot].x = u;
			b[tot].y = v;
			b[tot].w = w;
		}
		sort(a + 1 , a + n + 1 , cmp1);
		for(int i = 2;i <= n;i++){
			int w = a[i].y - a[i - 1].y;
			int u = min(a[i - 1].pos , a[i].pos), v = max(a[i].pos , a[i - 1].pos);
			b[++tot].x = u;
			b[tot].y = v;
			b[tot].w = w;
		}
		sort(b + 1, b + tot + 1 , cmp2);
		LL ans = 0;
		for(int i = 1;i <= tot;i++){
			int x = Find(b[i].x) , y = Find(b[i].y);
			if(x != y){
				fa[x] = y;
				ans += b[i].w;
			}
		}
		printf("%lld\n" , ans);
	}
}