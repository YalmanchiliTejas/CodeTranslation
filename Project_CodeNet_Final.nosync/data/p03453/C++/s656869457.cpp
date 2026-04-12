#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

const ll mod = 1000000007;
const ll INF = 100000010000;

ll kai[100010];
ll bit[700010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

/*ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= 700005)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1) {
		return x * pow_mod(x, y - 1) % mod;
	}
	else {
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

ll com(ll x, ll y) {
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
}

ll N, M;
ll S, T;
ll U[200010], V[200010], D[200010];
struct edge { ll to, cost; };
vector<edge> E[100010];
ll ans;

ll d[100010][2];
ll dp[100010][2];
map<ll, ll> mp;
bool path[100010];
vector<P> vec[2];

void dij(ll start, ll dir) {
	priority_queue<P, vector<P>, greater<P>> que;
	rep(i, N + 1) d[i][dir] = INF;
	d[start][dir] = 0;
	que.push(P(0, start));
	while (que.size()) {
		P p = que.top(); que.pop();
		if (p.f > d[p.s][dir]) continue;
		for (edge e : E[p.s]) {
			if (d[e.to][dir] > d[p.s][dir] + e.cost) {
				d[e.to][dir] = d[p.s][dir] + e.cost;
				que.push(P(d[e.to][dir], e.to));
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	cin >> S >> T;
	rep(i, M) {
		cin >> U[i] >> V[i] >> D[i];
		E[U[i]].pb(edge{ V[i], D[i] });
		E[V[i]].pb(edge{ U[i], D[i] });
	}
	dij(S, 0);
	dij(T, 1);

	for (int i = 1; i <= N; i++) {
		if (d[T][0] % 2 == 0) {
			if (d[i][0] < d[T][0] / 2) {
				mp[i] = 1;
			}
			if (d[i][1] < d[T][0] / 2) {
				mp[i] = 2;
			}
		}
		else {
			if (d[i][0] <= d[T][0] / 2) {
				mp[i] = 1;
			}
			if (d[i][1] <= d[T][0] / 2) {
				mp[i] = 2;
			}
		}
	}
	dp[T][0] = 1;
	for (int i = 1; i <= N; i++) {
		vec[0].push_back(P(d[i][0], i));
	}
	sort(vec[0].begin(), vec[0].end());
	reverse(vec[0].begin(), vec[0].end());
	for (P p : vec[0]) {
		for (edge e : E[p.s]) {
			if (d[p.s][0] - e.cost == d[e.to][0]) {
				(dp[e.to][0] += dp[p.s][0]) %= mod;
			}
		}
	}
	dp[S][1] = 1;
	for (int i = 1; i <= N; i++) {
		vec[1].push_back(P(d[i][1], i));
	}
	sort(vec[1].begin(), vec[1].end());
	reverse(vec[1].begin(), vec[1].end());
	for (P p : vec[1]) {
		for (edge e : E[p.s]) {
			if (d[p.s][1] - e.cost == d[e.to][1]) {
				(dp[e.to][1] += dp[p.s][1]) %= mod;
			}
		}
	}
	rep(i, M) {
		ll a = U[i], b = V[i];
		if (mp[a] == 1 && mp[b] == 2 && d[a][0] + D[i] == d[b][0]) {
			ll su = dp[a][1] * dp[b][0] % mod;
			(ans += mod - su * su % mod) %= mod;
		}
		if (mp[a] == 2 && mp[b] == 1 && d[b][0] + D[i] == d[a][0]) {
			ll su = dp[a][0] * dp[b][1] % mod;
			(ans += mod - su * su % mod) %= mod;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (d[i][0] * 2 == d[T][0]) {
			ll su = dp[i][0] * dp[i][1] % mod;
			(ans += mod - su * su % mod) %= mod;
		}
	}
	ll q = dp[S][0] * dp[T][1] % mod;
	(ans += q % mod) %= mod;
	cout << ans << endl;

	// ���������ɂ���A�ǂ������肪�Ƃ��������܂����B�ǂ����A�璹�ł��A�����ɊفA�悾�ꂾ���ł��A
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}
////////////////////////////////////////////////////////////////////////////////////////////jagfhaoi;sd;joi;asdfjzasdi;lfjoi;ernjsdoivcnoizvdfnvdfnon/////////////////////////////////////////////////////////
////////////////////jgoiadhsjgoi;vsjvgfonhjasoivhoivhno