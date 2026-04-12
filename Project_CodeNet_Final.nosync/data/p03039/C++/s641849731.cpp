#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod = 1e9 + 7;

const int maxn = 2e5 + 10;
LL fact[maxn];

LL ModPow(LL a, LL b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ans;
}

LL nCr(LL a, LL b)
{
    LL ans = fact[a] * ModPow(fact[b], Mod - 2) % Mod;
    ans = ans * ModPow( (fact[a -b] + Mod) % Mod, Mod - 2) % Mod;
    return ans;
}

void init()
{
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % Mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    LL n,m,k;
    cin >> n >> m >> k;
    LL ans = nCr(n*m, k) * nCr(k, 2) % Mod * ModPow(3, Mod - 2) % Mod;
    ans = ans * (n + m) % Mod;
    ans %= Mod;
    cout << ans << endl;
    return 0;
}
