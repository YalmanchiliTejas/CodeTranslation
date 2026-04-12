#include <iostream>

using namespace std;
#define long long long

const long MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m, k;
long res;

long Count_Dis(int i) {return (long) (i + 1)*i/2;}

void Pre()
{
    res = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = n - i;
        res = (res + Count_Dis(tmp)) % MOD;
    }
    res = (res*m) % MOD, res = (res*m) % MOD;

    long rt = 0;
    for (int i = 1; i <= m; ++i) {
        int tmp = m - i;
        rt = (rt + Count_Dis(tmp)) % MOD;
    }

    rt = (rt*n) % MOD, rt = (rt*n) % MOD;
    res += rt, res %= MOD;
}

long power(long a, long n)
{
    if (n == 1) return a;
    if (n == 0) return 1;
    long tmp = power(a, n/2);
    if (n % 2 == 0) return (tmp * tmp) % MOD;
    tmp = (tmp * tmp) % MOD, tmp = (tmp * a) % MOD;
    return tmp;
}

int main()
{
    cin >> n >> m >> k;
    Pre();
    long nn = (long) n*m - 2, kk = k - 2;
    long tu = 1, mau = 1;
    for (int i = kk + 1; i <= nn; ++i) tu = (tu*i) % MOD;
    for (int i = 1; i <= nn - kk; ++i) mau = (mau*i) % MOD;
    mau = power(mau, MOD - 2);

    res = (res * tu) % MOD;
    res = (res * mau) % MOD;
    cout << res;

    return 0;
}
