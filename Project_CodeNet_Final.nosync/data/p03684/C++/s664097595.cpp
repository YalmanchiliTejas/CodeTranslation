#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct coordinates{
	int x, y, id;
}a[MAXN];
struct edge{
	int u, v, l;
}e[MAXN*2];
int n, np, ans;
int Fa[MAXN];
bool cmp(edge x, edge y){
	return x.l < y.l;
}
bool cmpx(coordinates x, coordinates y){
	return x.x < y.x;
}
bool cmpy(coordinates x, coordinates y){
	return x.y < y.y;
}
int Find(int x){
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}
inline int read(void){
	int num = 0, f = 1;
	char ch;
	while(!isdigit(ch=getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) num = num*10 + ch-'0', ch = getchar();
	return num * f;
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read(), a[i].id = i;
	sort(a+1, a+n+1, cmpx);
	for(int i = 2; i <= n; i++)
		e[++np] = (edge){a[i-1].id, a[i].id, a[i].x - a[i-1].x};
	sort(a+1, a+n+1, cmpy);
	for(int i = 2; i <= n; i++)
		e[++np] = (edge){a[i-1].id, a[i].id, a[i].y - a[i-1].y};
	sort(e+1, e+np+1, cmp);
	for(int i = 1; i <= n; i++) Fa[i] = i;
	for(int i = 1; i <= np; i++){
		int f1 = Find(e[i].u), f2 = Find(e[i].v);
		if(f1 != f2){
			ans += e[i].l;
			Fa[f1] = f2;
		}
	}
	printf("%d\n", ans);
	return 0;
}
