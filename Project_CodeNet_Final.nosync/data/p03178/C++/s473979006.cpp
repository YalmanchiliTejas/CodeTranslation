#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
#define turbo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define qi queue<int>
#define ld long double

using namespace std;

/*---------------------------------------------------------///CODE///---------------------------------------------------------*/

int dp[100][2];
int dp2[100][2];

void clear_dp()
{
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 2; j ++)
            dp2[i][j] = 0;

}
void add_dp()
{
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 2; j++) 
            dp[i][j] = dp2[i][j];
    clear_dp();
}
const int MOD = 1e9 + 7;

int main()
{
    turbo

    dp[0][0] = 1;

    string K; cin >> K;
    int d; cin >> d;

    for(int i = 0; i < K.size(); i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = K[i] - '0' + 1; k <= 9; k++)
                (dp2[(j + k) % d][1] += dp[j][1]) %= MOD;

            for(int k = 0; k < K[i] - '0'; k++)
            {
                (dp2[(j + k) % d][1] += (dp[j][0] + dp[j][1])) %= MOD;
            }
            (dp2[(j + K[i] - '0') % d][0] += dp[j][0]) %= MOD;
            (dp2[(j + K[i] - '0') % d][1] += dp[j][1]) %= MOD;
        }
        add_dp();
    }

    cout << (dp[0][0] + dp[0][1] - 1 + MOD)% MOD;
    return 0;
}