#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
	int n;
	std::cin >> n;
	std::vector<int> v(30,0);
	string str;
	std::cin >> str;
	for (size_t i = 0; i < str.size(); i++) {
		v[str[i] - 'a']++;
	}

	for (size_t i = 1; i < n; i++) {
		std::cin >> str;
		std::vector<int> t(30,0);
		for (size_t j = 0; j < str.size(); j++) {
			t[str[j] - 'a']++;
		}
		for (size_t j = 0; j < v.size(); j++) {
			v[j] = min(v[j],t[j]);
		}
	}

	string ans;
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < v[i]; j++) {
			ans += ('a' + i);
		}
	}

	std::cout << ans << '\n';
	return 0;
}
