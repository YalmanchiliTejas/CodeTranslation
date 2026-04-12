#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

#define INF 1000000007 //1000000000000000003
#define MOD 1000000007
#define MAX 2000005

#define ll long long

//printf("%.10f", );
//cout << fixed << setprecision(10) << heikin << endl;
//vector<vector<int>> data(3, vector<int>(4, -1));
//left + 1 < top

using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct { int to; long long dist; };
const double PI = 3.141592653589793;
long long fact[MAX], inv[MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

//////////////////////////////////

vector<vector<int>> tree(100005);
int color[100005];
map<P, int>colorMap;
int m = 0;

struct BridgeInfo {
	int town1;
	int town2;
	int year;
	BridgeInfo(int t1, int t2, int y) {
		town1 = t1;
		town2 = t2;
		year = y;
	}
};

struct People {
	int index;
	int town;
	int year;
	People(int i, int t, int y) {
		index = i;
		town = t;
		year = y;
	}
};

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

struct UnionFind {
	vector<int>uf;
	
	UnionFind(int size) :uf(size, -1) {};

	int root(int target) {
		if (uf[target] < 0)return target;
		else return uf[target] = root(uf[target]);
	}

	void merge(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b)return;
		if (uf[b] < uf[a])swap(a, b);
		uf[a] += uf[b];
		uf[b] = a;
	}
};

ll CalcPow(ll num, ll power) {
	if (power == 0)return 1;
	if (power % 2 == 0) {
		ll half = CalcPow(num, power / 2);
		return (half * half) % MOD;
	}
	else return (num * CalcPow(num, power - 1)) % MOD;
}

ll combination(ll all, ll select) {
	if (all < select) return 0;
	if (all < 0 || select < 0) return 0;
	return fact[all] * (inv[select] * inv[all - select] % MOD) % MOD;
}

void initCombination(int max) {
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= max; ++i) {
		fact[i] = fact[i-1] * i % MOD;
	}

	inv[max] = CalcPow(fact[max], MOD - 2);
	for (int i = max - 1; 0 <= i; --i) {
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	}
}

void dfs(int from) {
	int c = 1;
	for (auto t : tree[from]) {
		c = c != color[from] ? c : c + 1;
		color[t] = c;
		colorMap[make_pair(from, t)] = c;
		m = max(c, m);
		dfs(t);
		c++;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	string ans = N <= M ? "Yes" : "No";
	cout << ans << endl;
}