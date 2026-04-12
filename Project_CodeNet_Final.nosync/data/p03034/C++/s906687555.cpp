#include<iostream>
#include<algorithm>
#include<set>
 
using namespace std;
typedef long long ll;
 
ll ans = 0;
int N;
ll s[100000];
 
ll dp[101000];//dp[k]だった時のans cは配列の使いまわしのよってカバー
set<int> used;
 
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
 
	ll ans = 0;// == 0の時の答えが0
 
	for (int C = 1; C <= N - 2; C++) {
		used.clear();
		//kを決めてる
		dp[0] = 0;
		for (int k = 1;; k++) {
			if (N - 1 - C * k <= 0)break;
			if (k * C >= N - 1)break;
			if (N - 1 - C * k - C <= 0)break;
			if (2 * C * k == N - 1)continue;
			if (used.find(C * k) != used.end() || used.find(N - 1 - C * k) != used.end())break;
			dp[k] = dp[k - 1] + s[N - 1 - k * C] + s[C * k];
			ans = max(ans, dp[k]);
			used.insert(C * k), used.insert(N - 1 - k * C);
		}
	}
	cout << ans << endl;
	return 0;
}