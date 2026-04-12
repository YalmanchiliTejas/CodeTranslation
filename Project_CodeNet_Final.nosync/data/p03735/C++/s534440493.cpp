#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000;
struct point {
	int x, y;
	void read() {
		scanf("%d%d", &x, &y);
	}
	bool operator<(const point &p)const {
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
}v[N];
int n;
ll calc(ll l, ll r) {
	int mn = 1e9 + 1, mx = -1;
	vector<point> s;
	for (int i = 0; i < n; ++i) {
		if (v[i].x >= l && v[i].x <= r && v[i].y >= l && v[i].y <= r) {
			s.push_back(v[i]);
			continue;
		}
		if (v[i].x >= l && v[i].x <= r) {
			mn = min(mn, v[i].y);
			mx = max(mx, v[i].y);
		}
		else {
			mn = min(mn, v[i].x);
			mx = max(mx, v[i].x);
		}
	}
	ll res = (r - l)*max(0, (mx - mn));
	if (!s.empty())
		res = 2e18;
	int until = mn;
	set<int> pushed;
	for (int i = 0; i < s.size(); ++i) {
		while (!pushed.empty() && *pushed.begin() == s[i].x)
			pushed.erase(pushed.begin());
		int cur = s[i].x;
		bool st = false;
		if (!pushed.empty() && *pushed.begin() < s[i].x) {
			st = true;
			--i;
			cur = *pushed.begin();
			pushed.erase(pushed.begin());
		}
		if (cur > until)
			break;
		int L = cur;
		int R = max(mx, s.back().x);
		R = max(R, L);
		res = min(res, (r - l)*(R - L));
		if (st)
			continue;
		until = min(until, s[i].y);
		mx = max(mx, s[i].y);
		pushed.insert(s[i].y);
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	int mn = 1e9, mxmn = -1e9, mx = -1, mnmx = 1e9;
	for (int i = 0; i < n; ++i) {
		v[i].read();
		mn = min(mn, min(v[i].x, v[i].y));
		mxmn = max(mxmn, min(v[i].x, v[i].y));
		mnmx = min(mnmx, max(v[i].x, v[i].y));
		if (v[i].x > v[i].y)
			swap(v[i].x, v[i].y);
		mx = max(mx, v[i].y);
	}
	sort(v, v + n);
	ll res = calc(mn, mx);
	res = min(res, (mxmn - mn)*(ll)(mx - mnmx));
	printf("%lld\n", res);
	return 0;
}