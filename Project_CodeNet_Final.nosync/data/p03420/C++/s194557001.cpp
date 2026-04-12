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
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
#define int long long
	long long n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	long long ans = 0;
	for (int i = k + 1; i <= n; ++i) {
		long long bot = k;
		long long top = i-1;
		for (int q = 0; bot + i * q <= n; ++q) {
			if (top + i * q <= n) {
				ans += top - bot + 1;
			}
			else {
				for (int j = bot + i * q; j <= n; ++j) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}