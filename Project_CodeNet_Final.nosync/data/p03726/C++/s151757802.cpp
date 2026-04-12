#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>
#include <iostream>
#include <fstream>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;

const int MAXN = 200001;

set <int> e[MAXN];

int q[MAXN], qe = 0;

void eredge(int x, int y) {
	e[x].erase(y);
	if (e[x].empty()) {
		cout << "First" << endl;
		exit(0);
	}
	if (e[x].size() == 1) q[qe++] = x;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		e[a].insert(b);
		e[b].insert(a);
	}	
	for (int i = 1; i <= n; i++) {
		if (e[i].size() == 1) q[qe++] = i;
	}
	for (int qb = 0; qb < qe; qb++) {
		int v = q[qb];
		int v2 = *e[v].begin();
		for (int u : e[v2]) {
			if (u != v)
				eredge(u, v2);
		}
	}
	cout << "Second" << endl;
	return 0;
}