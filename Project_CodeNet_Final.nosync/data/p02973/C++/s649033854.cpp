#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <array>
using namespace std;
using lint = long long;
using ld = long double;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
#pragma endregion

const lint INF = 1ll << 60;
const int mod = 1000000007;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<lint> data(n, INF);
	lint ans = 0;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		int p = upper_bound(data.begin(), data.end(), -s) - data.begin();
		if (data[p] == INF) ans++;
		data[p] = -s;
	}
	cout << ans << endl;

	return 0;
}