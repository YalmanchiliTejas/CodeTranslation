#include <iostream>
#define Nmax 3005

using namespace std;

long long v[Nmax], n, dp[Nmax][Nmax];

void read()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
}

void solve()
{
    int parityOfFirst = n % 2;
    int parityOfSecond = (parityOfFirst + 1) % 2;

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = v[i];
    }

    for (int left = n; left >= 0; --left) {
        for (int right = 1; right <= n; ++right) {
            if (left <= right) {
                if ((right - left + 1) % 2 == parityOfFirst) {
                    dp[left][right] = max(dp[left][right - 1] + v[right], dp[left + 1][right] + v[left]);
                }
                else {
                    dp[left][right] = min(dp[left][right - 1] - v[right], dp[left + 1][right] - v[left]);
                }
            }
        }
    }
    cout << dp[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    read();
    solve();
    return 0;
}
