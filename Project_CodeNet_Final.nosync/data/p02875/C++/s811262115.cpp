#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define End exit(0)
#define LL long long
#define mp make_pair
#define SZ(x) ((int) x.size())
#define GO cerr << "GO" << endl
#define DE(x) cout << #x << " = " << x << endl
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

void proc_status()
{
	freopen("/proc/self/status","r",stdin);
	string s; while(getline(cin, s)) if (s[2] == 'P') { cerr << s << endl; return; }
}

template<typename T> inline T read() 
{
	register T x = 0;
	register char c; register int f(1);
	while (!isdigit(c = getchar())) if (c == '-') f = -1;
	while (x = (x << 1) + (x << 3) + (c ^ 48), isdigit(c = getchar()));
	return x * f;
}

template<typename T> inline bool chkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }

const int maxN = 1e7 + 2;
const int mod = 998244353;

int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1) ans = 1ll * ans * a % mod;
    return ans;
}

inline void Inc(int &x) { x < 0 ? x += mod : 0; }

int fac[maxN + 2], ifac[maxN + 2], pw2[maxN + 2];

void init(int N = 1e7)
{
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = (LL) fac[i - 1] * i % mod;
    ifac[N] = qpow(fac[N], mod - 2);
    for (int i = N - 1; i >= 0; --i) ifac[i] = (LL) ifac[i + 1] * (i + 1) % mod;
    pw2[0] = 1;
    for (int i = 1; i <= N; ++i) pw2[i] = pw2[i - 1] * 2ll % mod;
}

int C(int n, int m)
{
    if (n < m) return 0;
    return (LL) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n;

void input() { n = read<int>(); }

void solve()
{
    int ans = qpow(3, n);
    for (int i = n / 2 + 1; i <= n; ++i)
        Inc(ans -= 2ll * C(n, i) * pw2[n - i] % mod);
    printf("%d\n", ans);
}

int main() 
{ 
    input(), init(), solve();
	return 0;
}

