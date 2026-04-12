#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
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
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
long long ans[500000] = {};
int main() {
	int n;
	cin >> n;
	iostream::sync_with_stdio(false);
	vector<pair<int, int>> wow;
	REP(i, n) {
		int a;
		cin >> a;
		wow.push_back(make_pair(a, i));
	}
	sort(wow.begin(), wow.end());
	for (int i = 0; i < n / 2; ++i) {
		ans[wow[i].second] = wow[n / 2].first;
	}
	for (int i = n / 2; i < n; ++i) {
		ans[wow[i].second] = wow[n / 2 - 1].first;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}