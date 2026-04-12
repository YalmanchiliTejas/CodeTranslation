#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    lint mod = 1e9 + 7;
    lint n;
    cin >> n;
    lint ans=0, tmp,sum_a=0;
    vector<lint> a(n);
    REP(i, n){
        cin >> a[i];
        sum_a += a[i];
        sum_a %= mod;
    }
    REP(i,n){
        lint x = sum_a + mod - a[i];
        ans = ans + x * a[i];
        ans%=mod;
    }

    ans = (ans * modinv(2, mod)) % mod;
    cout << ans <<"\n";

    return 0;
}