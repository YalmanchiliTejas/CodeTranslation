#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))
#define inCI(v, l, r) ((l) <  (v) && (v) <= (r))
#define inCD(v, l, r) ((l) <  (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

template<typename T> class RPQ : public PQ<T, vector<T>, greater<T>> { };
template<typename Cost> void dijkstra(int start, vector<pair<int, Cost>> g[], Cost dist[], LL pat[], LL mod) {
	RPQ<pair<Cost, int>> q;
	dist[start] = 0;
	pat[start] = 1;
	q.emplace(dist[start], start);
	while(! q.empty()) {
		auto cp = q.top(); q.pop();
		int  p = cp.SE;
		Cost c = cp.FI;
		if(dist[p] != c) { continue; }
		for(auto && e : g[p]) {
			int  ep = e.FI;
			Cost ec = e.SE;
			if(dist[ep]  > dist[p] + ec) { pat[ep] = pat[p]; }
			if(dist[ep] == dist[p] + ec) { (pat[ep] += pat[p]) %= mod; }
			if(setmin(dist[ep], dist[p] + ec)) { q.emplace(dist[ep], ep); }
		}
	}
	return;
}

// ----

const int V = 100000;

int n, m, s[2];
vector<pair<int, LL>> v[V];

LL d[2][V], INF = 1e15;
LL p[2][V], MOD = 1e9 + 7;
vector<int> ef[V];

int main() {
	cin >> n >> m >> s[0] >> s[1];
	s[0]--; s[1]--;
	inc(i, m) {
		LL a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		v[a].EB(b, c);
		v[b].EB(a, c);
	}
	
	inc(k, 2) {
		inc(i, n) { d[k][i] = INF; }
		dijkstra(s[k], v, d[k], p[k], MOD);
	}
	
	assert(d[0][s[1]] == d[1][s[0]]);
	assert(p[0][s[1]] == p[1][s[0]]);
	
	LL sd = d[0][s[1]];
	LL ans = p[0][s[1]] * p[1][s[0]] % MOD;
	// cout << ans << endl;
	inc(i, n) {
		if(d[0][i] + d[1][i] != sd) { continue; }
		
		if(d[0][i] != d[1][i]) { continue; }
		LL w = p[0][i] * p[1][i] % MOD;
		w = w * w % MOD;
		(ans += MOD - w) %= MOD;
		// cout << "V " << i + 1 << ": " << (- w) << endl;
	}
	inc(i, n) {
	inc(j, v[i].size()) {
		LL x = i, y = v[i][j].FI, z = v[i][j].SE;
		if(d[0][x] + d[1][y] + z != sd) { continue; }
		
		assert(inCD(sd - 2 * d[0][x], 0, 2 * z) == inCD(sd - 2 * d[1][y], 0, 2 * z));
		if(! inCD(sd - 2 * d[0][x], 0, 2 * z)) { continue; }
		LL w = p[0][x] * p[1][y] % MOD;
		w = w * w % MOD;
		(ans += MOD - w) %= MOD;
		// cout << "E " << x + 1 << " --> " << y << ": " << (-w) << endl;
	}
	}
	
	cout << ans << endl;
	
	return 0;
}
