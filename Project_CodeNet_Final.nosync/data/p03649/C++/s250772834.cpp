
#pragma region Include/Defines
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <time.h>

using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef vector<pii> vpii;
typedef vector <pll> vpll;
typedef long double ld;
#define all(a) std::begin(a), std::end(a)

const int INF = 0x3f3f3f3f;
const lli LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T, typename T2> inline void _max(T &a, T2 b) { a = max((T)a, (T)b); }
template<typename T, typename T2> inline void _min(T &a, T2 b) { a = min((T)a, (T)b); }

#ifdef _DEBUG
#define epr(...) fprintf(stderr,__VA_ARGS__)
#else
#define epr(...) 
#endif
#pragma endregion

const int MAX = 55;
lli a[MAX], n;

void clear() {
}

void read() {
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
}

void solve() {
	multiset<lli, greater<lli>> s;
	for (int i = 0; i < n; i++) s.insert(a[i]);
	lli k = 0;
	while (*s.begin() >= n) {
		lli t = *s.begin();
		multiset<lli, greater<lli>> ns;
		lli kol = t / n, rem = t % n;
		k += kol;
		ns.insert(rem);
		for (auto it = next(s.begin()); it != s.end(); it++)
			ns.insert(*it + kol);
		s = ns;
	}
	printf("%lld\n", k);
}

int main() {
#ifdef _LOCAL_VAN
	freopen("in.txt", "r", stdin);
#endif
	while (scanf("%d", &n) == 1) {
		clear();
		read();
		solve();
#ifndef _LOCAL_VAN
		return 0;
#endif
	}
	return 0;
}