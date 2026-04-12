#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional>
using namespace std;
#define ll long long
#define ull unsigned ll
struct node {
	int id;
	pair<int, int> coor;
};
struct EDGE {
	int fr, to, di;
	EDGE() {}
	EDGE(int F, int T, int D) {
		fr=F;
		to=T;
		di=D;
	}
};
int n;
node a[100005];
vector<EDGE> v;
bool cmp1(const node& t1, const node& t2) {
	return t1.coor.first<t2.coor.first;
}
bool cmp2(const node& t1, const node& t2) {
	return t1.coor.second<t2.coor.second;
}
bool cmp3(const EDGE& t1, const EDGE& t2) {
	return t1.di<t2.di;
}
int calcdist(node t1, node t2) {
	return min(abs(t1.coor.first-t2.coor.first), abs(t1.coor.second-t2.coor.second));
}
int fa[100005];
int Find(int x) {
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
ll kruskal() {
	ll res=0ll;
	for (int i=0; i<n; i++)
		fa[i]=i;
	for (int i=0; i<v.size(); i++) {
		int rx=Find(v[i].fr), ry=Find(v[i].to);
		if (rx==ry) continue;
		res+=(ll)v[i].di;
		fa[rx]=ry;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &a[i].coor.first, &a[i].coor.second);
		a[i].id=i;
	}
	sort(a, a+n, cmp1);
	for (int i=1; i<n; i++) {
		v.push_back(EDGE(a[i-1].id, a[i].id, calcdist(a[i-1], a[i])));
	}
	sort(a, a+n, cmp2);
	for (int i=1; i<n; i++) {
		v.push_back(EDGE(a[i-1].id, a[i].id, calcdist(a[i-1], a[i])));
	}
	sort(v.begin(), v.end(), cmp3);
	printf("%lld", kruskal());
	return 0;
}