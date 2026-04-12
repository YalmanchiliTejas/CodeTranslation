#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	string S;
	int K;
	cin >> S >> K;
	int N = S.size();
	vector<vector<ll>> dp_less(N+1, vector<ll>(K+1, 0));
	vector<vector<ll>> dp_eq(N+1, vector<ll>(K+1, 0));

	vector<int> A(N+1, 0);
	for(int i=1;i<=N;i++) A[i] = S[i-1] - '0';

	// 初期化
	dp_less[1][1] = A[1] - 1;
	dp_less[1][0] = 1;
	dp_eq[1][1] = 1;

	for(int i=2;i<=N;i++) {
		for(int j=1;j<=K;j++) {
			dp_less[i][0] = 1;
			// dp_eqからdp_eqに
			if(A[i] == 0) dp_eq[i][j] = dp_eq[i-1][j];
			else dp_eq[i][j] = dp_eq[i-1][j-1];
			// dp_lessからdp_lessに
			dp_less[i][j] += 9 * dp_less[i-1][j-1] + dp_less[i-1][j];
			// dp_eqからdp_lessに
			if(A[i] > 0) dp_less[i][j] += dp_eq[i-1][j] + (A[i] - 1) * dp_eq[i-1][j-1];
		}
	}

	cout << dp_less[N][K] + dp_eq[N][K] << endl;
}