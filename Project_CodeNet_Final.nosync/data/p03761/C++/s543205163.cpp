#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 1 << 21;
using pii = std::pair<int, int>;
#define SORT(v) std::sort(v.begin(), v.end())
int main(void) {
	int N,M;
	std::cin >> N;
	std::map<char, int> mp[51];
	for (int i = 0; i < N; ++i) {
		std::string s;
		std::cin >> s;
		for (size_t j = 0; j < s.size(); ++j) {
			mp[i][s[j]]++;
		}
	}
	for (char temp = 'a'; temp <= 'z';++temp) {
		int count = 100;
		for (int i = 0; i < N; i++) {
			count = std::min(mp[i][temp], count);
		}
		for (int i = 0; i < count; i++) {
			std::cout << temp;
		}
	}
	std::cout << std::endl;
	return 0;
}