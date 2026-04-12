#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
#define int long long
	vector<int> inputs;
	vector<int> checker;
	vector<int> gogo;
	int n;
	cin >> n;
	for (int q = 2; q <= 100000; ++q) {
		int ok = 1;
		for (int j = 0; j < checker.size(); ++j) {
			if (q % checker[j] == 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			checker.push_back(q);
		}
	}
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
		REP(j, checker.size()) {
			if (a % checker[j] == 0) {
				gogo.push_back(checker[j]);
				if(a != checker[j])
				gogo.push_back(a / checker[j]);
			}
		}
		if(a != 1)
		gogo.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	long long ans = 0;
	REP(i, gogo.size()) {
		long long now = 0;
		REP(q, inputs.size()) {
			if (inputs[q] % gogo[i] == 0) {
				now += inputs[q];
			}
		}
		ans = max(ans, now);
	}
	cout << ans << endl;
}
