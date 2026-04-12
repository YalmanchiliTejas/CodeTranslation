#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll dp[201010][2][2];
int N;
ll A[201010];

int main()
{
    cin >> N;
    repe(i, 1, N)
    {
        cin >> A[i];
    }

    /*
    if (N % 2 == 0) {
        ll sum1 = 0;
        ll sum2 = 0;
        repe(i, 1, N / 2)
        {
            sum1 += A[2 * i];
            sum2 += A[2 * i - 1];
        }
        cout << max(sum1, sum2) << endl;
        return 0;
    }
    */

    dp[1][1][1] = A[1];
    dp[2][1][0] = dp[1][1][1];
    dp[2][1][1] = A[2];
    dp[3][0][0] = max(dp[2][1][0], dp[2][1][1]);

    repe(i, 3, N)
    {
        if (i % 2 == 0) {
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]);
            dp[i][1][0] = dp[i - 1][1][1];
            dp[i][1][1] = dp[i - 1][0][0] + A[i];
        } else {
            dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
            dp[i][0][1] = dp[i - 1][0][0] + A[i];
            dp[i][1][0] = 0;
            dp[i][1][1] = dp[i - 1][1][0] + A[i];
        }
    }

    if (N % 2 == 0) {
        cout << max(dp[N][1][0], dp[N][1][1]) << endl;
    } else {
        cout << max(dp[N][0][0], dp[N][0][1]) << endl;
    }
}