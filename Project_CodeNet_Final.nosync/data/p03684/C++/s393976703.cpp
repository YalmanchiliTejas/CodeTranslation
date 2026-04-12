#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100009;
struct edge{
	int x, y, w;
	bool operator < (const edge &e){
		return w < e.w;
	}
} e[maxn*2];
struct point{
	int x, y, pos;
} p[maxn];
int n, pa[maxn];
long long ans;

inline bool cmpX(point a, point b){
	return a.x < b.x;
}

inline bool cmpY(point a, point b){
	return a.y < b.y;
}

int getpa(int x){
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].pos = i;
	}
	
	sort(p+1, p+n+1, cmpX);
	for (int i=1; i<=n-1; i++){
		e[i].x = p[i].pos;
		e[i].y = p[i+1].pos;
		e[i].w = p[i+1].x - p[i].x;
	}

	sort(p+1, p+n+1, cmpY);
	for (int i=1; i<=n-1; i++){
		e[n-1+i].x = p[i].pos;
		e[n-1+i].y = p[i+1].pos;
		e[n-1+i].w = p[i+1].y - p[i].y;
	}
	
	for (int i=1; i<=n; i++) pa[i] = i;
	sort(e+1, e+2*n-2+1);
	for (int i=1; i<=2*n-2; i++){
		if (getpa(e[i].x) == getpa(e[i].y)) continue;
		pa[getpa(e[i].x)] = getpa(e[i].y);
		ans += e[i].w;
	}
	printf("%lld\n", ans);
	
	return 0;
}