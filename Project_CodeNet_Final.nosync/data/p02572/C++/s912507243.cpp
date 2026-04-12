#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
const int MOD(1e9 + 7);
int n, v[200005], s, res;
int powlog(int baza, int exp)
{
    int rez = 1;
    while (exp)
    {
        if(exp % 2 == 1)
            rez = rez * baza % MOD;
        baza = baza * baza % MOD;
        exp /= 2;
    }
    return rez;
}
main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        s += v[i];
    }
    for (int i = 1; i <= n; ++i)
        (res += ((s - v[i]) % MOD * v[i])) %= MOD;
    (res *= powlog(2, MOD - 2)) %= MOD;
    cout << res;
    PLEC
}
