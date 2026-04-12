#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };


int main() {

	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s.at(i);
		sort(s.at(i).begin(), s.at(i).end());
	}
	string ans;
	for (char c = 'a'; c <= 'z'; c++) {
		int num = mod;
		rep(i, n) {
			int cnt = 0;
			rep(j, s.at(i).size()) {
				if (s.at(i).at(j) == c) cnt++;
			}
			num = min(num, cnt);
		}
		rep(k, num) {
			ans += c;
		}
	}
	cout << ans << endl;

	return 0;
}