#ifndef VS
#include<bits/stdc++.h>
#endif

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};
int N;
int a[212345];
int b[212345];
int c[212345];
LL ds[112345];
LL cs[112345];
LL dt[112345];
LL ct[112345];
typedef vector<int> V;
typedef vector<V> VV;
VV g;
constexpr LL INF = 1e18;
constexpr int mod = 1e9 + 7;
typedef pair<LL, int> P;
priority_queue<P> que;
void dijkstra(int s,LL* d,LL* cnt) {
	d[s] = 0;
	cnt[s] = 1;
	que.push({ d[s],s });
	while (que.size()) {
		int v; LL cost;
		tie(cost, v) = que.top(); que.pop();
		cost = -cost;
		if (d[v] > cost)continue;
		for (int e : g[v]) {
			int u = v ^ a[e] ^ b[e];
			LL nxtcost = cost + c[e];
			if (chmin(d[u], nxtcost)) {
				cnt[u] = 0;
				que.push({ -d[u],u });
			}
			if (d[u] == nxtcost) {
				cnt[u] += cnt[v];
				if (cnt[u] >= mod)cnt[u] -= mod;
			}
		}
	}
}
int main() {
	int S, T, M;
	cin >> N >> M >> S >> T;
	g = VV(N);
	S--; T--;
	for (int i : range(M)) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	fill(ds, ds + N, INF);
	fill(dt, dt + N, INF);
	fill(cs, cs + N, 0ll);
	fill(ct, ct + N, 0ll);
	dijkstra(S, ds, cs);
	dijkstra(T, dt, ct);
	LL ret = cs[T] * cs[T] % mod;
	for (int i : range(N)) {
		if (ds[i] + dt[i] == ds[T] && ds[i] == dt[i]) {
			LL k = cs[i] * ct[i] % mod;
			ret += mod - k*k%mod;
		}
	}
	LL half = (ds[T] + 1) / 2;
	for (int i : range(M)) {
		int u = a[i], v = b[i];
		if (ds[u] + dt[v] + c[i] == ds[T] && ds[u] < half&&dt[v] < half) {
			LL k = cs[u] * ct[v] % mod;
			ret += mod-k*k%mod;
		}
		swap(u, v);
		if (ds[u] + dt[v] + c[i] == ds[T] && ds[u] < half&&dt[v] < half) {
			LL k = cs[u] * ct[v] % mod;
			ret += mod-k*k%mod;
		}
	}
	cout << ret%mod << endl;
	return 0;
}
