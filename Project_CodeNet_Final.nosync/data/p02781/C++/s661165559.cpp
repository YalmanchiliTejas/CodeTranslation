#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

long long int c(long long int a, long long int b) {
	long long int res = 1;
	for (int i = 0; i < b; i++) {
		res *= (a - i);
	}
	for (int i = 1; i <= b; i++) {
		res /= i;
	}
	return res;
}

int main(int argc, char *argv[]) {

	string s;
	cin >> s;
	int k;
	cin >> k;
	int kk = k;
	long long int res = 0;
	for (int i = k; i < s.size(); i++) {
		long long int ret = c(i - 1, k - 1);
		ret *= pow(9, k);
		res += ret;
	}

	for (int i = 0; i < s.size(); i++) {
		int start = 0;
		if (i == 0) {
			start = 1;
		}
		for (int j = start; j < s[i] - '0'; j++) {
			if (j > 0 && k == 0) continue;
			long long ret;
			if (j == 0) {
				ret = c(s.size() - i - 1, k);
				ret *= pow(9, k);
			}
			else {
				ret = c(s.size() - i - 1, k - 1);
				ret *= pow(9, k - 1);
			}
			res += ret;
		}
		if (s[i] != '0') k--;
	}
	int c = 0;
	for (auto ss : s)
		if (ss != '0')
			c++;
	if (c == kk)
		res++;
	cout << res << endl;
}







