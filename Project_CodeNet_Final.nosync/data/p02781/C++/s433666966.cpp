#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

string number;
int K;
const int N = 400;
ll dp[N][2][10];

ll solve(int d, int less, int k){
	if(k > K) return 0LL;

	if(k == K){
		return 1LL;
	}

	if(d < 0){
		return 0LL;
	}

	ll &ans = dp[d][less][k];

	if(ans != -1){
		return ans;
	}

	ans = 0;

	if(less){
		ans = solve(d - 1, less, k + 1) * 9LL;
		ans += solve(d - 1, less, k);

		return ans;
	}else{
		int dd = number[d] - '0';

		for(int e = 0 ; e <= dd ; e++){
			ans += solve(d - 1, e < dd, k + (e != 0));
		}

		return ans;
	}
}

int main(){
	memset(dp, -1, sizeof dp);
	
	cin >> number;

	reverse(number.begin(), number.end());

	cin >> K;

	cout << solve(int(number.length()) - 1, 0, 0) << endl;

	return 0;
}