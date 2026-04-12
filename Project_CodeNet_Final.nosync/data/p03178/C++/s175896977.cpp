#define ONLINE_JUDGE
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const int mod = 1e9 + 7;

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	string digits;
	int d;
	cin >> digits >> d;

	vector<int[2]> dp(d);
	dp[0][0] = 1;

	for(int i = 0; i < digits.size(); ++i) {
		vector<int[2]> next(d);
		for(int j = 0; j < d; ++j) {
			for(auto s : {false, true}) {
				for(int digit = 0; digit < 10; ++digit) {
					if(s == false && digit > (digits[i] - '0')) break;
					add_self(next[(j + digit) % d][s || (digit < digits[i] - '0')],
							 dp[j][s]);
				}
			}
		}
		for(int i = 0; i < d; ++i) {
			dp[i][0] = next[i][0];
			dp[i][1] = next[i][1];
		}
	}
	int ans = dp[0][0];
	add_self(ans, dp[0][1]);
	--ans;
	if(ans < 0) ans += mod;
	cout << ans << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
