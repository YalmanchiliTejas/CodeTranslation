#include<math.h>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include <array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
//AtCoderC++.cpp

using namespace std;

vector<long long> comb = vector<long long>(100 * 100,-1);

long long combination(long long n, long long r) {
	if (n == 1 || n == 0)return 1;
	if (n == r)	return 1;
	else if (r == 0)return 1;
	else if (r == 1)return n;
	else if (comb[100 * (n - 1) + (r - 1)] != -1) return comb[100 * (n - 1) + (r - 1)];
	else {
		auto res = combination(n - 1, r - 1) + combination(n - 1, r);
		comb[100 * (n - 1) + (r - 1)] = res;
		return res;
	}
}




int main() {
	size_t n; cin >> n;
	auto min_count = vector<size_t>(26,10000);
	auto count = vector<size_t>(26, 0);
	string s;
	for (size_t i = 0; i < n; i++) {
		cin >> s;
		for (size_t i = 0; i < s.length(); i++) {
			count[s[i] - 'a']++;
		}
		for (size_t i = 0; i < 26; i++) {
			min_count[i] = min(min_count[i], count[i]);
			count[i] = 0;
		}
	}
	string answer = "";
	for (size_t i = 0; i < 26; i++) {
		for (size_t j = 0; j < min_count[i]; j++) {
			answer += (char)('a' + i);
		}
	}
	cout << answer << endl;
}
