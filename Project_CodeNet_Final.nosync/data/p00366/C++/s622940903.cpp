
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
vector<int>vec;
int hyou[123456];

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp; cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.rbegin(), vec.rend());
	int M = vec[0];
	for (int j = M; j >= 1; --j) {
		if (M % j != 0) {
			hyou[j] = hyou[j + 1] + 1;
		}
	}
	int ans = 0;
	for (int elm : vec) {
		ans += hyou[elm];
	}
	cout << ans << endl;
	return 0;
}

