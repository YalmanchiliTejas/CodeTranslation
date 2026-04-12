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
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
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
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
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

class Graph {
public:
	int vn;
	int sumcost = 0;
	vector<vector<pii>> g;

	Graph(int n) {
		vn = n;
		g.resize(n);
	}
	virtual void con(int a, int b, int w) = 0;
	int getWeight(int f, int t) {
		auto itr = lower_bound(ALL(g[f]), make_pair(t, INT_MIN));
		if (itr != g[f].end())
			return itr->second;
		return INT_MIN;
	}
	int Costsum() {
		return sumcost;
	}
	void scan(int edcount, bool oindexed, bool w) {
		REP(i, edcount) {
			int a, b, c = 1;
			scanf("%d %d", &a, &b);
			if (w)scanf("%d", &c);
			con(a - oindexed, b - oindexed, c);
		}
	}
};
class BiDGraph : public Graph {//無向
public:
	BiDGraph(int n) : Graph(n) {}

	void con(int a, int b, int w = 1) {
		g[a].push_back({ b,w });
		g[b].push_back({ a, w });
		sumcost++;
	}
};
template<class T>
vector<ll> Dijkstra(T g, int st) {
	priority_queue<pii, vector<pii>, greater<pii>> que;

	que.push({ 0, st });
	int kk = 0;
	vector<ll> res(g.vn, -1);
	while (kk < g.vn && que.size()) {
		pii cur = que.top();
		que.pop();
		if (res[cur.second] != -1)
			continue;
		res[cur.second] = cur.first;
		kk++;
		for (auto itr : g.g[cur.second]) {
			if (res[itr.first] == -1)
				que.push({ cur.first + itr.second,itr.first });
		}
	}
	return res;
}
signed main() {
	int n;
	cin >> n;
	vector<ll> num(n);

	REP(i, n) {
		scanf("%lld", &num[i]);
	}

	sort(ALL(num));
	ll ret = 0;
	ll bans = 0;
	vector<ll> bb(n);
	bool f = 1;
	while (f) {
		f = 0;
		ll ans = 0;
		REP(i, n) {
			num[i] += bans-bb[i];

			if (num[i] >= n)
				f = 1;

			ans += (num[i]) / n;
			bb[i] = (num[i]) / n;
			num[i] -= ((num[i]) / n) * n;
		}
		ret += ans;

		bans = ans;
	}

	printf("%lld\n", ret);
	return 0;
}