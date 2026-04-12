#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N, M;
vector <pii> lv[200020];
ll T[1<<19], C[1<<19];

void pushdown(int rt) {
	if(C[rt]) {
		T[rt<<1] += C[rt], C[rt<<1] += C[rt];
		T[rt<<1|1] += C[rt], C[rt<<1|1] += C[rt];
		C[rt] = 0;
	}
}

void update(int rt, int l, int r, int s, int e, ll val) {
	if(s <= l && r <= e) {
		C[rt] += val;
		T[rt] += val;
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(s <= m) update(rt<<1, l, m, s, e, val);
	if(m < e) update(rt<<1|1, m+1, r, s, e, val);
	T[rt] = max(T[rt<<1], T[rt<<1|1]);
}

ll read(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) return T[rt];
	pushdown(rt);
	int m = (l + r) >> 1;
	ll res = -1e18;
	if(s <= m) res = max(res, read(rt<<1, l, m, s, e));
	if(m < e) res = max(res, read(rt<<1|1, m+1, r, s, e));
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i=1;i<=M;i++) {
		int l, r, a; scanf("%d%d%d", &l, &r, &a);
		lv[l].pb(pii(l-1, a));
		lv[r+1].pb(pii(l-1, -a));
	}
	ll ans = 0;
	for(int i=1;i<=N;i++) {
		for(pii e : lv[i]) {
			update(1, 0, N, 0, e.Fi, e.Se);
		}
		ll r = read(1, 0, N, 0, i - 1);
		ans = max(ans, r);
		update(1, 0, N, i, i, r);
	}
	printf("%lld\n", ans);
	return 0;
}
