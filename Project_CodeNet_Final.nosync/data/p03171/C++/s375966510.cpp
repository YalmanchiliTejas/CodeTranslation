#include <bits/stdc++.h>
using namespace std;

#define MOD (1000 * 1000 * 1000 + 7)
#define INF (1LL << 60)
#define pb push_back
#define po pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;

#define maxn 3005
ll dp[maxn][maxn][2];
int N;
ll A[maxn];

ll solution(int i, int j, int p) {
    if (i > j || j < i) {
        return 0;
    }

    if (dp[i][j][p] != -1) {
        return dp[i][j][p];
    }

    if(p == 0) {
        dp[i][j][p] = max(solution(i + 1, j, (p + 1) % 2) + A[i], solution(i, j - 1, (p + 1) % 2) + A[j]);
    } else {
        dp[i][j][p] = min(solution(i + 1, j, (p + 1) % 2) - A[i], solution(i, j - 1, (p + 1) % 2) - A[j]);
    }

    return dp[i][j][p];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", A + i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solution(0, N - 1, 0));

    return 0;
}