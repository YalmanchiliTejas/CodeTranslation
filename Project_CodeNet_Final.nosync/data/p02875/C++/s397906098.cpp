#include <bits/stdc++.h>

#define MAX_N 10000000

using namespace std;

typedef long long lint;

const int MOD = 998244353;

int n;

lint putere(int a, int b)
{
    lint rez = 1;
    lint ca = a;
    for(int i = 0; (1 << i) <= b; i ++)
    {
        if(((1 << i) & b) != 0)
        {
            rez *= ca;
            rez %= MOD;
        }

        ca *= ca;
        ca %= MOD;
    }

    return rez;
}

lint p2[MAX_N + 1];
lint fact[MAX_N + 1];
lint inv[MAX_N + 1];

void euclid(lint a, lint b, lint &x, lint &y, lint &d)
{
    if(b == 0)
    {
        x = 1;
        y = 0;

        d = a;
        return;
    }

    lint xx, yy, q = a / b;
    euclid(b, a % b, xx, yy, d);
    x = yy;
    y = xx - yy * q;
}

lint comb(int n, int k)
{
    return (fact[n] * inv[k] % MOD * inv[n - k] % MOD);
}

int main()
{
    cin >> n;

    p2[0] = 1;
    fact[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        p2[i] = (p2[i - 1] << 1) % MOD;
        fact[i] = fact[i - 1] * i % MOD;
    }

    lint x, y, d;
    euclid(fact[n], MOD, x, y, d);
    if(x < 0)
        x = MOD + x % MOD;

    //cout << fact[n] << " " << x << "\n";
    //cout << fact[n] * x % MOD << "\n";

    inv[0] = 1;
    inv[n] = x;
    for(int i = n - 1; i >= 1; i --)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

       // cout << inv[1] << "\n";

    lint rez = putere(3, n);
    lint sum = 0;
    for(int i = (n >> 1) + 1; i <= n; i ++)
    {
      //  cout << n << " " << i << " " << comb(n, i) << " " << p2[n - i] << "\n";
        sum += comb(n, i) * p2[n - i] % MOD;
        if(sum >= MOD)
            sum -= MOD;
    }

    rez = rez - (sum << 1);
    while(rez < 0)
        rez += MOD;

    cout << rez << "\n";

    return 0;
}
