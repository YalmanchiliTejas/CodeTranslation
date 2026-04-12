
//https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long int ll;

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
using ll = long long;
const double EPS = 1e-9;

pair<ll, ll> recSolve2(int l, int r, vector<int> & seq, bool player) {
	if(l > r) return {0,0};

	if(player == false) {  //taro

		auto fleft = recSolve2(l + 1, r, seq, true);
		auto fRight = recSolve2(l, r - 1, seq, true);

		if(seq[l] + fleft.first - fleft.second >
		seq[r] + fRight.first - fleft.second) {
			return {seq[l] + fleft.first, fleft.second};
		}  else {
			return {seq[r] + fRight.first, fRight.second};
		}
	} else {
		auto fleft = recSolve2(l + 1, r, seq, false);
		auto fRight = recSolve2(l, r - 1, seq, false);

		if(fleft.first - seq[l] - fleft.second <
		fRight.first - seq[r] - fRight.second) {
			return {fleft.first, seq[l] + fleft.second};
		} else {
			return {fRight.first, seq[r] + fRight.second};
		}
	}
}


ll recSolve(int l, int r, vector<int> & seq, vector<vector<ll>> & memo) {
	if(l > r) return 0;
	if(memo[l][r] != -1) return memo[l][r];

	ll leftTaken = seq[l] + min(recSolve(l + 2, r, seq, memo), 
		recSolve(l + 1, r - 1, seq, memo));
	ll rightTaken = seq[r] + min(recSolve(l + 1, r - 1, seq, memo), 
		recSolve(l, r - 2, seq, memo));

	memo[l][r] =  max(leftTaken, rightTaken);
	return memo[l][r];
}

ll solveDeque() {
	int n; cin >> n;
	vector<int> seq(n);
	for(auto & v : seq) {
		cin >> v;
	}

	vector<vector<ll>> memo(3000, vector<ll>(3000, -1));

	ll taroAcc = recSolve(0, n - 1, seq, memo);
	ll acc = accumulate(seq.begin(), seq.end(), 0l);
	ll jiroAcc = acc - taroAcc;

	return taroAcc - jiroAcc;
}

ll solveDequeDP() {
	int n; cin >> n;
	vector<int> seq(n);
	for(auto & v : seq) {
		cin >> v;
	}
	
	
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

	for(auto delta = 0; delta < n; ++delta) {
		for(auto l = 0; l < n - delta; ++l) {
			auto r = l + delta;
			if(l > r) continue;

			if(l == r){
				dp[l][r] = seq[l];
			} else {
				auto leftTaken = seq[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);
				auto rightTaken = seq[r] + min(dp[l][r - 2], dp[l + 1][r - 1]);

				dp[l][r] = max(leftTaken, rightTaken);
			}
		}
	}

	ll taroAcc = dp[0][n - 1];
	ll acc = accumulate(seq.begin(), seq.end(), 0l);
	ll jiroAcc = acc - taroAcc;
	return taroAcc - jiroAcc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(precision);
	cout.setf(ios_base::fixed);

	auto ret = solveDequeDP();
	cout << ret << endl;
	
	return 0;
}
