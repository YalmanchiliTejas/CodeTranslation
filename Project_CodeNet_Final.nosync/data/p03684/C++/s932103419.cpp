#include <iostream>
#include <cstdio>
#include <algorithm>
#define S second
#define F first
#define S second
#define N 100005
using namespace std;

typedef long long ll;
#define PI pair<ll, ll>
ll n, x, y, sz, s, bu[N];
PI a[N], b[N];
struct st {
	ll c1, c2, c3;
}c[200005];

bool comp(st p, st q) {
	return p.c1 < q.c1;
}

ll f(ll p) {
	if (bu[p] == p) return p;
	return bu[p] = f(bu[p]);
}
int main()
{
	ll i,t1, t2;
	cin >> n;
	for (i = 0; i <n; i++) {
		scanf ("%lld %lld", &x, &y);
		a[i].F = x;
		a[i].S = i;
		b[i].F = y;
		b[i].S = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (i = 0; i < n - 1; i++) {
		c[sz++] = {a[i + 1].F - a[i].F, a[i].S, a[i + 1].S};
	}
	for (i = 0; i < n - 1; i++) {
		c[sz++] = {b[i + 1].F - b[i].F, b[i].S, b[i + 1].S};
	}
	sort(c, c + sz, comp);
	for (i = 1; i <= n; i++) bu[i] = i;
	for (i = 0; i < n * 2 - 1; i++){
		t1 = f(c[i].c2);
		t2 = f(c[i].c3);
		if (t1 != t2) {
			bu[t1] =t2;
			s += c[i].c1;
		}
	}
	cout << s;
    return 0;
}
