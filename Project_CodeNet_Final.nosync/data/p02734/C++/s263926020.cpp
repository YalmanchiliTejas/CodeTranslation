#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 3e3+5;
ll n , s , a[N] , dp[N][N] , suf[N] , pre[N] , mod = 998244353;

int mul(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (1ll * a * b) % mod;
}

int add(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

int solve(int i , int sum)
{
    if (i==0) return sum == s;
    if (sum > s) return 0;

    if (sum == s) return i+1;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int ans = solve(i-1 , sum);
    ans = add(ans , solve(i-1 , sum+a[i]));

    return dp[i][sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    memset(dp , -1 , sizeof(dp));

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        pre[i] = solve(i-1 , a[i]);
        ans = add(ans , mul(n-i+1 , pre[i]));
    }

    cout << ans << '\n';

    return 0;
}
