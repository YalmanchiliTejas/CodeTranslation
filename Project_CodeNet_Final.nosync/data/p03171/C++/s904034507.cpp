#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
vector<ll> deque;
vector<vector<ll>> dp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	deque.assign(N, 0);
	for(int i = 0; i < N; i++) cin >> deque[i];

	dp.assign(N, vector<ll>(N, 0));
	for(int r = 0; r < N; r++){
		for(int l = r; l >= 0; l--){
			if (l == r) dp[l][r] = deque[l];
			else {
				dp[l][r] = max(deque[l] - dp[l+1][r], deque[r] - dp[l][r-1]);
			}
		}
	}

	cout << dp[0][N-1] << endl;
	return 0;
}