#include <iostream>
#include <assert.h>
#include <vector>
#include <stdio.h>
using namespace std;

const int NMAX = 3010;

long long dp[NMAX][NMAX];
int v[NMAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
