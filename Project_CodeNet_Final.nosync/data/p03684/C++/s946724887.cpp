
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const double pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
REP(i, v.size()) { if (i)os << " "; os << v[i]; }return os;
}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;
}

class union_find {
public:
	union_find(int n)
		: par_(n, -1)
	{}
	void init(int n) {
		par_.assign(n, -1);
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) {
			return false;
		}
		else {
			if (par_[x] < par_[y]) {
				par_[x] += par_[y];
				par_[y] = x;
			}
			else {
				par_[y] += par_[x];
				par_[x] = y;
			}
			return true;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return -par_[root(x)];
	}

private:
	std::vector<int> par_;
};

struct Kruskal {
	ll cost, from, to;
	bool operator<(const Kruskal& another) const {
		return cost < another.cost;
	}
};

int main() {
	ll n;
	ll x, y;
	ll cos;
	ll sum = 0;
	vector<pair<ll, ll>> v1;
	vector<pair<ll, ll>> v2;
	vector<Kruskal> vv;

	cin >> n;

	union_find uf(n);

	REP(i, n) {
		cin >> x >> y;

		v1.push_back({ x, i });
		v2.push_back({ y, i });
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	REP(i, n - 1) {
		//FOR(j, i, n) {
			//cos = min(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
		cos = v1[i + 1].first - v1[i].first;
		Kruskal kru1 = { cos, v1[i].second, v1[i+1].second };
		vv.push_back(kru1);

		cos = v2[i + 1].first - v2[i].first;
		Kruskal kru2 = { cos, v2[i].second, v2[i + 1].second };
		vv.push_back(kru2);
		//}
	}

	sort(vv.begin(), vv.end());

	REP(i, vv.size()) {
		if (uf.same(vv[i].from, vv[i].to) == false) {
			uf.unite(vv[i].from, vv[i].to);
			sum += vv[i].cost;
		}
	}

	cout << sum << endl;
}