#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <tuple>
#define all(c) ((c).begin(),(c).end())
#define rall(c) ((c).rbegin(),(c).rend())
#define ll long long
#define fi first
#define se second
#define inf (999999999)
using namespace std;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
//---------------------------------------------------------------------------------------------//
int n;
int x[100001], y[100001];
int par[100011];
int Rank[100011];
struct edge {
	int from, to, cost;
};
void init() {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		Rank[i] = 0;
	}
}
int Find(int x) {
	if (par[x] == x)return x;
	return par[x]=Find(par[x]);
}

bool same(int x, int y) {
	if (Find(x) == Find(y))return 1;
	else return 0;
}

void unite(int x, int y) {
	if (Find(x) == Find(y))return;
	if (Rank[x] < Rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}
bool comp(const edge& a,const edge& b) {
	return a.cost < b.cost;
}
void Union(int a, int b) {
	unite(Find(a), Find(b));
}
int main() {
	cin >> n;
	init();
	vector<pair<int, int>> x;
	vector<pair<int, int>> y;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		x.push_back(pair<int, int>(a, i));
		y.push_back(pair<int, int>(b, i));
	}
	vector<edge> ve;
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	for (int i = 0; i < x.size()-1; i++) {
		ve.push_back({ x[i].se,x[i + 1].se,x[i + 1].first - x[i].fi });
	}
	for (int i = 0; i < y.size() - 1; i++) {
		ve.push_back({ y[i].second,y[i + 1].second,y[i + 1].first - y[i].fi });
	}
	sort(ve.begin(), ve.end(),comp);
	int cont = 0;
	ll ans = 0;
	int i = 0;
	while (cont < n - 1) {
		if (!same(ve[i].from, ve[i].to)) {
			//cout << Find(ve[i].from) << endl;
			//cout << Find(ve[i].to) << endl;
			//cout << ve[i].from << " " << ve[i].to << " " << ve[i].cost << endl;
			//cout << "------------" << endl;
			ans += ve[i].cost;
			//unite(ve[i].from, ve[i].to);
			Union(ve[i].from, ve[i].to);
			cont++;
			i++;
		}
		else i++;
	}
	cout << ans << endl;
}