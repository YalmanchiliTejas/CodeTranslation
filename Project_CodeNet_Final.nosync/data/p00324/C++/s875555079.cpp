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
#include <time.h>
#include <utility>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)
#define bitget(a,b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(),(x).end()
#define C(x) std::cout << #x << " : " << x << std::endl
#define scanf scanf_s

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

template<typename Key, typename Value>
class hashmap {
	std::vector<std::pair<Key, Value>> map;
	uint64 mask, temp, rand, count;
public:
	hashmap() :map(8192, std::make_pair(~static_cast<Key>(0), Value())) {
		mask = 8191; count = 0;
		rand = (uint32)time(NULL);
		rand ^= (rand << 13);
		rand ^= ((rand & 0xFFFFFFFF) >> 7);
		rand ^= (rand << 5);
	}
	hashmap(size_t s) {
		s |= s << 1;
		s |= s >> 2;
		s |= s >> 4;
		s |= s >> 8;
		s |= s >> 16;
		mask = s;
		rand = (uint32)time(NULL);
		rand ^= (rand << 13);
		rand ^= ((rand & 0xFFFFFFFF) >> 7);
		rand ^= (rand << 5);
		count = 0;
		map.resize(s + 1, std::make_pair(~static_cast<Key>(0), Value()));
	}
	Value &operator[](Key suf) {
		temp = mask&std::hash<Key>()(suf^rand);
		while (map[temp].first != suf) {
			temp = mask&(temp + 1);
		}
		return map[temp].second;
	}
	void insert(Key key, const Value &value) {
		temp = mask&std::hash<Key>()(key^rand);
		while (~map[temp].first) {
			if (map[temp].first == key) {
				map[temp].second = value;
				return;
			}
			temp = mask&(temp + 1);
		}
		map[temp] = std::make_pair(key, value);
		++count;
		if ((count << 1) > mask) {
			std::pair<Key, Value> mkey;
			uint64 t = mask;
			mask = mask << 1 | 1;
			map.resize(mask + 1, std::make_pair(~static_cast<Key>(0), Value()));
			while (~map[t].first) {
				--t;
			}
			while (++t <= (mask >> 1)) {
				mkey = map[t];
				map[t].first = ~static_cast<Key>(0);
				temp = mask&std::hash<Key>()(mkey.first^rand);
				while (~map[temp].first) {
					temp = mask&(temp + 1);
				}
				map[temp] = mkey;
			}
			for (t = 0;t <= mask >> 1;++t) {
				if (~map[t].first) {
					mkey = map[t];
					map[t].first = ~static_cast<Key>(0);
					temp = mask&std::hash<Key>()(mkey.first^rand);
					while (~map[temp].first) {
						temp = mask&(temp + 1);
					}
					map[temp] = mkey;
				}
			}
		}
		return;
	}
	bool find(Key key) {
		temp = mask&std::hash<Key>()(key^rand);
		while (~map[temp].first) {
			if (map[temp].first == key) {
				return true;
			}
			temp = mask&(temp + 1);
		}
		return false;
	}
	bool empty(void) {
		return !count;
	}
	size_t size(void) {
		return count;
	}
};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	hashmap<uint64,uint32> map(1);
	uint32 n;
	std::cin >> n;
	int64 a, sum = 1LL<<50;
	uint32 ans = 0;
	map.insert(sum, 0);
	rep(i, 0, n) {
		std::cin >> a;
		sum += a;
		if (map.find(sum)) {
			ans = std::max(ans, i + 1 - map[sum]);
		}
		else {
			map.insert(sum, i + 1);
		}
	}
	std::cout << ans << "\n";
	return 0;
}