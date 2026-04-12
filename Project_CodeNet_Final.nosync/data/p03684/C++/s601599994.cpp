#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef long double ld;
int n, pa[100000];
struct A {
	int x, a;
};
bool operator<(A a, A b) { return a.x < b.x; }
struct B {
	int y, a;
};
bool operator<(B a, B b) { return a.y < b.y; }
struct C {
	int from, to, cost;
};
bool operator<(C a, C b) { return a.cost < b.cost; }
A a[100001];
B b[100001];
vector<C>c;
int root(int x) {
	if (pa[x] == x) return x;
	return pa[x] = root(pa[x]);
}
void unite(int x, int y) {
	x = root(x);
	y = root(y);
	pa[x] = y;
}
signed  main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = { x,i };
		b[i] = { y,i };
		pa[i] = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n-1; i++) {
		c.push_back(C{ a[i].a,a[i + 1].a,a[i + 1].x - a[i].x });
		c.push_back(C{ b[i].a,b[i + 1].a,b[i + 1].y - b[i].y });
	}
	sort(c.begin(), c.end());
	int sum = 0;
	for (int i = 0; i < c.size(); i++) {
		if (root(c[i].from) == root(c[i].to)) continue;
		unite(c[i].from, c[i].to);
		sum += c[i].cost;
	}
	cout << sum << endl;
	getchar(); getchar();
}