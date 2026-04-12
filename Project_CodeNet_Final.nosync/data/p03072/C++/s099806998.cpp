
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

vector<int>A;
vector<int>B;
int N;

int main() {
	cin >> N;
	int big = -1;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		big = max(tmp, big);
		A.push_back(tmp);
		B.push_back(big);
		if (tmp == big)ans++;
	}
	cout << ans << endl;
	return 0;
}