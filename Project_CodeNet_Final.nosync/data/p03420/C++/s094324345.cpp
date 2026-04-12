
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

LL N, K;

int main(void)
{
	cin >> N >> K;
	LL ans = 0;
	for (int b = K + 1; b <= N; ++b) {
		LL beet = (N / b);
		LL can = beet * (b - K);
		LL ei1333 = N - (beet * b) + 1 - K;
		ei1333 = max(ei1333, 0LL);
		can += ei1333;
		if (K == 0)--can;
		ans += can;
	}
	cout << ans << endl;
	return 0;
}
