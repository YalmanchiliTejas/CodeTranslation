#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MAXN = 3010;

int A[MAXN];
LL dp[MAXN][MAXN];
int N;

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];
	
	memset(dp, 0, sizeof(dp));
	for(int i=N; i>0; i--) {
		for(int j=i; j<=N; j++) {
			if(i==j) dp[i][j] = A[i];
			dp[i][j] = max(A[j]-dp[i][j-1], A[i]-dp[i+1][j]);
		}
	}
	
	cout << dp[1][N] << endl;
	return 0;
}