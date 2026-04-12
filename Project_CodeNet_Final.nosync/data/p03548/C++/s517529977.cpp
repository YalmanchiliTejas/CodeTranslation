#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define ll long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define bitget(a, b) (((a) >> (b)) & 1)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vsort(x) sort(x.begin(), x.end())

using int32 = int_fast32_t;
using int64 = int_fast64_t;
using uint32 = uint_fast32_t;
using uint64 = uint_fast64_t;

using namespace std;

int main() {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int64 ans;
	x -= z;
	ans = x / (y + z);
	printf("%lld", ans);
	return 0;
}
