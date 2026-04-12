
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
using namespace std;
using LL = long long;

int N;
pair<LL, int>A[234567];
LL ans[234567];

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A, A + N);
	for (int i = 0; i < N / 2; ++i) {
		ans[A[i].second] = A[N / 2].first;
	}
	for (int i = N / 2; i < N; ++i) {
		ans[A[i].second] = A[N / 2 - 1].first;
	}
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
