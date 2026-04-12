#include <bits/stdc++.h>
using namespace std;

template<unsigned long long m>
struct modint {

	unsigned long long x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}

	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator unsigned long long () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	modint operator^ (unsigned long long arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
typedef modint<MOD> mint;


typedef long long ll;

int n, m, s, t;
vector<pair<int, int>> e[100005];

ll ds[100005], dt[100005];

mint ws[100005], wt[100005];

void dijkstra(int s, ll* d) {
	set<pair<ll, int>> pq;
	fill(d+1, d+n+1, 1e18);
	d[s] = 0;
	pq.insert({0, s});

	while (!pq.empty()) {
		auto p = *pq.begin();
		pq.erase(p);

		int x = p.second;

		for (auto ee : e[x]) {
			int y = ee.first;
			int l = ee.second;

			if (d[y] > d[x] + l) {
				pq.erase({d[y], y});
				d[y] = d[x] + l;
				pq.insert({d[y], y});
			}
		}
	}
}

bool cmp_s(int x, int y) {
	return ds[x] < ds[y];
}

bool cmp_t(int x, int y) {
	return dt[x] < dt[y];
}

void uradi_w(ll* d, mint* w, int s, auto cmp) {
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	sort(a.begin(), a.end(), cmp);

	w[s] = 1;
	for (int x : a) {
		for (auto p : e[x]) {
			if (d[x] + p.second == d[p.first]) {
				w[p.first] += w[x];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s >> t;

	for (int i=1; i<=m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		e[u].push_back({v, d});
		e[v].push_back({u, d});
	}

	dijkstra(s, ds);
	dijkstra(t, dt);

	uradi_w(ds, ::ws, s, cmp_s);
	uradi_w(dt, wt, t, cmp_t);

	mint sol = ::ws[t] * wt[s];

	// cerr << "tmp " << sol.x << '\n';

	for (int i=1; i<=n; i++) {
		// susrecu se u cvoru i
		if (ds[i] == dt[i]) {
			sol -= ::ws[i] * wt[i] * ::ws[i] * wt[i];
			// cerr << "smanji ovde " << (::ws[i] * wt[i]).x << '\n';
		}

		// susrecu se na grani nekoj
		for (auto ee : e[i]) {
			int j = ee.first;
			int l = ee.second;

			// cerr << i << ' ' << j << ' ' << ds[i] << ' ' << l << ' ' << dt[j] << '\n';

			if (ds[i] + l + dt[j] != ds[t]) {
				continue;
			}

			if (ds[i] + l <= dt[j]) {
				continue;
			}
			if (dt[j] + l <= ds[i]) {
				continue;
			}
			
			sol -= ::ws[i] * ::wt[j] * ::ws[i] * ::wt[j];
		}

	}

	cout << sol.x << '\n';

}