#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353LL
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
int main() {
	mp::cpp_int a, b, x;
	cin >> a >> b >> x;
	if (x < a) {
		cout << x%MAX_MOD << endl;
		return 0;
	}
	mp::cpp_int ans = 0;
	mp::cpp_int nya = (x - a) / (a - b);
	nya++;
	ans = (nya%MAX_MOD) * (a%MAX_MOD);
	ans %= MAX_MOD;
	x -= nya * (a-b);
	cout << (ans%MAX_MOD + x%MAX_MOD)%MAX_MOD << endl;
	return 0;
}
