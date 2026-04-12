
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);
const ll mod = 1000000007;
ll max(ll a, ll b) {
	if (a < b)
		return b;
	else
		return a;

}
ll min(ll a, ll b) {
	if (a < b)
		return a;
	else
		return b;

}

double max(double a, double b) {
	if (a < b) return b;

	return a;
}

ll N;
priority_queue<pair<ll, pint>> q;
vector<pair<pll, ll>> d;


class DisjointSet {
public:
	vector<int> p, rank, num;


	DisjointSet() {}

	DisjointSet(int size) {
		rank.resize(size, 0);
		p.resize(size, 0);
		num.resize(size, 0);
		rep(i, size) { p[i] = i; rank[i] = 0; num[i] = 1; }
	}

	bool same(int x, int y) {

		return findSet(x) == findSet(y);

	}

	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {

			p[y] = x;
			num[x] += num[y];

		}

		else {
			p[x] = y;
			num[y] += num[x];
			if (rank[x] == rank[y]) {

				rank[y]++;
			}

		}


	}


	ll NumberOfElements(int x) {

		return num[findSet(x)];

	}


	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);
			num[x] = 1;
		}

		return p[x];
	}



};



bool compare_b(pair< pint,ll> a, pair<pint, ll> b) {
	if (a.first.second > b.first.second)
		return true;

	return false;
}

ll vis[100005];

int main() {
	
	cin >> N;
	d.resize(N);
	rep(i, N) {
		cin >> d[i].first.first >> d[i].first.second;
		d[i].second = i;
	}

	sort(d.begin(), d.end());
	rep(i, d.size()-1) {
		q.push({ -abs(d[i].first.first - d[i + 1].first.first), {d[i].second, d[i + 1].second} });

	}

	sort(d.begin(), d.end(), compare_b);
	reverse(d.begin(), d.end());

	rep(i, d.size() - 1) {
		q.push({ -abs(d[i].first.second - d[i+1].first.second), {d[i].second, d[i + 1].second} });

	}

	ll honsu = 0;
	ll sum = 0;
	DisjointSet ds = DisjointSet(N);

	for (int i = 0; i < 2 * N - 2; i++) {
		if (!ds.same(q.top().second.first, q.top().second.second)) {
			sum += -q.top().first;
			ds.unite(q.top().second.first, q.top().second.second);
		}

		q.pop();
	}

	cout << sum << endl;
	return 0;
}