#include<bits/stdc++.h>
using namespace std;
#define sz 10010
#define MOD 1000000007
#define ll long long

inline ll add(ll a, ll b)
{
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (a + b) % MOD;
}

inline ll sub(ll a, ll b)
{
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a - b) % MOD + MOD) % MOD;
}

ll dp[sz][2][105];
string s;
int D, N;

ll f(int idx, bool tight, int val)
{
    if (idx == N)
        return (val == 0);
    ll &ans = dp[idx][tight][val];
    if (ans != -1)
        return ans;
    ans = 0;
    if (tight)
    {
        int dig = s[idx] - '0';
        for (int i = 0; i < dig; i++)
            ans = add(ans, f(idx + 1, 0, (val - i + D) % D));
        ans = add(ans, f(idx + 1, 1, (val - dig + D) % D));
    }
    else
    {
        for (int i = 0; i <= 9; i++)
            ans = add(ans, f(idx + 1, 0, (val - i + D) % D));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> s >> D;

    N = s.length();

    cout << sub(f(0, 1, 0), 1);



    return 0;
}