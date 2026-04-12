#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to;
	ll weight;

	bool operator < (const Edge& obj) const {
		return weight < obj.weight;
	}
	bool operator > (const Edge& obj) const {
		return weight > obj.weight;
	}
};

int main()
{
	int n, m, s,t;

	cin >> n >> m >> s >> t;
	s--, t--;
	map<pii, ll> ed;
	vector<vector<Edge>> g(n);
	REP(i, m) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		a--, b--;
		g[a].push_back({ a,b,c });
		g[b].push_back({ b,a,c });
		ed[{a, b}] = c;
		ed[{b, a}] = c;
	}

	vector<ll> dis1(n, -1), dis2(n, -1);
	vector<ll> cou1(n),cou2(n);

	auto dik = [&](int st, vector<ll>&cou, vector<ll>& dis) {
		priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
		cou[st] = 1;
		pq.push({ 0, {st,st} });
		while (pq.size()) {

			auto cur = pq.top();

			pq.pop();
			if (dis[cur.second.first] == -1) {
				dis[cur.second.first] = cur.first;
				if (cur.second.first != cur.second.second) {
					(cou[cur.second.first] += cou[cur.second.second]) %= MODU;
				}
			}
			else {
				if (dis[cur.second.first] == cur.first)
					(cou[cur.second.first] += cou[cur.second.second]) %= MODU;
				continue;
			}

			for (auto itr : g[cur.second.first]) {
				if (dis[itr.to] == -1)
					pq.push({ cur.first + itr.weight, MP(itr.to,cur.second.first) });
				else {
					if (dis[itr.to] == cur.first + itr.weight)
						(cou[itr.to] += cou[cur.second.first]) %= MODU;
				}
			}

		}
	};

	dik(s, cou1,dis1);
	dik(t, cou2, dis2);
	if (dis1[t] != dis2[s]) return 1;
	if (cou1[t] != cou2[s]) return 1;
	ll Mind = dis1[t];
	ll ans = (cou1[t] * cou2[s]) % MODU;

	for (auto itr : ed) {
		if ( abs(dis1[itr.first.first] - dis2[itr.first.second]) < itr.second && dis1[itr.first.first] + dis2[itr.first.second] + itr.second == Mind) {
			(ans -= PW((cou1[itr.first.first] * cou2[itr.first.second]) % MODU) % MODU) %= MODU;
		}
	}

	REP(i, n) {
		if(dis1[i] == dis2[i] && dis1[i] + dis2[i] == Mind)
			(ans -= PW((cou1[i] * cou2[i])%MODU) % MODU) %= MODU;
	}
	ans = (ans + MODU) % MODU;
	cout << ans << endl;
	return 0;
}
	