#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
const int MAX_N = 3008;

int N;
ll A[MAX_N];
ll dp[MAX_N][MAX_N];

void solve()
{
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<N; ++i) dp[i][i]=A[i];
	for(int len=2; len<=N; ++len)for(int i=0; i+len<=N;++i){
		int j = i+len-1;
		dp[i][j] = max(A[i]+min(dp[i+1][j-1], dp[i+2][j]), A[j]+min(dp[i][j-2], dp[i+1][j-1]));
	}
	cout << 2*dp[0][N-1]-accumulate(A, A+N, 0LL) << endl;
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i)cin >> A[i];
	solve();
	return 0;
}