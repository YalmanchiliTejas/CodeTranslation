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

ll dp[3001][3001][2];
bool vis[3001][3001][2];
int T[3001];

ll count_dp(int a, int b, int c)
{
    if(vis[a][b][c]) return dp[a][b][c];
    if(a == b) return (c ? T[a]*(-1) : T[a]);
    vis[a][b][c] = true;

    if(c == 0)
        dp[a][b][c] = max(count_dp(a + 1, b, 1) + T[a], count_dp(a, b - 1, 1) + T[b]);  
    if(c == 1)
        dp[a][b][c] = min(count_dp(a + 1, b, 0) - T[a], count_dp(a, b - 1, 0) - T[b]);

    return dp[a][b][c];
}
int main()
{
    turbo

    int n; cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> T[i];

    cout << count_dp(1, n, 0);
    
    return 0;
}