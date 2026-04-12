#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a, _b = b; i <= _b; ++i)
#define Ford(i, a, b) for(int i = a, _b = b; i >= _b; --i)
#define FileName      "test"
#define ll            long long
#define ld            long double
#define ull           unsigned long long
#define Print(x)      cerr << #x << "is " << x << '\n';
#define pb            push_back
#define X             first
#define Y             second
//#define Karma

using namespace std;

template<typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}
template <typename T> inline void Out(T x) {if(x > 9) Out(x / 10); putchar(x % 10 + '0');}
template <typename T> inline void Cout(T x, char c) {if(x < 0) putchar('-'); x = abs(x); Out(x); putchar(c);}
template <typename T, typename... Args> inline void Cin(T& a, Args&... args) {Cin(a);Cin(args...);}
template <typename T, typename... Args> inline void Cout(T a, char c, Args... args) {Cout(a, c);Cout(args...);}

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int N = 3007;

ll f[N][N], n, a[N];

ll S(int l, int r)
{
    if(l > r) return 0;
    return a[r] - a[l - 1];
}

void Enter()
{
     Cin(n);
     For(i, 1, n) Cin(a[i]), a[i] += a[i - 1];
}

void Solve()
{
     for(int l = n; l >= 1; --l)
     {
         f[l][l] = a[l];
         f[l][l + 1] = max(a[l] - a[l - 1], a[l + 1] - a[l]);
         for(int r = l + 2; r <= n; ++r)
         {
             f[l][r] = max(S(l + 1, r) - f[l + 1][r] + a[l] - a[l - 1], S(l, r - 1) - f[l][r - 1] + a[r] - a[r - 1]);
         }
     }
     cout << 2 * f[1][n] - a[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef Karma
    freopen(FileName".inp", "r", stdin);
    freopen(FileName".out", "w", stdout);
#endif // Karma

    Enter();
    Solve();

    return 0;
}
