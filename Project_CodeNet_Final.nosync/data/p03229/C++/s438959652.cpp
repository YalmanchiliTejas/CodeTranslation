#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, j, n) for (int i = j; i < (n); ++i);
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int n; cin >> n;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];
	vector<ll> param1(n), param2(n);
	param1[0] = -1;
	param2[0] = 1;
	if (n % 2 == 0) {
		param1[1] = 1;
		param2[1] = -1;
	}
	else {
		param1[1] = -1;
		param2[1] = 1;
	}
	for (int i = 2; i < n; ++i) {
		if (i % 2 == 0) {
			param1[i] = 2;
			param2[i] = -2;
		}
		else {
			param1[i] = -2;
			param2[i] = 2;
		}
	}
	sort(param1.begin(), param1.end());
	sort(param2.begin(), param2.end());
	ll ans = 0;
	ll tmpans = 0;
	sort(v.begin(), v.end());
	rep(i, n) {
		tmpans += v[i] * param1[i];
	}
	ans = max(ans, tmpans);
	tmpans = 0;
	rep(i, n) {
		tmpans += v[i] * param2[i];
	}
	ans = max(ans, tmpans);
	cout << ans << endl;
	return 0;
}