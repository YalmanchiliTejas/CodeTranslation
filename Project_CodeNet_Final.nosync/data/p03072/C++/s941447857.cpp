#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <tuple>
#include <regex>
#include <map>

using namespace std;
using ull = unsigned long long;

int main() {
	ull N;
	cin >> N;

	vector<ull> vec(N);

	for (size_t i = 0; i < N; i++) {
		cin >> vec[i];
	}

	ull ans = N;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < i; j++) {
			if (vec[j] > vec[i]) {
				ans--;
				break;
			}
		}
	}

	cout << ans << endl;


	return 0;
}
