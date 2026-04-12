#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100005
#define F first
#define S second
using namespace std;

struct st{
	int s, e, d;
};
int n, ans, b[N];
pair<int, int> x[N], y[N];
vector<st> a;

bool cmp(st p, st q) {return p.d < q.d;}

int f(int p) {
	if (b[p] == p) return p;
	return b[p] = f(b[p]);
}

int main()
{
	int i, t1, t2;
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%d %d", &x[i].F, &y[i].F), x[i].S = y[i].S = i;
	for (i = 1; i <= n; i++) b[i] = i;
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (i = 2; i <= n; i++) {
		a.push_back({x[i - 1].S, x[i].S, x[i].F - x[i - 1].F});
		a.push_back({y[i - 1].S, y[i].S, y[i].F - y[i - 1].F});
	}
	sort(a.begin(), a.end(), cmp);
	for (i = 0; i < a.size(); i++) {
		t1 = f(a[i].e), t2 = f(a[i].s);
		if (t1 != t2) b[t1] = t2, ans += a[i].d;
	}
    cout << ans << endl;
    return 0;
}