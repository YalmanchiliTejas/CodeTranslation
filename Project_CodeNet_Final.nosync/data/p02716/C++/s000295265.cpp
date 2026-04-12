#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAXN 200000

int N, A[MAXN + 3], idxMini;
LL dp[MAXN + 3][2][2];

LL solve(int group, int pos, int skipCount) {
    if (group == 0) {
        return (skipCount > 0 ? -1e15 : 0);
    }

    if (dp[group][pos][skipCount] != -1)
        return dp[group][pos][skipCount];

    int idx = (group - 1) * 2;
    LL result = (skipCount > 0 ? max(solve(group - 1, 0, skipCount - 1), solve(group - 1, 1, skipCount - 1)) : -1e15);

    if (pos == 0) {
        result = max(result, solve(group - 1, 0, skipCount) + A[idx + 1]);
    } else {
        result = max(result, max(solve(group - 1, 0, skipCount), solve(group - 1, 1, skipCount)) + A[idx + 2]);
    }

    return dp[group][pos][skipCount] = result;
}

int main() {
    cin >> N;

    idxMini = 1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] < A[idxMini])
            idxMini = i;
    }

    memset(dp, -1, sizeof(dp));

    if (N%2 == 0)
        cout << max(solve(N/2, 0, 0), solve(N/2, 1, 0)) << endl;
    else {
        LL first = max(solve(N/2, 0, 0), solve(N/2, 1, 0));
        LL second = A[N] + solve(N/2, 0, 1);

        cout << max(first, second) << endl;
    }
}
