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

int N, M, S, T;
vector<vector<ll>>edges;
vector<pair<ll, ll>>E[101010];
vector<ll>dist[2];
ll dp[2][101010];	
vector<int>edag[101010];

void dijkstra(int num,int st) {
	min_priority_queue<pair<ll, ll>>que;
	for (int i = 0; i < 101010; i++)dist[num].pb(inf);
	dist[num][st] = 0;
	que.push({0,st});
	while (que.size()) {
		auto p = que.top();
		que.pop();
		ll d = p.first;
		ll node = p.second;
		if (dist[num][node] < d)continue;
		ll cnt = dist[num][node];
		fore(x, E[node]) {
			ll to = x.first;
			ll cost = x.second;
			if (dist[num][to] > cost + d) {
				dist[num][to] = cost + d;
				que.push({ dist[num][to],to });
			}
		}
	}
}

ll memo(int num,int st,int now){
	if (dp[num][now] != -1)return dp[num][now];
	ll temp = 0;
	fore(x, edag[now]) {
		temp += memo(num,st,x);
		temp %= mod;
	}
	return dp[num][now] = temp % mod;
}

void count(int num,int st){
	for (int i = 0; i < 101010; i++) {
		edag[i].clear();
		dp[num][i] = -1;
	}
	for (int i = 0; i < M; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		ll cost = edges[i][2];
		if (dist[num][u] + cost == dist[num][v]) {
			edag[v].pb(u);
		}
		else if (dist[num][v] + cost == dist[num][u]) {
			edag[u].pb(v);
		}
	}
	dp[num][st] = 1;
	for (int i = 0; i < N; i++)memo(num, st, i);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

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

	dijkstra(0,S);
	dijkstra(1,T);
	count(0,S);
	count(1,T);
	
	mint ans = dp[0][T] * dp[0][T];
	ll l = dist[0][T];
	for (int i = 0; i < N; i++) {
		if (2LL * dist[0][i] == l && 2LL * dist[1][i] == l) {
			ll temp = dp[0][i] * dp[1][i];
			temp %= mod;
			temp *= temp;
			ans -= temp;
		}
	}

	for (int i = 0; i < M; i++) {
		ll cost = edges[i][2];
		int u = edges[i][0];
		int v = edges[i][1];
		ll x1 = dist[0][u];
		ll y1 = dist[1][v];
		ll x2 = dist[0][v];
		ll y2 = dist[1][u];
		if (x1 + y1 + cost == l) {
			if (y1 - cost < x1 && x1 < y1 + cost && x1 - cost < y1 && y1 < x1 + cost){
				ll temp = dp[0][u] * dp[1][v];
				temp %= mod;
				temp *= temp;
				ans -= temp;
			}
		}
		else if (x2 + y2 + cost == l) {
			if (y2 - cost < x2 && x2 < y2 + cost && x2 - cost < y2 && y2 < x2 + cost){
				ll temp = dp[0][v] * dp[1][u];
				temp %= mod;
				temp *= temp;
				ans -= temp;
			}
		}
	}
	puts(ans.x);

	return 0;
}