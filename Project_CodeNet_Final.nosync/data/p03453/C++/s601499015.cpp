#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

typedef long long LL;
const int P = 1e9 + 7;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, S, T; LL ans;
struct D{int x, y, v;} a[M];
struct edge{int ed, ne, v;} e[M<<1]; int he[N], en;
LL dis1[N], dis2[N], kry, num1[N], num2[N];
queue<int> q; bool inq[N];
int d[N];
LL zyf[N+M], sum; int cnt;

void ins(int a, int b, int c) {
	e[++en].ed = b; e[en].v = c; e[en].ne = he[a]; he[a] = en;
}

bool cmp1(int a, int b) {return dis1[a] > dis1[b];}
bool cmp2(int a, int b) {return dis2[a] > dis2[b];}

int main() {
	int i, j, u, v;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &S, &T);
	rep(i, 1, m) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
		ins(a[i].x, a[i].y, a[i].v);
		ins(a[i].y, a[i].x, a[i].v);
	}
	
	rep(i, 1, n) d[i] = i;
	
	rep(i, 1, n) dis1[i] = 0x3f3f3f3f3f3f3f;
	q.push(S); dis1[S] = 0;
	while(!q.empty()) {
		u = q.front(); inq[u] = 0; q.pop();
		for(i = he[u]; i; i = e[i].ne)
		if(dis1[u] + e[i].v < dis1[e[i].ed]) {
			v = e[i].ed;
			dis1[v] = dis1[u] + e[i].v;
			if(!inq[v]) {q.push(v); inq[v] = 1;}
		}
	}
	
	sort(d+1, d+n+1, cmp1);
	num1[T] = 1;
	rep(i, 1, n) {
		u = d[i];
		for(j = he[u]; j; j = e[j].ne)
		if(dis1[u] + e[j].v == dis1[e[j].ed]) num1[u] = (num1[u] + num1[e[j].ed]) % P;
	}
//	rep(i, 1, n) printf("%d ", d[i]); puts("");
//	rep(i, 1, n) printf("%lld ", dis1[i]); puts("");
//	rep(i, 1, n) printf("%lld ", num1[i]); puts("");
	
	
	rep(i, 1, n) dis2[i] = 0x3f3f3f3f3f3f3f;
	q.push(T); dis2[T] = 0;
	while(!q.empty()) {
		u = q.front(); inq[u] = 0; q.pop();
		for(i = he[u]; i; i = e[i].ne)
		if(dis2[u] + e[i].v < dis2[e[i].ed]) {
			v = e[i].ed;
			dis2[v] = dis2[u] + e[i].v;
			if(!inq[v]) {q.push(v); inq[v] = 1;}
		}
	}
	
	sort(d+1, d+n+1, cmp2);
	num2[S] = 1;
	rep(i, 1, n) {
		u = d[i];
		for(j = he[u]; j; j = e[j].ne)
		if(dis2[u] + e[j].v == dis2[e[j].ed]) num2[u] = (num2[u] + num2[e[j].ed]) % P;
	}
//	rep(i, 1, n) printf("%lld ", dis1[i]); puts("");
//	rep(i, 1, n) printf("%lld ", dis2[i]); puts("");
	
	kry = dis1[T];
	rep(i, 1, n) 
	if(dis1[i]*2 == kry) zyf[++cnt] = num1[i] * num2[i] % P;
	rep(i, 1, m) {
		u = a[i].x; v = a[i].y;
		if(dis1[u] > dis1[v]) swap(u, v);
		if(dis1[u] + a[i].v == dis1[v] && dis1[u]*2 < kry && dis1[v]*2 > kry) zyf[++cnt] = num2[u] * num1[v]%P;
	}
	rep(i, 1, cnt) sum = (sum + zyf[i]) % P;
	rep(i, 1, cnt) ans = (ans + zyf[i] * (sum - zyf[i]) % P + P) % P;
	printf("%lld\n", ans);
	return 0;
}