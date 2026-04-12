#include <iostream>
using namespace std;

const long long INF = 1LL << 60;

int N;
int a[3009];

long long dp[3009][3009];

long long solve(int l, int r) {
    if(l == r) return a[l];
    if(dp[l][r] != INF) return dp[l][r];
    return dp[l][r] = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> a[i];

    for(int i = 0; i < 3009; i++)
        for(int j = 0; j < 3009; j++)
            dp[i][j] = INF;

    cout << solve(1, N) << endl;
}