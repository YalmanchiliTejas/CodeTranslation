#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

class unionfind {
public:
	class node {
	public:
		ll r, o, n;
	};

	node* d;

	void init(ll n) {
		d = new node[n];
		for (ll i = 0; i < n; i++) {
			d[i].o = i;
			d[i].r = 0;
			d[i].n = 1;
		}
	}

	ll find(ll a) {
		if (d[a].o == a) {
			return a;
		}
		return d[a].o = find(d[a].o);
	}

	void unit(ll a, ll b) {
		if (d[a].r > d[b].r) {
			d[b].o = a;
			d[b].n = 0;
		}
		else if (d[a].r == d[b].r) {
			d[a].r++;
			d[b].o = a;
			d[b].n = 0;
		}
		else {
			d[a].o = b;
			d[a].n = 0;
		}
	}
};

class bit {
public:
	ll n;
	ll* d;
	
	void init(ll nw) {
		n = nw;
		d = new ll[n];
		for (ll i = 0; i < n; i++) {
			d[i] = 0;
		}
	}

	void add(ll b, ll x) {
		for (ll i = b + 1; i <= n; i += (i & -i)) {
			d[i - 1] += x;
		}
	}

	ll sum(ll b) {
		ll all = 0;
		for (ll i = b + 1; i > 0; i -= (i & -i)) {
			all += d[i - 1];
		}
		return all;
	}
};

ll n1, n2;

class path {
public:
	ll z, s, t;
};

path pl1[100100];
path pl2[100100];

path p1[100100];
path p2[100100];

ll pp[100100];
ll pn;

ll bfind(ll a) {
	ll b = 0;
	ll e = pn;
	while (e - b > 1) {
		ll m = (b + e) / 2;
		if (a < pp[m]) {
			e = m;
		}
		else {
			b = m;
		}
	}
	return b;
}

void zpress() {
	for (ll i = 0; i < n1; i++) {
		pp[i] = pl1[i].z;
	}
	sort(pp, pp + n1);
	pn = unique(pp, pp + n1) - pp;
	for (ll i = 0; i < n1; i++) {
		p1[i].z = bfind(pl1[i].z);
		p1[i].s = pl1[i].s;
		p1[i].t = pl1[i].t;
	}
	for (ll i = 0; i < n2; i++) {
		p2[i].z = pl2[i].z;
		p2[i].s = bfind(pl2[i].s);
		if (pp[p2[i].s] < pl2[i].s) {
			p2[i].s++;
		}
		p2[i].t = bfind(pl2[i].t);
	}
}

pair<ll, pair<ll, pair<ll, ll> > > tmp[1000000];

int main() {
	ll w, h, n;
	scanf("%lld%lld%lld", &w, &h, &n);
	n1 = 0;
	n2 = 0;
	pl1[n1].z = 0;
	pl1[n1].s = 0;
	pl1[n1].t = h;
	n1++;
	pl1[n1].z = w;
	pl1[n1].s = 0;
	pl1[n1].t = h;
	n1++;
	pl2[n2].z = 0;
	pl2[n2].s = 0;
	pl2[n2].t = w;
	n2++;
	pl2[n2].z = h;
	pl2[n2].s = 0;
	pl2[n2].t = w;
	n2++;
	for (ll i = 0; i < n; i++) {
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a == c) {
			pl1[n1].z = a;
			pl1[n1].s = b;
			pl1[n1].t = d;
			n1++;
		}
		else {
			pl2[n2].z = b;
			pl2[n2].s = a;
			pl2[n2].t = c;
			n2++;
		}
	}
	zpress();
	ll now = 0;
	for (ll i = 0; i < n1; i++) {
		tmp[now++] = make_pair(p1[i].s, make_pair(0, make_pair(p1[i].z, 0)));
		tmp[now++] = make_pair(p1[i].t, make_pair(2, make_pair(p1[i].z, 0)));
	}
	for (ll i = 0; i < n2; i++) {
		tmp[now++] = make_pair(p2[i].z, make_pair(1, make_pair(p2[i].s, p2[i].t)));
	}
	sort(tmp, tmp + now);
	ll ans = 0;
	unionfind uf;
	uf.init((n + 10) * 10);
	ll unow = 0;
	map<ll, ll> ss;
	map<ll, ll> nj;
	nj[-1] = unow++;
	bit bb;
	bb.init(n + 100);
	for (ll i = 0; i < now; i++) {
		/*for (auto j : nj) {
			prllf("%d:%d ", j.first, j.second);
		}
		prllf("\n");*/
		auto w = tmp[i];
		if (w.second.first == 0) {
			bb.add(w.second.second.first, 1);
			auto it = nj.lower_bound(w.second.second.first);
			it--;
			if (it != nj.end()) {
				ll nn;
				if ((*it).second < 0) {
					nn = unow++;
				}
				else {
					nn = (*it).second;
				}
				nj[(*it).first] = nn;
				ss[(*it).first] = nn;
				nj[w.second.second.first] = nn;
				ss[w.second.second.first] = nn;
			}
		}
		else if (w.second.first == 1) {
			auto it = ss.lower_bound(w.second.second.first);
			while (1) {
				auto itit = nj.find((*it).first);
				itit++;
				if (itit == nj.end() || (*itit).first > w.second.second.second) {
					break;
				}
				nj[(*it).first] = -1;
				ans--;
				auto itw = it;
				it++;
				ss.erase(itw);
			}
			ans += max((ll)0, bb.sum(w.second.second.second) - bb.sum(w.second.second.first - 1) - 1);
			//printf("%d:%d,%d %d\n", w.first, w.second.second.first, w.second.second.second, ans);
		}
		else {
			bb.add(w.second.second.first, -1);
			auto it = nj.find(w.second.second.first);
			auto it2 = it;
			it2--;
			if ((*it).second >= 0) {
				if ((*it2).second < 0) {
					nj[(*it2).first] = (*it).second;
					ss[(*it2).first] = (*it).second;
				}
				else {
					ll aw = uf.find((*it).second);
					ll bw = uf.find((*it2).second);
					if (aw != bw) {
						uf.unit(aw, bw);
					}
				}
			}
			ss.erase((*it).first);
			nj.erase(it);
		}
	}
	for (ll i = 0; i < unow; i++) {
		ans += uf.d[i].n;
	}
	ans--;
	printf("%lld\n", ans);
	return 0;
}