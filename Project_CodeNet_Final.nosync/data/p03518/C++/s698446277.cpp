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
int gogo[100000];
int main(){
	int n;
	cin >> n;
	REP(i, n) {
		cin >> gogo[i];
	}
	vector<int> answer;
	for (int i = 0;; ++i) {
		long long geko = (i + n - 1) % n;
		if (geko != n - 1) {
			if (gogo[geko] > gogo[i%n]) {
				swap(gogo[i%n], gogo[geko]);
				answer.push_back(n - 1);
			}
		}
		int ok = 1;
		for (int q = 0; q < n; ++q) {
			if (gogo[q] != q) {
				ok = 0;
				break;
			}
		}
		if (ok == 1&&i % n == 0) {
			cout << answer.size() << endl;
			REP(q, answer.size()) {
				cout << answer[q] << endl;
			}
			return 0;
		}
		answer.push_back(1);
	}
}