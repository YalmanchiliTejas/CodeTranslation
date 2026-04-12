#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define itn int
#define retrun return
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
using namespace std;
typedef long long llong;
typedef pair<int, int> pii;
llong gcd(llong a, llong b) {
	if (a < b) std::swap(a, b);
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}
llong lcm(llong a, llong b) {
	llong g = gcd(a, b);
	return a * b / g;
}
//ここまで共通
int main() {
	string S;
	cin >> S;
	if (S == "AAA" || S == "BBB") {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}