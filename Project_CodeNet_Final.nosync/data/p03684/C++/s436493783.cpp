#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#define maxn 100009
using namespace std;
long long fact[maxn];
struct node{
	int x, y;
	int id;
}a[maxn];
struct edge{
	int u, v, w;
	bool operator < (const edge &rhs)const{
		return w < rhs.w;
	}
}e[maxn * 10];
int p[maxn];
int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}
void unionset(int x, int y){
	p[findset(x)] = findset(y);
}
bool cmp1(node a, node b){
	return a.x < b.x;
}
bool cmp2(node a, node b){
	return a.y < b.y;
}
long long mst(int n, int tot){
	sort(e, e + tot);
	for(int i = 0; i < n; i++)
		p[i] = i;
	long long ans = 0;
	for(int i = 0; i < tot; i++){
		int u = e[i].u;
		int v = e[i].v;
		if(findset(u) == findset(v))
			continue;
		ans += e[i].w;
		unionset(u ,v);
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	int tot = 0;
	sort(a, a + n ,cmp1);
	for(int i = 1; i < n; i++){
		e[tot].u = a[i - 1].id;
		e[tot].v = a[i].id;
		e[tot].w = min(abs(a[i].x - a[i - 1].x), abs(a[i].y - a[i - 1].y));
		tot++;
	}
	sort(a, a + n, cmp2);
	for(int i = 1; i < n; i++){
		e[tot].u = a[i - 1].id;
		e[tot].v = a[i].id;
		e[tot].w = min(abs(a[i].x - a[i - 1].x), abs(a[i].y - a[i - 1].y));
		tot++;
	}
	cout << mst(n, tot) << endl;
	return 0;
}