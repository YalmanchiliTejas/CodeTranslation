#include "bits/stdc++.h"
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#ifndef _DEBUG
#define main_ main
#endif
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

template <typename T>
using keyVal = pair<string, T>;
template<typename T>
bool val_greater(const keyVal<T>& left, const keyVal<T>& right) {
	return left.second > right.second;
}

void init_global() {}

int main_() {
	int N;
	cin >> N;
	int x = 800 * N;
	int y = 200 * (N / 15);

	int ans = x - y;

	cout << ans << endl;
	return 0;
}
