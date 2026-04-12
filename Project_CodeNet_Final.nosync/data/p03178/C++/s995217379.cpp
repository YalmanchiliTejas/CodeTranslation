#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 105;
#define mod   1000000007
int dp[N][M][2];
int n, m;
string num;
int d;
int add(long long a, long long b)
{
    return ((a % mod) + (b % mod)) % mod;
}
long long help(long long idx, long long sum, long long tight)
{
    if (idx == n)
        return sum == 0;
    if (dp[idx][sum][tight] != -1)
        return dp[idx][sum][tight];
    long long res = 0;
    int biggest;
    if (tight)
     biggest= (num[idx]-'0') ;
     else
        biggest=9;
    for (int i = 0; i <= biggest; i++)
    {
        int newtight = ((num[idx]-'0')== i) ? tight : 0;
        res = add(res,help(idx + 1, (sum + i) % d, newtight));
    }
    return dp[idx][sum][tight] = res;
}
void solve()
{
    memset(dp, -1, sizeof dp);
    cin >> num;
    cin >> d;
    n = num.size();
    cout << ((help(0, 0, 1) % mod - 1 % mod) + mod) % mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
