#include <iostream>
using namespace std;

#define ll long long int
#define L 3000

ll dp[L + 5][L + 5], A[L + 5];

ll max(ll a, ll b)
{
    if (a >= b) return(a);
    return(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i][i] = A[i];
    }
    for (int i = 1; i < N; i++) for (int j = 0; j + i < N; j++) dp[j][j + i] = max(A[j] - dp[j + 1][j + i], A[j + i] - dp[j][j + i - 1]);
    cout << dp[0][N - 1] << '\n';
    return(0);
}