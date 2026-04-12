#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 1e4 + 50, INF = 1e15, MOD = 1e9 + 7, max_Mod = 100;
string K;
ll N, D;
ll DP[max_N][max_Mod][2];

ll num_integers(ll pos, ll mod, bool tight)
{
    if (pos == N)
        return (mod == 0);
    ll &res = DP[pos][mod][tight];
    if (res != -1)
        return res;
    res = 0;
    ll curr_digit = K[pos] - '0';
    ll up_digit = 9;
    if (tight)
        up_digit = curr_digit;
    for (ll d = 0; d <= up_digit; ++d)
    {
        res += num_integers(pos + 1, (mod + d) % D, tight && (d == up_digit));
        res %= MOD;
    }
    return res;
}

int main()
{
    cin >> K >> D;
    N = K.length();
    memset(DP, -1, sizeof(DP));
    ll ans = num_integers(0, 0, 1);
    ans = (ans -1 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}