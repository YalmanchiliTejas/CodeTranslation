#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

using ll = long long;
const int nax = 10123;
char k[nax];

void add_self(int &a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int D;
	cin >> k >> D;
	int len = strlen(k);
	vector<vector<int>> dp(D, vector<int>(2));
	dp[0][0] = 1;
	for(int i=0; i<len; ++i) {
		vector<vector<int>> new_dp(D, vector<int>(2));
		for(int sum = 0; sum < D; ++sum) {
			for(bool sm_already : {false, true}) {
				for(int digit = 0; digit < 10; ++digit) {
					if(digit > k[i] - '0' && !sm_already)
						break;
					add_self(new_dp[(sum+digit)%D][sm_already || (digit < k[i] - '0')], dp[sum][sm_already]);
				}

			}
		}
		dp = new_dp;
	}
	int answer = (dp[0][false] + dp[0][true])%mod;
	--answer;
	if(answer == -1) {
		answer = mod - 1 ;
	}
	cout << answer << "\n";
	return 0;
}
