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
int N;
vector<llong>A;
const llong MOD = 1000000007;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		llong a;
		cin >> a;
		A.push_back(a);
	}

	llong ANS = 0;
	llong tmp = 0;
	for (int i = 0; i < N; i++) {
		ANS += tmp * A[i];
		ANS %= MOD;
		tmp += A[i];
		tmp %= MOD;
	}

	ANS %= MOD;

	cout << ANS << endl;
}