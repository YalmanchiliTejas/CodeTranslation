#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long int ll;
typedef complex<double> com;
typedef pair<int, int> P;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 4e18;



int main() {
	int n; cin >> n;
	vector<ll> cnt(26,INF);
	rep(i, 0, n) {
		string s; cin >> s;
		vector<ll> sum(26, 0);
		rep(j, 0, s.size()) {
			sum[s[j] - 'a']++;
		}
		rep(j, 0, 26) {
			cnt[j] = min(cnt[j], sum[j]);
		}
	}
	string ans;
	rep(i, 0, 26) {
		rep(j, 0, cnt[i]) {
			ans += ('a'+i);
		}
	}
	printf("%s", ans.c_str());
	return 0;
}
