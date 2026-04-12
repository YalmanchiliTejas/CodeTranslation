#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

priority_queue<pair<int, int> > heap;

bool done[1000000];

vector<int> closest[1000000];

int main() {
	vector<pair<int, int> > p;
	vector<pair<int, int > > x, y;
	int N;
	cin >> N;
	int a, b;
	FOR (i, N) {
		cin >> a >> b;
		p.pb(make_pair(a, b));
		x.pb(make_pair(a, i));
		y.pb(make_pair(b, i));
		closest[i].clear();
	}
	sort(all(x));
	sort(all(y));
	SET(done, 0);
	FOR (i, x.sz) {
		int idx = x[i].second;
		if (i)
			closest[idx].pb(x[i - 1].second);
		if (i < x.sz - 1)
			closest[idx].pb(x[i + 1].second);
	}

	FOR (i, y.sz) {
		int idx = y[i].second;
		if (i)
			closest[idx].pb(y[i - 1].second);
		if (i < y.sz - 1)
			closest[idx].pb(y[i + 1].second);
	}
	
	LL ret = 0LL;
	heap.push(make_pair(0, 0));
	while (!heap.empty()) {
		pair<int, int> el = heap.top();
		heap.pop();
		int idx = el.second, dist = el.first;
		if (done[idx])
			continue;
		done[idx] = true;
		ret -= dist;
		FOR (i, closest[idx].sz) {
			int w = closest[idx][i];
			if (done[w])
				continue;
			LL d = min(abs(p[idx].first - p[w].first), abs(p[idx].second - p[w].second));
			heap.push(make_pair(-d, w));
		}
	}
	cout << ret << endl;
	return 0;
}