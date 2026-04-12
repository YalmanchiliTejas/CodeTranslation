#include<bits/stdc++.h>
using namespace std;

#define DIV 998244353

long long N, S;
long long A[3005];
//           idx,  sum , state (0-> LR not fixed, 1-> L fixed, 2-> LR fixed)
long long dp[3005][3005][3];

int main(){
	cin >> N >> S;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	for(long long i = 0; i < N; i++) {
		//左端を決める
		if(A[i] <= S) {
			dp[i+1][A[i]][1] = (i + 1);
			dp[i+1][A[i]][1] %= DIV;
		}
		//左右端を同時に
		if(A[i] == S) {
			dp[i+1][S][2] += (i + 1) * (N-i);
			dp[i+1][S][2] %= DIV;
		}
		dp[i+1][S][2] += dp[i][S][2];
		dp[i+1][S][2] %= DIV;
		for(long long j = 0; j <= S; j++) {
			//A[i]を使う
			if(j + A[i] <= S) {
				dp[i+1][j + A[i]][1] += dp[i][j][1];
				dp[i+1][j + A[i]][1] %= DIV;
			}

			//A[i]を使わない
			dp[i+1][j][1] += dp[i][j][1];
			dp[i+1][j][1] %= DIV;

			//右端を決める
			if(j + A[i] == S) {
				dp[i+1][S][2] += dp[i][j][1] * (N-i);
				dp[i+1][S][2] %= DIV;
			}

		}
	}
	cout << dp[N][S][2] << endl;


	//long long ans = 0;
	////        start left, sum     , num
	//map<pair<long long, long long>, long long> memo;
	//map<pair<long long, long long>, long long> nextmemo;

	//for(long long i = 0; i < N; i++) {

	//	for(auto item: memo) {
	//		long long left = item.first.first;
	//		long long sumi = item.first.second;
	//		long long num = item.second;

	//		nextmemo[item.first] += num;
	//		

	//		//これを使う
	//		if(sumi + A[i] == S) {
	//			//cout << "left = " << left << " right = " << i << endl;
	//			//left - right
	//			ans += (left+1) * (N - i) * num;
	//			ans %= DIV;
	//		} else if(sumi + A[i] < S) {
	//			nextmemo[make_pair(left, sumi + A[i])] += num;
	//		}
	//	}


	//	//start from this
	//	if(A[i] == S) {
	//		//cout << "left = " << i << " right = " << i << endl;
	//		ans += (i+1) * (N - i);
	//		ans %= DIV;
	//	} else if (A[i] < S) {
	//		nextmemo[make_pair(i, A[i])] += 1;
	//	}
	//	swap(memo, nextmemo);
	//	nextmemo.clear();
	//}

	//cout << ans << endl;
}