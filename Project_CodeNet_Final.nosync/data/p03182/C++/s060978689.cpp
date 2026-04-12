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
const int N = 2e5 + 7;
const ll oo = 1e18 + 7;

int n, m, l, r, x;
vector<pii> add[N], del[N];

struct TSegment
{
    int l[N << 2], h[N << 2];
    ll st[N << 2], lazy[N << 2];
    #define mid (low + high) / 2
    void Build(int x, int low, int high)
    {
         l[x] = low, h[x] = high;
         if(l[x] == h[x]) return;
         Build(x << 1, low, mid);
         Build(x << 1 | 1, mid + 1, high);
    }
    void Down(int x)
    {
        st[x] += lazy[x];
        if(l[x] == h[x] || !lazy[x]) {lazy[x] = 0; return;}
        lazy[x << 1] += lazy[x], lazy[x << 1 | 1] += lazy[x];
        lazy[x] = 0;
    }
    void Update(int x, int low, int high, ll v)
    {
         Down(x);
         if(low > h[x] || l[x] > high) return;
         if(low <= l[x] && h[x] <= high)
         {
             lazy[x] += v;
             Down(x);
             return;
         }
         Update(x << 1, low, high, v);
         Update(x << 1 | 1, low, high, v);
         st[x] = max(st[x << 1], st[x << 1 | 1]);
    }
    ll Query(int x, int low, int high)
    {
        Down(x);
        if(low > h[x] || l[x] > high) return -oo;
        if(low <= l[x] && h[x] <= high) return st[x];
        return max(Query(x << 1, low, high), Query(x << 1 | 1, low, high));
    }
    #undef mid
} Seg;

void Enter()
{
     Cin(n, m);
     while(m --)
     {
         Cin(l, r, x);
         add[l].emplace_back(l - 1, x), del[r].emplace_back(l - 1, -x);
     }
}

void Solve()
{
     ll res = 0;
     Seg.Build(1, 0, n);
     For(i, 1, n)
     {
         for(pii p: add[i]) Seg.Update(1, 0, p.X, p.Y);
         ll f = Seg.Query(1, 0, i - 1);
         res = max(res, f);
         Seg.Update(1, i, i, f);
         for(pii p: del[i]) Seg.Update(1, 0, p.X, p.Y);
     }
     cout << res;
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
