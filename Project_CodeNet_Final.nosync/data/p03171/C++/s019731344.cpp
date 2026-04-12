#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<vector<ll>>& dp, vector<ll>& a, int head, int tail){
	if(head >= tail){
		return dp[head][tail] = a[head];
	}
	if(dp[head][tail] != 0) return dp[head][tail];

	ll best = max(
		-solve(dp,a,head,tail-1) + a[tail],
		-solve(dp,a,head+1,tail) + a[head]
		);

	return dp[head][tail] = best;
}

int main(){
	int N;
	cin >> N;
	vector<ll> a(N);
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}

	vector<vector<ll>> dp(N,vector<ll>(N));
	cout << solve(dp,a,0,a.size()-1) << endl;

	return 0;


}

