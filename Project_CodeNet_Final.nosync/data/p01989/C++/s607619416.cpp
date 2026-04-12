#include <iostream>
#include <string>

#define FOR(i, a, b) for(int i = int(a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)

int calc(std::string s, int k) {
	if (k == 4) {
		return s.empty() ? 1 : 0;
	}
	if (s.empty()) return 0;
	if (s.front() == '0') {
		return calc(s.substr(1), k + 1);
	}
	int res = 0;
	REP(i, 3) {
		if (std::stoi(s.substr(0, i + 1)) <= 255) {
			if (s.size() <= i + 1) {
				res += calc("", k + 1);
				break;
			}
			else res += calc(s.substr(i + 1), k + 1);
		}
	}
	return res;
}

signed main() {
	std::string s;
	std::cin >> s;
	std::cout << calc(s, 0) << std::endl;
}
