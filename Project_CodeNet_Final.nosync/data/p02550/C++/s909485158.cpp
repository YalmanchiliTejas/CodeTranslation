#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i<(b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)
#define FILL(a, b) memset(a, b, sizeof(a))

void dout() { cerr << endl; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    int x, m;
    cin >> n >> x >> m;
    VI to(m, -1);
    FOR(i, 0, m)
    {
        to[i] = (LL)i * i % m;
    }
    VI vis(m);
    vis[x] = true;
    VI path = {x};
    while (!vis[to[x]])
    {
        x = to[x];
        path.PB(x);
        vis[x] = true;
    }
    int beg = 0;
    while (path[beg] != to[x])
        beg++;
    LL csum = 0;
    VL cycle;
    FOR(i, beg, SZ(path))
    {
        cycle.PB(path[i]);
        csum += path[i];
    }
    LL ans = 0;
    int where = 0;
    while (n > 0 && where != beg)
    {
        ans += path[where];
        n--;
        where++;
    }
    if (n > 0)
    {
        LL full = n / SZ(cycle);
        ans += full * csum;
        cycle.back() = 0;
        int rem = n % (SZ(cycle));
        FOR(i, 0, rem)
            ans += cycle[i];
    }
    cout << ans;
    return 0;
}