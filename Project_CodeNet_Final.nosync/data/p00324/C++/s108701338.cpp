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
#include <utility>
#include <unordered_map>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)
#define bitget(a,b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(),(x).end()
#define scanf scanf_s

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::unordered_map<uint64,uint32> map;
	uint32 n;
	std::cin >> n;
	int64 a, sum = 1e15;
	uint32 ans = 0;
	map[sum] = 0;
	rep(i, 0, n) {
		std::cin >> a;
		sum += a;
		if (map.find(sum)!=map.end()) {
			ans = std::max(ans, i + 1 - map[sum]);
		}
		else {
			map[sum] = i + 1;
		}
	}
	std::cout << ans << "\n";
	return 0;
}