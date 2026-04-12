#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i,N) cin >> A[i];

    if (N == 2) {
        cout << max(A[0], A[1]) << endl;
        return 0;
    }

    vector< vector<long long> > dp(N, vector<long long>(3, (-1) * LINF));
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    dp[2][0] = A[0] + A[2];
    dp[2][2] = A[2];
    for (int i = 3; i < N; i++) {
        dp[i][0] = dp[i - 2][0] + A[i];
        dp[i][1] = max(dp[i - 2][1] + A[i], dp[i - 3][0] + A[i]);
        dp[i][2] = max(dp[i - 2][2] + A[i], max(dp[i - 3][1] + A[i], i > 3 ? dp[i - 4][0] + A[i] : (-1) * LINF));
    }

    if (N % 2 == 0) cout << max(dp[N - 2][0], dp[N - 1][1]) << endl;
    else cout << max(dp[N - 3][0], max(dp[N - 2][1], dp[N - 1][2])) << endl;
    
    return 0;
}