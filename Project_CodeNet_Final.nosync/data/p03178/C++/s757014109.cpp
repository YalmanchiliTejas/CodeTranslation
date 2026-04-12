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
const int N = 1e4 + 7;
const int D = 107;
const int M = 1e9 + 7;

string k;
int d;
ll f[N][2][D];
bool vis[N][2][D];

void DP(int pos, bool prefix, int mod)
{
     if(vis[pos][prefix][mod]) return;
     vis[pos][prefix][mod] = 1;
     if(pos >= k.size())
     {
         if(mod == 0) f[pos][prefix][mod] = 1;
         else f[pos][prefix][mod] = 0;
         return;
     }
     ll& res = f[pos][prefix][mod];
     int lim = prefix? k[pos] - '0': 9;
     for(int i = 0; i <= lim; ++i)
     {
         int nxt = (mod + i) % d;
         DP(pos + 1, prefix && i == lim, nxt);
         res += f[pos + 1][prefix && i == lim][nxt];
         res %= M;
     }
}

void Enter()
{
     cin >> k >> d;
     DP(0, 1, 0);
     --f[0][1][0];
     if(f[0][1][0] < 0) f[0][1][0] += M;
     cout << f[0][1][0];
}

void Solve()
{

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
