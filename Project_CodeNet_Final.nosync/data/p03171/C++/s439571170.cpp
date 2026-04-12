#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;

long long dp[MAXN][MAXN][2];

int arr[MAXN];
int n;

void update_dp(int lengh)
{
    for(int i = 0; i <= n - lengh; i++){
        long long ans1, ans2;
        ans1 = arr[i] + dp[lengh - 1][i + 1][1];
        ans2 = arr[i + lengh - 1] + dp[lengh - 1][i][1];

        dp[lengh][i][0] = max(ans1, ans2);

        dp[lengh][i][1] =  dp[lengh - 1][i + 1][0];

        if(ans2 > ans1) dp[lengh][i][1] = dp[lengh - 1][i][0];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout << fixed << setprecision(10);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++) update_dp(i);

    cout << dp[n][0][0] - dp[n][0][1] << endl;


    return 0;
}

