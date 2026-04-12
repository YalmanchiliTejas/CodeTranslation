#include <bits/stdc++.h>

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

//{{{
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while
(getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}

const int mod = 1e9 + 7;
const int N = 200010;
const LL inf = 1e18;

int n, m;

#define L(x) x << 1
#define R(x) x << 1 | 1

struct st
{
    int l, r;
    LL lazy, maxi;
} seg[N << 2];

void pushup(int rt) { seg[rt].maxi = max(seg[L(rt)].maxi, seg[R(rt)].maxi); }

void pushdown(int rt)
{
    if (seg[rt].lazy)
    {
        seg[L(rt)].lazy += seg[rt].lazy;
        seg[R(rt)].lazy += seg[rt].lazy;
        seg[L(rt)].maxi += seg[rt].lazy;
        seg[R(rt)].maxi += seg[rt].lazy;
        seg[rt].lazy = 0;
    }
}

void build(int l, int r, int rt = 1)
{
    if (rt == 1) r++;
    seg[rt].l = l, seg[rt].r = r;
    // debug(l, r);
    seg[rt].lazy = 0;

    if (l + 1 == r)
    {
        seg[rt].maxi = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, L(rt));
    build(mid, r, R(rt));

    pushup(rt);
}

void modify(int l, int r, LL val, int rt = 1)
{
    if (rt == 1) r++;
    if (l <= seg[rt].l && seg[rt].r <= r)
    {
        seg[rt].maxi += val;
        seg[rt].lazy += val;
        // debug(l, r, seg[rt].maxi);
        //操作
        return;
    }

    pushdown(rt);

    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (l < mid) modify(l, r, val, L(rt));
    if (r > mid) modify(l, r, val, R(rt));

    pushup(rt);
}

LL query(int l, int r, int rt = 1)
{
    if (rt == 1) r++;
    if (l <= seg[rt].l && seg[rt].r <= r) return seg[rt].maxi;

    pushdown(rt);

    int mid = (seg[rt].l + seg[rt].r) >> 1;
    LL maxi = -inf;
    if (l < mid) maxi = max(maxi, query(l, r, L(rt)));
    if (r > mid) maxi = max(maxi, query(l, r, R(rt)));

    return maxi;
}

vector<int> ileft[N];
vector<pair<int, int>> iright[N];

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            ileft[i].clear();
            iright[i].clear();
        }

        for (int i = 1; i <= m; i++)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            ileft[l].push_back(x);
            iright[r].push_back({l, x});
        }

        LL ans = 0;
        build(0, n);
        for (int i = 1; i <= n; i++)
        {
            // add
            for (auto x : ileft[i])
            {
                // debug(0, i - 1, x);
                modify(0, i - 1, x);
            }

            LL v = query(0, i - 1);

            ans = max(ans, v);
            modify(i, i, v);

            // debug(i, v);
            // del
            for (auto p : iright[i])
            {
                int l = p.first;
                int x = p.second;
                modify(0, l - 1, -x);
            }

            // LL d = query(0, 0);
            // debug(i, d);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
