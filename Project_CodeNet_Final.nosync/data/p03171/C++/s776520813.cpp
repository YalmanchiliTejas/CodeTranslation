#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int N = 3000 + 2;

array<array<long long, N>, N> dp;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    auto f = [&](int i, int j) -> long long {
        if (i > j) return 0;
        return dp[i][j];
    };
    for (int j = 0; j < n; ++j)
        for (int i = j; i >= 0; --i)
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);

    cout << dp[0][n - 1];
    return 0;
}
