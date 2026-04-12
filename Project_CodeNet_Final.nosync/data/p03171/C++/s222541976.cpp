#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout<<"["<<#__VA_ARGS__<<": "<<__VA_ARGS__<<"]\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 3e3 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
ll arr[maxn], dp[maxn][maxn][2];
ll solve(int l, int r, ll f)
{
    if(dp[l][r][f] != -1) return dp[l][r][f];
    if(l == r) return f * arr[l];
    if(f == 1) return dp[l][r][1] = max(arr[l] + solve(l + 1, r, 0), arr[r] + solve(l, r - 1, 0));
    else return dp[l][r][0] = min(solve(l + 1, r, 1), solve(l, r - 1, 1));
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << 2 * solve(1, n, 1) - sum << "\n";
    return 0;
}
