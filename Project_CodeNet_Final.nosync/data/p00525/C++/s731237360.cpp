#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define y1 y233
using ll = long long;
using pii = pair <int, int>;

const int N = 1e5L + 11;
const int M = N * 4 + 11;
const int inf = 2e9L;

int x1[N], y1[N], x2[N], y2[N];

int lowbit(int x) { return x & (-x); }
struct BIT {
	int b[M];
	void clear() { fill(b, b + M, 0); }
	void change(int p, int x) {
		for(p += 5; p < M; p += lowbit(p))
			b[p] += x;
	}
	int query(int p) {
		int r = 0;
		for(p += 5; p; p -= lowbit(p))
			r += b[p];
		return r;
	}
}bit;

struct event {
	int p, type, k1, k2, id;
	bool operator <(event e) const {
		return tie(p, type, k1, k2, id) < tie(e.p, e.type, e.k1, e.k2, e.id);
	}
};

int p[N];
int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

int main() {
	ios :: sync_with_stdio(false);
	int w, h, n; cin >> w >> h >> n;
	for(int i = 1; i <= n; i ++)
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	n ++; x1[n] = 0; y1[n] = 0; x2[n] = w; y2[n] = 0;
	n ++; x1[n] = 0; y1[n] = 0; x2[n] = 0; y2[n] = h;
	n ++; x1[n] = w; y1[n] = h; x2[n] = w; y2[n] = 0;
	n ++; x1[n] = w; y1[n] = h; x2[n] = 0; y2[n] = h;
	
	{
		map <int, int> mp;
		for(int i = 1; i <= n; i ++) {
			mp[x1[i]] = 0; mp[y1[i]] = 0;
			mp[x2[i]] = 0; mp[y2[i]] = 0;
		}
		int cnt = 0;
		for(auto &p : mp)
			p.second = ++ cnt;
		for(int i = 1; i <= n; i ++) {
			//swap(x1[i], y1[i]); swap(x2[i], y2[i]);
			x1[i] = mp[x1[i]]; y1[i] = mp[y1[i]];
			x2[i] = mp[x2[i]]; y2[i] = mp[y2[i]];
		}
	}
	
	vector <event> eves; int cnt = 0;
	for(int i = 1; i <= n; i ++)
		if(x1[i] == x2[i]) {
			if(y1[i] > y2[i]) swap(y1[i], y2[i]);
			eves.pb({y1[i], 0, x1[i], 1, ++ cnt});
			eves.pb({y2[i] + 1, 0, x1[i], -1, cnt});
		} else {
			if(x1[i] > x2[i]) swap(x1[i], x2[i]);
			eves.pb({y1[i], 1, x1[i], x2[i], 0});
		}
	iota(p, p + cnt + 1, 0);
	sort(eves.begin(), eves.end());

	set <pii> sts, stp;
	for(int i = 0; i < M; i ++)
		sts.insert({i, i});
	stp.insert({M, 0});

	ll m = 0, sp = 0;
	bit.clear();
	for(auto e : eves)
		if(e.type == 0) {
			bit.change(e.k1, e.k2);

			if(e.k2 == 1) {
				stp.insert({e.k1, e.id});
				pii p = *(-- sts.lower_bound({e.k1, inf})); sts.erase(p);
				if(p.fi != e.k1) sts.insert({p.fi, e.k1 - 1});
				sts.insert({e.k1, e.k1});
				if(p.se != e.k1) sts.insert({e.k1 + 1, p.se});
			} else
				stp.erase({e.k1, e.id});
		} else {
			m += bit.query(e.k2);
			m -= bit.query(e.k1 - 1);

			auto it = stp.lower_bound({e.k1, 0});
			if(it -> first > e.k2) { sp ++; continue; }
			int x = it -> second;

			it = -- sts.lower_bound({e.k1, inf});

			if(it -> fi != e.k1) {
				pii p = *it; sts.erase(it);
				sts.insert({p.fi, e.k1 - 1});
				sts.insert({e.k1, p.se});
				it = -- sts.lower_bound({e.k1, inf});
			}
			int l = it -> fi, r;

			while(it -> fi <= e.k2) {
				if(it -> se > e.k2) {
					pii p = *it; sts.erase(it);
					sts.insert({p.fi, e.k2});
					sts.insert({e.k2 + 1, p.se});
					it = -- sts.lower_bound({p.fi, inf});
				}

				r = it -> se;
				auto is = stp.lower_bound({it -> fi, 0});
				if(is -> fi <= it -> se) {
					int y = is -> se;
					int a = find(x), b = find(y);
					if(a != b) p[b] = a;
				}
				is = it ++;
				sts.erase(is);
			}
			sts.insert({l, r});
		}
	ll ans = m - n + sp;
	for(int i = 1; i <= cnt; i ++)
		if(find(i) == i) ans ++;
	cout << ans << '\n';
}