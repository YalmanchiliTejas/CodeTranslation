#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

const int mod = 1000000007;
struct mint {
	ll x;
	mint(ll x = 0) :x(x%mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
};

vector<vector<ll>>edges;
vector<pair<ll, ll>>E[101010];
vector<pair<ll, ll>>dist[2];

void dijkstra(int num, int st) {
	min_priority_queue<pair<ll, ll>>que;
	for (int i = 0; i < 101010; i++)dist[num].pb({ inf,0 });
	dist[num][st] = { 0,1 };
	que.push({ 0,st });
	while (que.size()) {
		auto p = que.top();
		que.pop();
		ll d = p.first;
		ll node = p.second;
		if (dist[num][node].first < d)continue;
		ll cnt = dist[num][node].second;
		fore(x, E[node]) {
			ll to = x.first;
			ll cost = x.second;
			if (dist[num][to].first == cost + d) {
				dist[num][to].second += cnt;
				dist[num][to].second %= mod;
			}
			else if (dist[num][to].first > cost + d) {
				dist[num][to].first = cost + d;
				dist[num][to].second = cnt;
				que.push({ dist[num][to].first,to });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, M, S, T;
	cin >> N >> M >> S >> T;
	S--, T--;
	for (int i = 0; i < M; i++) {
		ll u, v, d;
		cin >> u >> v >> d;
		u--, v--;
		edges.pb({ u,v,d });
		E[u].pb({ v,d });
		E[v].pb({ u,d });
	}

	dijkstra(0, S);
	dijkstra(1, T);

	mint ans = dist[0][T].second;
	ans *= dist[0][T].second;
	ll l = dist[0][T].first;
	if (l % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (l / 2 == dist[0][i].first && l / 2 == dist[1][i].first) {
				ll temp = dist[0][i].second*dist[1][i].second;
				temp %= mod;
				temp *= temp;
				temp %= mod;
				ans -= temp;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		ll u = edges[i][0];
		ll v = edges[i][1];
		ll x1 = dist[0][u].first;
		ll y1 = dist[1][v].first;
		ll x2 = dist[0][v].first;
		ll y2 = dist[1][u].first;
		ll cost = edges[i][2];
		if (x1 + cost + y1 == l) {
			if (y1 - cost < x1 && x1 < y1 + cost && x1 -cost < y1 && y1 < x1 + cost) {
				mint temp = dist[0][u].second * dist[1][v].second;
				temp *= temp;
				ans -= temp;
			}
		}
		else if (x2 + cost + y2 == l) {
			if (y2 - cost < x2 && x2 < y2 + cost && x2 - cost < y2 && y2 < x2 + cost) {
				mint temp = dist[0][v].second * dist[1][u].second;
				temp *= temp;
				ans -= temp;
			}
		}
	}
	puts(ans.x);

	return 0;
}