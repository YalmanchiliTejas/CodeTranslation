#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int N = 1e5;
vector<pair<int, int>> g[N];
int n, m;

vector<pair<ll, int>> f(int s) {
	vector<pair<ll, int>> dis(n, pair<ll, int>(1e18, 0));
	dis[s] = {0, 1};
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.emplace(0, s);
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if (dis[x.S].F == x.F) {
			for (auto v : g[x.S]) {
				if (v.S + x.F < dis[v.F].F) {
					pq.emplace(v.S + x.F, v.F);
					dis[v.F] = {v.S + x.F, dis[x.S].S};
				} else if (v.S + x.F == dis[v.F].F) {
					dis[v.F].S += dis[x.S].S;
					if (dis[v.F].S >= inf) dis[v.F].S -= inf;
				}
			}
		}
	}
	return dis;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	int s, t; cin >> s >> t; --s, --t;
	FOR (_, 1, m) {
		int u, v, d; cin >> u >> v >> d;
		--u, --v;
		g[u].emplace_back(v, d);
		g[v].emplace_back(u, d);
	}

	auto x = f(s), y = f(t);

	ll D = x[t].F;

	int ans = (x[t].S * 1LL * y[s].S) % inf;
	vector<int> vis(n);
	FOR (i, 0, n - 1) {
		if (x[i].F == D/2 and y[i].F == D/2 and !(D & 1LL)) {
			int val = (x[i].S * 1LL * x[i].S) % inf;
			val = (val * 1LL * y[i].S) % inf;
			val = (val * 1LL * y[i].S) % inf;
			ans = (ans - val) % inf;
			if (ans < 0) ans += inf;
			vis[i] = 1;
		}
	}

	FOR (i, 0, n - 1) if (!vis[i]) {
		for (auto j : g[i]) if (!vis[j.F]) {
			if (x[i].F + y[j.F].F + j.S == D and x[i].F <= D/2 and x[i].F + j.S >= (D+1)/2) {
				int val = (x[i].S * 1LL * y[j.F].S) % inf;
				val = (val * 1LL * x[i].S) % inf;
				val = (val * 1LL * y[j.F].S) % inf;	
				ans = (ans - val) % inf;
				if (ans < 0) ans += inf;
			}
		}
	}

	cout << ans << "\n";


	return 0;
}
