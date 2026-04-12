#include <bits/stdc++.h>

#define MOD  998244353
const long long nmax = 1e7+1;

using namespace std;

int n;
long long thr[nmax], tw[nmax], fr[nmax];

long long mul(long long a, long long b)
{
    return (a * b) % MOD;
}

long long add(long long a, long long b)
{
    return (a + b) % MOD;
}

long long sub(long long a, long long b)
{
    long long o = a - b;

    while (o < 0) o += MOD;
    return o;
}

long long Pow(long long a, long long b)
{
    if (b == 1) return a;
    long long o = Pow(a, b/2);

    if (b % 2 == 1) return mul(mul(o, o), a);
    return mul(o, o);
}

long long Ckn(long long a, long long b)
{
    return mul(fr[b], Pow(mul(fr[a], fr[b-a]), MOD - 2));
}

void Input()
{
    ios_base::sync_with_stdio(0);       cin.tie(0);

//    freopen("abc.txt", "r", stdin);

    cin >> n;   thr[0] = tw[0] = fr[0] = 1;
    for (int i=1; i<=n; i++)
    {
        thr[i] = mul(thr[i-1], 3);
        tw[i] = mul(tw[i-1], 2);
        fr[i] = mul(fr[i-1], i);
    }
}

void Process()
{
    long long ans = 0;
    for (int i=n/2+1; i<=n; i++)
        ans = add(ans, mul(Ckn(i, n), tw[n-i+1]));

//    cout << Ckn(2, n) << endl;
//    cout << ans << endl;

    cout << sub(thr[n], ans);
}

int main()
{
    Input();
    Process();
    return 0;
}
