//#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
template<class T>
using V = vector<T>;
template<class T>
using VV = vector<vector<T>>;
typedef unsigned long long ULL;

void input();
void solve();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N;
VI H;

void input() {
	cin >> N;
	H.resize(N);
	for (int n = 0; n < N; n++) {
		cin >> H[n];
	}
}

void solve() {
	int ans = 1;
	for (int n = 1; n < N; n++) {
		bool flag = true;
		for (int s = 0; s < n; s++) {
			if (H[s] > H[n])flag = false;
		}
		if (flag)ans++;
	}
	cout << ans << "\n";
}