#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;

ll const MAX = 800010;
ll const A_MAX = 200005;
ll tree[MAX];
ll lazy[MAX];
ll n_ = 1;

void init(ll n) {
	while (n_ <= n) {
		n_ *= 2;
	}
	REP(i, 1, n_ * 2) {
		tree[i] = lazy[i] = 0;
	}
}

void add_o(ll u, ll v, ll x, ll k, ll l, ll r) {
	if (u <= l && r <= v) {
		if (r - l > 1) {
			lazy[k] += x;
		}
		else {
			tree[k] += x;
		}
	}
	else if (!(r <= u || v <= l)) {
		add_o(u, v, x, k * 2, l, (l + r) / 2);
		add_o(u, v, x, k * 2 + 1, (l + r) / 2, r);
	}
	if (r - l > 1) {
		tree[k] = max(tree[k * 2], tree[k * 2 + 1]) + lazy[k];
	}
}

ll query_o(ll u, ll v, ll k, ll l, ll r) {
	if (lazy[k] != 0 && r - l > 1) {
		lazy[k * 2] += lazy[k];
		lazy[k * 2 + 1] += lazy[k];
		tree[k * 2] += lazy[k];
		tree[k * 2 + 1] += lazy[k];
		lazy[k] = 0;
	}
	if (u <= l && r <= v) {
		return tree[k];
	}
	else if (r <= u || v <= l) {
		return -1e18;
	}
	else {
		ll ans1 = query_o(u, v, k * 2, l, (l + r) / 2);
		ll ans2 = query_o(u, v, k * 2 + 1, (l + r) / 2, r);
		return max(ans1, ans2);
	}
}


void add(ll l, ll r, ll x) {
	add_o(l, r, x, 1, 0, n_);
}

ll query(ll l, ll r) {
	return query_o(l, r, 1, 0, n_);
}

ll n, m;

struct range {
	ll l; ll r; ll v;
};
range a[MAX], b[MAX];
ll maxv[MAX] = {};
bool ord1(range x, range y) {
	return x.l < y.l;
}
bool ord2(range x, range y) {
	return x.r < y.r;
}

int main() {
	cin >> n >> m;
	REP(i, 1, m) {
		ll x, y, z;
		cin >> x >> y >> z;
		a[i] = b[i] = { x,y + 1,z };
	}
	init(n + 3);
	SORT_O(a, m, ord1);
	SORT_O(b, m, ord2);
	ll ttt = 1e18;
	a[m + 1] = b[m + 1] = { ttt,ttt,ttt };
	ll cur_a = 1; ll cur_b = 1;
	REP(i, 1, n) {
		while (a[cur_a].l == i) {
			add(0, a[cur_a].l, a[cur_a].v);
			cur_a++;
			//cout << i << " " << a[cur_a].l << " " << a[cur_a].v << endl;
		}
		while (b[cur_b].r == i) {
			add(0, b[cur_b].l, -b[cur_b].v);
			//cout << i << " " << b[cur_b].l << " " << -b[cur_b].v << endl;

			cur_b++; 
		}		
		ll x = query(0, i);
		add(i, i + 1, x);	
		maxv[i] = x;
		//cout << maxv[i] << endl;
	}
	ll ans = 0;
	REP(i, 1, n) {
		ans = max(maxv[i], ans);
	}
	cout << ans << endl;
}
