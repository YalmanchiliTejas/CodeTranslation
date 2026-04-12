/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps || (abs(goa - now_min) <= eps && (abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
int union_tree[10000];
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[a] = b;
	return 0;
}
long long winning[4001][4001];
vector<pair<long long, long long>> vertexs[4000];
void dfs(int now, int back,int itr) {
	for (int q = 0; q < vertexs[now].size(); ++q) {
		if (vertexs[now][q].first == back) continue;
		int go = vertexs[now][q].first;
		winning[itr][go] = max(winning[itr][now], vertexs[now][q].second);
		dfs(go, now, itr);
	}
}
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<tuple<long long, long long, long long>> edges;
	REP(i, m) {
		long long a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		edges.push_back(make_tuple(c, a, b));
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; ++i) {
		union_tree[i] = i;
	}
	long long ans = 0;
	REP(i, m) {
		if (union_find(get<1>(edges[i])) != union_find(get<2>(edges[i]))) {
			ans += get<0>(edges[i]);
			union_merge(get<1>(edges[i]), get<2>(edges[i]));
			vertexs[get<1>(edges[i])].push_back(make_pair(get<2>(edges[i]), get<0>(edges[i])));
			vertexs[get<2>(edges[i])].push_back(make_pair(get<1>(edges[i]), get<0>(edges[i])));
		}
	}
	REP(i, n) {
		dfs(i, -1, i);
	}
	int query;
	cin >> query;
	REP(i, query) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << ans - winning[a][b] << endl;
	}
	return 0;
}