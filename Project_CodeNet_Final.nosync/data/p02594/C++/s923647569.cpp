#include <algorithm>
#include<cfenv>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include<numeric>
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
using namespace std;
typedef long long llong;
typedef unsigned long long ullong;
vector<llong> AllDivisors(llong N) {
	vector<llong> ANS;
	for (llong i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			ANS.push_back(i);
			if (N / i != i)ANS.push_back(N / i);
		}
	}
	sort(ANS.begin(), ANS.end());
	return ANS;
}
bool IsPrime(llong N) {
	for (llong i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}
pair<llong, llong> Reduction(pair<llong, llong> A) {
	llong tmp = gcd(A.first, A.second);
	auto p = make_pair(A.first / tmp, A.second / tmp);
	return p;
}
//ここまで共通
int main() {
	int X;
	cin >> X;
	if (X >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;
}