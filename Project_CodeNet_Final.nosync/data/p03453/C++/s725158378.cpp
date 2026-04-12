#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<pli, vector<pli>, greater<pli> > pq;
vector<pii> v[100000];

ll ldist[100000];
ll rdist[100000];

int ls[100000];
int rs[100000];

struct node {
	int u, v, c;
} edg[200000];

void dijk(int st, ll *dist, int *ss) {
	while (!pq.empty()) pq.pop();
	fill(dist, dist + 100000, (ll)1e18);
	
	ss[st] = 1; dist[st] = 0;
	pq.push({ 0, st });

	pli tv;
	pii tt;

	while (!pq.empty()) {
		tv = pq.top();
		pq.pop();

		if (tv.first != dist[tv.second]) continue;

		for (int i = 0; i < sz(v[tv.second]); i++) {
			tt = v[tv.second][i];

			if (dist[tt.second] > dist[tv.second] + tt.first) {
				dist[tt.second] = dist[tv.second] + tt.first;
				ss[tt.second] = 0;
				pq.push({ dist[tt.second], tt.second });
			}
			if (dist[tt.second] == dist[tv.second] + tt.first)
				ss[tt.second] = (ss[tt.second] + ss[tv.second]) % MOD;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int s, t;
	scanf("%d %d", &s, &t);
	s--; t--;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });

		edg[i] = { a, b, c };
	}

	dijk(s, ldist, ls);
	dijk(t, rdist, rs);
	ll ans = (ll)ls[t] * rs[s] % MOD;

	if (ldist[t] % 2 == 0) {
		for (int i = 0; i < n; i++)
			if (ldist[i] + rdist[i] == ldist[t] && ldist[i] == ldist[t] / 2) {
				ll tt = (ll)ls[i] * rs[i] % MOD;
				tt = tt * tt % MOD;
				ans = (ans - tt + MOD) % MOD;
			}
	}

	for (int i = 0; i < m; i++) {
		// printf("%d %d : ", edg[i].u + 1, edg[i].v + 1);
		if (ldist[edg[i].u] < (ldist[t] + 1) / 2 && ldist[edg[i].v] > ldist[t] / 2 && ldist[edg[i].u] + edg[i].c + rdist[edg[i].v] == ldist[t]) {
			// printf("pass");
			ll tt = (ll)ls[edg[i].u] * rs[edg[i].v] % MOD;
			tt = tt * tt % MOD;
			ans = (ans - tt + MOD) % MOD;
		}
		else if (ldist[edg[i].v] < (ldist[t] + 1) / 2 && ldist[edg[i].u] > ldist[t] / 2 && ldist[edg[i].v] + edg[i].c + rdist[edg[i].u] == ldist[t]) {
			// printf("pass");
			ll tt = (ll)ls[edg[i].v] * rs[edg[i].u] % MOD;
			tt = tt * tt % MOD;
			ans = (ans - tt + MOD) % MOD;
		}
		// printf("\n");
	}

	printf("%lld", ans);
}