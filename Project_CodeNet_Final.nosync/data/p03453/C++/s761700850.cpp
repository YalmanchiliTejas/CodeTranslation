#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL

template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<template<class, class...> class C, class... A>
typename enable_if<!is_same<C<A...>, string>::value, ostream&>::type
operator<<(ostream& os, class C<A...> c) {
	auto i = c.begin();
	while (i != c.end()) {
		os << " {"[i == c.begin()] << *i;
		os << ",}"[++i == c.end()];
	}
	return os;
}

#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(...) {}
#endif

typedef long long ll;

const int N = 1e6;
long long infLL = 1e18;
int inf = 1e9;

int kra[N];

vector<pair<int,int>> G[N];

pair<vector<ll>, vector<vector<int>>> dijk(int st, int n) {
	vector<ll> odl;
	vector<vector<int>> skad;
	skad.resize(n + 1);
	odl.resize(n + 1, infLL);
	odl[st] = 0;
	set<pair<ll, int>> kol;
	kol.insert({0, st});
	while (!kol.empty()) {
		int x = kol.begin() -> second;
		kol.erase(kol.begin());
		for (auto p : G[x]) {
			int y = p.first;
			int e = kra[p.second];
			if (odl[y] > odl[x] + e) {
				skad[y].clear();
				kol.erase({odl[y], y});
				odl[y] = odl[x] + e;
				kol.insert({odl[y], y});
			}
			if (odl[y] == odl[x] + e) {
				skad[y].push_back(x);
			}
		}
	}
	return make_pair(odl, skad);
}

const int mod = 1e9 + 7;

vector<ll> policz(vector<vector<int>>& t) {
	vector<vector<int>> g;
	queue<int> kol;
	vector<int> deg;
	vector<ll> res;
	res.resize(t.size(), 0);
	deg.resize(t.size(), 0);
	g.resize(t.size());
	
	for (int x = 1; x < g.size(); x ++) {
		deg[x] = t[x].size();
		for (int y : t[x]) {
			g[y].push_back(x);
		}
	}
	for (int x = 1; x < g.size(); x ++) {
		if (deg[x] == 0) {
			kol.push(x);
			res[x] = 1;
		}
	}
	while (!kol.empty()) {
		int x = kol.front();
		kol.pop();
		for (int y : g[x]) {
			res[y] = (res[y] + res[x]) % mod;
			deg[y] --;
			if (deg[y] == 0) {
				kol.push(y);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i ++) {
		int a, b, d;
		cin >> a >> b >> d;
		G[a].push_back({b, i});
		G[b].push_back({a, i});
		kra[i] = d;
	}
	auto q = dijk(s, n);
	vector<ll> odlS = q.first;
	vector<vector<int>> skadS = q.second;
	vector<ll> dpS = policz(skadS);
	q = dijk(t, n);
	vector<ll> odlT = q.first;
	vector<vector<int>> skadT = q.second;
	vector<ll> dpT = policz(skadT);
	long long D = odlS[t];
	vector<int> ileV;
	vector<int> ileE;
	ileV.resize(n + 1);
	ileE.resize(m + 1);
	long long sumV = 0;
	long long sumE = 0;
	debug(odlS);
	debug(skadS);
	debug(dpS);
	debug(odlT);
	debug(skadT);
	debug(dpT);
	for (int i = 1; i <= n; i ++) {
		if (odlS[i] == D/2 && odlT[i] == D/2) {
			ileV[i] = (dpS[i] * (ll)dpT[i]) % mod;
			sumV = (sumV + ileV[i]) % mod;
		}
		for (auto p : G[i]) {
			int y = p.first;
			int idx = p.second;
			if (2 * odlS[i] < D && 2 * odlT[y] < D && odlS[i] + kra[idx] + odlT[y] == D) {
				ileE[idx] = (dpS[i] * (ll)dpT[y]) % mod;
			}
		}
	}
	for (int i = 0; i < m; i ++) {
		sumE = (sumE + ileE[i]) % mod;
	}
	debug(mod);
	debug(sumV);
	debug(ileV);
	debug(sumE);
	debug(ileE);
	long long res = 0;
	for (int i = 1; i <= n; i ++) {
		res = (res + (ileV[i] * (sumE + sumV - ileV[i] + mod) % mod)) % mod;
	}
	for (int i = 0; i < m; i ++) {
		res = (res + (ileE[i] * (sumV + sumE - ileE[i] + mod) % mod)) % mod;
	}
	if (D == infLL) {
		res = 0;
	}
	cout << res << "\n";
}
