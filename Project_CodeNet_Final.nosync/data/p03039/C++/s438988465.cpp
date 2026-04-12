#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200200;
const int Mod = 1e9 + 7;

int Inv[N];
int Fact[N];
int iFact[N];

void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}

void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += Mod;
}

int mul(int x, int y)
{
    return (ll) x * y % Mod;
}

int fp(int x, int y)
{
    int Res = 1;
    for(; y > 0; y >>= 1, x = mul(x, x))
        if(y & 1)
            Res = mul(Res, x);
    return Res;
}

int C(int n, int k)
{
    if(n < 0 || k < 0 || n < k) return 0;
    return mul(Fact[n], mul(iFact[k], iFact[n - k]));
}

int main()
{
    Inv[1] = 1;
    for(int i = 2; i < N; i++)  Inv[i] = (Mod - mul(Mod / i, Inv[Mod % i])) % Mod;

    Fact[0] = iFact[0] = 1;
    for(int i = 1; i < N; i++)  Fact[i] = mul(i, Fact[i - 1]);
    for(int i = 1; i < N; i++)  iFact[i] = mul(Inv[i], iFact[i - 1]);

    int n, m, k;    cin >> n >> m >> k;

    int Ans = 0;

    for(int x = 1; x <= n; x++)
    {
        add_self(Ans, mul(x, mul(mul(C(n * m - 2, k - 2), m), mul(x - 1, m))));
        sub_self(Ans, mul(x, mul(mul(C(n * m - 2, k - 2), m), mul(n - x, m))));
    }

    for(int y = 1; y <= m; y++)
    {
        add_self(Ans, mul(y, mul(mul(C(n * m - 2, k - 2), n), mul(y - 1, n))));
        sub_self(Ans, mul(y, mul(mul(C(n * m - 2, k - 2), n), mul(m - y, n))));
    }

    cout << Ans << endl;
}
