//#line 2 "SubstringQueries.cpp"

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
#include <cstdint>
using namespace std;
using LL = long long;

int N;
vector<int>G[123456];
vector<int>child[123456];
int memo1[123456];
int dp1(int v, int las) {
	int res = 0;
	for (int ch : G[v]) {
		if (las == ch)continue;
		child[v].push_back(ch);
		res = max(res, dp1(ch, v) + 1);
	}
	return memo1[v] = res;
}
int memo2[123456];
int dp2(int v, int d) {
	vector<pair<int, int>>rank;
	rank.push_back({ d,-1 });
	for (int ch : child[v]) {
		rank.push_back({ memo1[ch] + 1 ,ch });
	}
	sort(rank.rbegin(), rank.rend());
	for (int ch : child[v]) {
		if (rank[0].second == ch) {
			dp2(ch, rank[1].first + 1);
		}
		else {
			dp2(ch, rank[0].first + 1);
		}
	}
	return memo2[v] = d;
}

int main() {
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (N == 2) {
		cout << 11 << endl;
		return 0;
	}
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dp1(0, -1);
	dp2(0, 0);
	int big = 0;
	for (int i = 0; i < N; ++i) {
		vector<int>rank;
		for (int v : child[i]) {
			rank.push_back(memo1[v] + 1);
		}
		if (i != 0) {
			rank.push_back(memo2[i]);
		}
		sort(rank.rbegin(), rank.rend());
		if (rank.size() >= 3) {
			int opt = rank[0] + rank[2] - (rank[0] == rank[2] ? 1 : 0);
			big = max(big, opt);
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (i <= 2) {
			cout << 1;
		}
		else {
			if (big >= i) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
	}
	cout << endl;
	return 0;
}
