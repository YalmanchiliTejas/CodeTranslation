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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
int main(){
	int h, w;
	cin >> h >> w;
	vector<pair<int,int>> geko;
	REP(i, h) {
		string s;
		cin >> s;
		long long now_max = -1;
		long long now_min = 1e5;
		REP(q, w) {
			if (s[q] == 'B') {
				now_min = min(now_min, q);
				now_max = max(now_max, q);
			}
		}
		if (now_max != -1) {
			geko.push_back(make_pair(i, now_min));
			geko.push_back(make_pair(i, now_max));
		}
	}
	int ans = 0;
	REP(i, geko.size()) {
		REP(q, geko.size()) {
			ans = max(ans, abs(geko[i].first - geko[q].first) + abs(geko[i].second - geko[q].second));
		}
	}
	cout << ans << endl;
	return 0;
}
