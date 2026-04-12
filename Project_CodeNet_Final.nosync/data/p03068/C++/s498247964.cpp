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
	int N;
	cin >>N;
	string S;
	cin >> S;
	int K;
	cin >> K;

	for (size_t i = 0; i < S.length(); i++) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}

	std::cout << S << endl;

	return 0;
}

