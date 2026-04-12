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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<long long> inputs;
long long powing(long long a, long long b) {
	long long ans = 1;
	while (b != 0) {
		if (b % 2) {
			ans *= a;
			ans %= MAX_MOD;
		}
		a *= a;
		a %= MAX_MOD;
		b /= 2;
	}
	return ans;
}
pair<long long, long long> dfs(long long left, long long right) {
	pair<long long, long long> ans = make_pair(0, 1);
	if (left == right) return ans;
	long long height = 1e9;
	for (int i = left; i < right; ++i) {
		height = min(height, inputs[i]);
	}
	for (int i = left; i < right; ++i) {
		inputs[i] -= height;
	}
	vector<pair<long long, long long>> kouho;
	int back_itr = left;
	int cnt = 0;
	for (int i = left; i < right; ++i) {
		if (inputs[i] == 0) {
			kouho.push_back(dfs(back_itr, i));
			back_itr = i + 1;
			cnt++;
		}
	}
	kouho.push_back(dfs(back_itr, right));
	for (int i = 0; i < kouho.size(); ++i) {
		ans.second *= kouho[i].second;
		ans.second %= MAX_MOD;
	}
	ans.first = 1;
	for (int q = 0; q < kouho.size(); ++q) {
		ans.first *= (kouho[q].first + kouho[q].second);
		ans.first %= MAX_MOD;
	}
	ans.first *= powing(2LL, cnt);
	ans.first %= MAX_MOD;
	ans.first += MAX_MOD - ((ans.second * 2LL) % MAX_MOD);
	ans.first %= MAX_MOD;
	ans.second *= powing(2LL, height);
	ans.second %= MAX_MOD;
	ans.first += ans.second;
	ans.first %= MAX_MOD;
	return ans;
}
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	cout << dfs(0, inputs.size()).first << endl;
}