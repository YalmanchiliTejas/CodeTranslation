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
#include <random>
using namespace std;
using LL = long long;

LL N, X, M;

int main() {
	cin >> N >> X >> M;
	LL now = X;
	LL ans = X;
	LL loop = 1;
	map<LL, pair<LL, LL>>path;//first: value second: tobu
	path[X] = { X,1 };

	bool hasfast = false;
	LL tobu = 0;
	LL plus = 0;
	while (loop < N) {
		if (hasfast) {
			if (loop + tobu <= N) {
				LL lo = 1, hi = 1000000000;
				while (hi - lo > 1) {
					LL mid = (lo + hi) / 2;
					if (loop + tobu * mid <= N) {
						lo = mid;
					}
					else {
						hi = mid;
					}
				}
				loop += tobu * lo;
				ans += plus * lo;
			}
			else {
				now *= now;
				now %= M;
				ans += now;
				++loop;
			}
		}
		else {
			now *= now;
			now %= M;
			ans += now;
			++loop;
			if (path.count(now)) {
				hasfast = true;
				tobu = loop - path[now].second;
				plus = ans - path[now].first;
			}
			else {
				path[now] = { ans,loop };
			}

		}
	}
	cout << ans << endl;
	return 0;
}