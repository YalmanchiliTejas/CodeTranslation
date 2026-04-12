#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>
#include <sys/resource.h>
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;
 
const int precision = 15;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7
 
const double EPS = 1e-9;
const ll inf = 1e18;


void increaseStack() {
	const rlim_t kStackSize = 50 * 1024 * 1024;   // min stack size = 50 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
		if (rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
		    result = setrlimit(RLIMIT_STACK, &rl);
		    if (result != 0) {
		    	fprintf(stderr, "setrlimit returned result = %d\n", result);
		    }
		}
	}
}

void solve() {
	ll d;
	string k;

	cin >> k >>  d;

	vector<vector<int>> dp(d, vector<int>(2));
	// dp[sum%d][isSmaller]
	dp[0][0] = 1;
	for (int i = 0; i < k.size(); ++i) {
		vector<vector<int>> tmpDp(d, vector<int>(2));
		auto curD = k[i] - '0';
		for (auto s = 0; s < d; ++s) {
			for (auto small : {0, 1}) {
				for (auto digit = 0; digit <= 9; ++digit) {
					if (digit > curD and !small) break;
					auto pSum = (s + digit) % d;
					auto isSmaller = small or (digit < curD);
					auto & curDp = tmpDp[pSum][isSmaller];

					curDp += dp[s][small];
					if (curDp >= lmodulo) {
						curDp -= lmodulo;
					}
				}	
			}			
		}
		swap(dp, tmpDp);
	}

	auto ret = dp[0][0] + dp[0][1];
	ret %= lmodulo;
	ret --;
	if (ret < 0) ret = lmodulo - 1;
	cout << ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solve();
  return 0;
}
