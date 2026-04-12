#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[200005];

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	if(false) {
		long long odd = 0;
		long long even = 0;
		for(long long i = 0; i < N; i++) {
			if(i%2 == 0) {
				even+=A[i];
			} else {
				odd+=A[i];
			}
		}
		cout << max(even, odd) << endl;
		return 1;
	} else {
		//  get count, max        1はskipしないといけない, 0はskipしなくていい
		map<long long, long long> dp[2];
		map<long long, long long> dpnext[2];


		dp[0][0] = 0;
		for(long long i = 0; i < N; i++) {
			long long mini = i/2 - 10;
			long long maxi = i/2 + 10;
			//cout << "i = " << i << endl;
			//cout << "dp[0]" << endl;
			//for(auto item: dp[0]) {
			//	cout << item.first << ", " << item.second << endl;
			//}
			//cout << "dp[1]" << endl;
			//for(auto item: dp[1]) {
			//	cout << item.first << ", " << item.second << endl;
			//}

			//取る
			for(auto item: dp[0]) {
				if(item.first > mini && item.first < maxi) {
					if(dpnext[1].count(item.first + 1) > 0) {
						dpnext[1][item.first + 1] = max(dpnext[1][item.first + 1], item.second + A[i]);
					} else {
						dpnext[1][item.first + 1] = item.second + A[i];
					}
				}
			}
			//撮らない
			for(auto item: dp[0]) {
				if(item.first > mini && item.first < maxi) {
					if(dpnext[0].count(item.first) > 0) {
						dpnext[0][item.first] = max(dpnext[0][item.first], item.second);
					} else {
						dpnext[0][item.first] = item.second;
					}
				}
			}
			for(auto item: dp[1]) {
				if(item.first > mini && item.first < maxi) {
					if(dpnext[0].count(item.first) > 0) {
						dpnext[0][item.first] = max(dpnext[0][item.first], item.second);
					} else {
						dpnext[0][item.first] = item.second;
					}
				}
			}
			swap(dp, dpnext);
			dpnext[0].clear();
			dpnext[1].clear();
		}


		long long ans = LONG_MIN;
		//cout << "i = " << N << endl;
		//cout << "dp[0]" << endl;
		for(auto item: dp[0]) {
			//cout << item.first << ", " << item.second << endl;
			if(item.first == N/2) {
				ans = max(ans, item.second);
			}
		}
		//cout << "dp[1]" << endl;
		for(auto item: dp[1]) {
			//cout << item.first << ", " << item.second << endl;
			if(item.first == N/2) {
				ans = max(ans, item.second);
			}
		}
		cout << ans << endl;
	}
}
