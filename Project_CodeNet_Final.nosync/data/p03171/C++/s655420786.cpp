#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >

int N;
ll A[3100];
ll dp[3100][3100];

int main() {

	cin >> N;
	rep(i, N) cin >> A[i];

	rep(i, N + 1) dp[i][i] = 0;

	for (int w = 1; w <= N; w++) {
		for (int l = 0; l + w <= N; l++) {

			int r = w + l;
			if (w % 2 == N % 2) {
				dp[l][r] = max(dp[l + 1][r] + A[l],
					dp[l][r - 1] + A[r - 1]);
			}
			else {
				dp[l][r] = min(dp[l + 1][r] - A[l], 
					dp[l][r - 1] - A[r - 1]);
			}
		}
	}

	cout << dp[0][N] << endl;

}
