#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<vector>
#include<functional>
#include<string.h>
#include<limits.h>
#include<queue>
#include<deque>
#include<stack>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#define int long long
#define P pair<int,int>
using namespace std;

bool OK[100000];
struct A {
	int x, y, ID;
};
vector<P>rinsetu[100000];
A a[100000], b[100000];
signed main() {
	int c; scanf("%lld", &c);
	for (int d = 0; d < c; d++) {
		scanf("%lld%lld", &a[d].x, &a[d].y); a[d].ID = d;
		b[d] = a[d];
	}
	sort(a, a + c, [](A n, A m) {if (n.x != m.x)return n.x < m.x; return n.ID < m.ID; });
	sort(b, b + c, [](A n, A m) {if (n.y != m.y)return n.y < m.y; return n.ID < m.ID; });
	for (int i = 1; i < c; i++) {
		rinsetu[a[i - 1].ID].push_back({ a[i].x - a[i - 1].x,a[i].ID });
		rinsetu[a[i].ID].push_back({ a[i].x - a[i - 1].x,a[i-1].ID });
	}
	for (int i = 1; i < c; i++) {
		rinsetu[b[i - 1].ID].push_back({ b[i].y - b[i - 1].y,b[i].ID });
		rinsetu[b[i].ID].push_back({ b[i].y - b[i - 1].y,b[i-1].ID });
	}
	int ans = 0;
	priority_queue<P, vector<P>, greater<P>>Q;
	Q.push({ 0,0 });
	while (Q.size()) {
		P t = Q.top(); Q.pop();
		if (OK[t.second])continue;
		OK[t.second] = true;
		ans += t.first;
		for (P i : rinsetu[t.second]) {
			if (!OK[i.second]) {
				Q.push({ i.first, i.second });
			}
		}
	}
	cout << ans << endl;
}