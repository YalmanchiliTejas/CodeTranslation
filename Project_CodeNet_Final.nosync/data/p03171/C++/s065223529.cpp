#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 3005;

int N;
vector<int> A;
long long dp[N_MAX][N_MAX];

int main() {
    scanf("%d", &N);
    A.resize(N);

    for (int &a : A)
        scanf("%d", &a);

    for (int i = 0; i <= N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 0; i--)
        for (int j = i + 1; j <= N; j++)
            dp[i][j] = max(A[i] - dp[i + 1][j], A[j - 1] - dp[i][j - 1]);

    printf("%lld\n", dp[0][N]);
}
