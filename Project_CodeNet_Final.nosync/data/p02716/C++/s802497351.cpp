#include <iostream>
#include <vector>
using namespace std;
using lint = long long int;
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<vector<lint>> dp(3, vector<lint>(N + 2, -1e18));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i) chmax(dp[j][i + 1], dp[j][i - 1] + A[i]);
        }

        for (int j = 0; j < 2; j++)
        {
            chmax(dp[j + 1][i + 1], dp[j][i]);
        }
    }
    cout << dp[1 + N % 2].back() << "\n";
}
