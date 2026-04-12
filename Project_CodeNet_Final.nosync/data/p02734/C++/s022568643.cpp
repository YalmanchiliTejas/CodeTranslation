#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 6100;
const ll MOD = 998244353;

int N, S;
int arr[MAXN];
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp[0] = 1;
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int x = arr[i];
        for (int j = S; j >= 0; j--)
        {
            if (j) dp[j+x] = (dp[j+x] + dp[j]) % MOD;
            else dp[j+x] = (dp[j+x] + (N - i) * dp[j]) % MOD;
        }

        ans = (ans + dp[S]) % MOD;
    }
    cout << ans << "\n";
}