#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

struct edge {
	int to, length, data;
};

int N, M, S, T, U, V, D;
ll dis[100000], e[200000], t[100000], rt[100000], rdis[100000], res;
vector<edge>vec[100000];
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>>q;

int main(){
	cin >> N >> M >> S >> T;
	--S;
	--T;
	for (int i = 0; i < M; ++i) {
		cin >> U >> V >> D;
		--U;
		--V;
		vec[U].push_back({ V,D,i });
		vec[V].push_back({ U,D,i });
	}
	for (int i = 0; i < N; ++i) {
		dis[i] = rdis[i] = llmax;
	}
	t[S] = 1;
	q.push(mkp(0, mkp(S, S)));
	while (!q.empty()) {
		ll d = q.top().first;
		int to = q.top().second.first, from = q.top().second.second;
		q.pop();
		if (dis[to] == llmax) {
			t[to] = t[from];
			dis[to] = d;
			for (edge u : vec[to]) {
				if (dis[u.to] == llmax) {
					q.push(mkp(d + u.length, mkp(u.to, to)));
				}
			}
		}
		else if (dis[to] == d) {
			t[to] = (t[to] + t[from]) % mod;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (edge u : vec[i]) {
			if (dis[i] + u.length == dis[u.to]) {
				e[u.data] = t[i];
			}
		}
	}
	rt[T] = 1;
	q.push(mkp(0, mkp(T, T)));
	while (!q.empty()) {
		ll d = q.top().first;
		int to = q.top().second.first, from = q.top().second.second;
		q.pop();
		if (rdis[to] == llmax) {
			rt[to] = rt[from];
			rdis[to] = d;
			for (edge u : vec[to]) {
				if (rdis[u.to] == llmax) {
					q.push(mkp(d + u.length, mkp(u.to, to)));
				}
			}
		}
		else if (rdis[to] == d) {
			rt[to] = (rt[to] + rt[from]) % mod;
		}
	}
	res = t[T] * rt[S] % mod;
	for (int i = 0; i < N; ++i) {
		if (dis[i] + rdis[i] != dis[T])continue;
		if (dis[i] * 2 == dis[T]) {
			res = (res + mod - t[i] * rt[i] % mod * t[i] % mod*rt[i] % mod) % mod;
		}
		for (edge u : vec[i]) {
			if (rdis[i] + u.length == rdis[u.to]) {
				if (rdis[i] * 2 < rdis[S] && rdis[S] < rdis[u.to] * 2 && dis[u.to] + rdis[u.to] == dis[T]) {
					res = (res + mod - e[u.data] * rt[i] % mod * e[u.data] % mod*rt[i] % mod) % mod;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}