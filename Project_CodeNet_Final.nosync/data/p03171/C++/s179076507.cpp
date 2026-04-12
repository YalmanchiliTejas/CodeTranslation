#include <iostream>
#include <queue>
#include <map>
#include <deque>
#include <algorithm>
#include <set>
#include <string>
#include <math.h>
#include <stdio.h>
#include<iomanip>
#include <cstring>


#define ll long long
using namespace std;
//const ll MOD = (int) 10e9 + 7;

/*ll dp[100001];
vector<vector<ll>>adj;
ll dfs(ll node)
{
    if (dp[node] != -1)
        return dp[node];

    ll ans = 0;
    for (int i = 0; i < adj[node].size(); i++)
    {
        ans = max(dfs(adj[node][i]) + 1, ans);

    }
    return dp[node] = ans;
}
*/
ll dp[3001][3001];
bool flag[3001][3001];
ll factorial(ll n)
{
    if (n == 1 || n == 0)
        return 1;

    return n * factorial(n - 1);
}
ll help(ll i, ll j, ll arr[], ll turn)
{
    if (i > j) return 0;
    if (flag[i][j])
        return dp[i][j];

    if (turn == 1)
    {
        dp[i][j] = max(arr[i] + help(i + 1, j, arr, -1 * turn), arr[j] + help(i, j - 1, arr, -1 * turn));
    }
    else
        dp[i][j] = min(help(i + 1, j, arr, -1 * turn) - arr[i],  (- 1 * arr[j]) + help(i, j - 1, arr, -1 * turn));

    flag[i][j] = true;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < 3001; i++)
    {
        for (ll j = 0; j < 3001; j++)
            flag[i][j] = false;
    }
    cout << help(0, n  - 1, arr, 1);
    /*std::cout<<std::fixed;
    std::cout<<std::setprecision(10)<<ans;*/
    return 0;
}
