#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100000;
int n;
vector<pair<pair<int, int>, int> > ed, p;
int parent[N];
int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}
int main() {
	scanf("%d", &n);
	p.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].first.first, &p[i].first.second);
		p[i].second = i;
	}
	sort(p.begin(), p.end());
	for (int i = 0; i + 1 < p.size(); ++i)
		ed.push_back(make_pair(make_pair(p[i + 1].first.first - p[i].first.first, p[i].second), p[i + 1].second));
	for (int i = 0; i < p.size(); ++i)
		swap(p[i].first.first, p[i].first.second);
	sort(p.begin(), p.end());
	for (int i = 0; i + 1 < p.size(); ++i)
		ed.push_back(make_pair(make_pair(p[i + 1].first.first - p[i].first.first, p[i].second), p[i + 1].second));
	sort(ed.begin(), ed.end());
	for (int i = 0; i < n; ++i)
		parent[i] = i;
	ll res = 0;
	for (int i = 0; i < ed.size(); ++i) {
		int a = ed[i].first.second;
		int b = ed[i].second;
		a = find(a);
		b = find(b);
		if (a != b) {
			res += ed[i].first.first;
			parent[a] = b;
		}
	}
	cout << res << endl;
	return 0;
}