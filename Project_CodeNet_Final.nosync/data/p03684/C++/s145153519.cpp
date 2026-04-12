#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<vector>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;

int n, ans;
bool vis[MaxN + 5];

struct NODE{
	int cost, u, v;
};

NODE box[MaxN + 5][3];
struct XX{
	int x, y;
	int p;
}a[MaxN + 5];

vector<NODE> que;

bool cmp1(XX x, XX y){
	return x.x < y.x;
}
bool cmp2(XX x, XX y){
	return x.y < y.y;
}
bool cmp3(NODE x, NODE y){
	return x.cost < y.cost;
}
int fa[MaxN + 5];
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &a[i].x, &a[i].y);
			a[i].p = i;
		}
		sort(a + 1, a + 1 + n, cmp1);
		for(int i = 2; i <= n; i++){
			int len = min(abs(a[i].x - a[i - 1].x), abs(a[i].y - a[i - 1].y));
			NODE temp;
			temp.cost = len, temp.u = a[i - 1].p, temp.v = a[i].p;
			que.push_back(temp);
			box[a[i].p][1].cost = len;
			box[a[i - 1].p][1].v = a[i].p;
			box[a[i].p][1].v = a[i - 1].p;
		}
		sort(a + 1, a + 1 + n, cmp2);
		for(int i = 2; i <= n; i++){
			int len = min(abs(a[i].x - a[i - 1].x), abs(a[i].y - a[i - 1].y));
			NODE temp;
			temp.cost = len, temp.u = a[i - 1].p, temp.v = a[i].p;
			que.push_back(temp);
			box[a[i].p][2].cost = len;
			box[a[i - 1].p][2].v = a[i].p;
			box[a[i].p][2].v = a[i - 1].p;
		}
		for(int i = 1; i <= n; i++){
			if(box[i][1].cost > box[i][2].cost) swap(box[i][1], box[i][2]);
		}
		int len = que.size();
		sort(que.begin(), que.end(), cmp3);
		for(int i = 1; i <= n; i++) fa[i] = i;
		LL tot = 0;
		for(int i = 0; i < len; i++){
			int u = que[i].u, v = que[i].v, cost = que[i].cost;
			if(find(u) != find(v)){
				fa[find(u)] = find(v);
				tot += cost;
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
}

