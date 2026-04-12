#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

typedef pair<pair<ll, ll>, ll> p;
typedef pair<ll, ll> pii;

ll n;
p ps1[100000], ps2[100000];

struct edge {
	ll to, cost;
};
vector<edge> es[100000];

int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) {
		ps1[i].second = i;
		cin >> ps1[i].first.first >> ps1[i].first.second;
		ps2[i] = ps1[i];
		swap(ps2[i].first.first, ps2[i].first.second);
	}
	sort(ps1, ps1 + n);
	sort(ps2, ps2 + n);

	REP(i, n - 1) {
		ll x1 = ps1[i].first.first, y1 = ps1[i].first.second, n1 = ps1[i].second;
		ll x2 = ps1[i + 1].first.first, y2 = ps1[i + 1].first.second, n2 = ps1[i + 1].second;
		ll c = min(abs(x1 - x2), abs(y1 - y2));
		es[n1].push_back({ n2, c });
		es[n2].push_back({ n1,c });
		x1 = ps2[i].first.first, y1 = ps2[i].first.second, n1 = ps2[i].second;
		x2 = ps2[i + 1].first.first, y2 = ps2[i + 1].first.second, n2 = ps2[i + 1].second;
		c = min(abs(x1 - x2), abs(y1 - y2));
		es[n1].push_back({ n2, c });
		es[n2].push_back({ n1,c });
	}

	set<ll> ved;
	ved.insert(0);
	priority_queue<pii, vector<pii>, greater<pii>> q;
	REP(i, es[0].size()) q.push(MP(es[0][i].cost, es[0][i].to));
	ll res = 0;
	REP(i, n - 1) {
		pii t;
		while (true) {
			t = q.top(); q.pop();
			if (!ved.count(t.second)) break;
		}
		ved.insert(t.second);
		res += t.first;
		REP(j, es[t.second].size()) q.push(MP(es[t.second][j].cost, es[t.second][j].to));
	}

	cout << res << endl;

	return 0;
}
