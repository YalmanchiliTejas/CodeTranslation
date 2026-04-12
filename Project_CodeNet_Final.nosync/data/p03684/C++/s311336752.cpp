#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l4;
set<l4> xset, yset;
const int maxn = 1e5+1;
ll x[maxn], y[maxn], n;

struct Edge
{
    int u, v;
    ll len;
    bool operator<(const Edge &r) const
    {
        return len < r.len;
    }
};

int pa[maxn], cnt[maxn];
int init()
{
    for (int i = 1; i <= n; ++i)
    {
        pa[i] = i;
        cnt[i] = 1;
    }
}
int findpa(int id)
{
    return id==pa[id]?id:pa[id]=findpa(pa[id]);
}
bool merge(int x, int y)
{
    x = findpa(x);
    y = findpa(y);
    if (x != y)
    {
        if (cnt[x] > cnt[y])
            swap(x, y);
        pa[x] = y;
        cnt[y] += cnt[x];
        return true;
    }
    return false;
}
vector<Edge> e;

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld %lld", x+i, y+i);
        xset.insert(l4(x[i], i));
        yset.insert(l4(y[i], i));
    }
    for (int i = 1; i <= n; ++i)
    {
        set<l4>::iterator it = xset.find(l4(x[i], i));
        if (it != xset.begin())
        {
            --it;
            e.push_back((Edge){i, it->second, abs(x[i]-it->first)});
            ++it;
        }
        ++it;
        if (it != xset.end())
        {
            e.push_back((Edge){i, it->second, abs(x[i]-it->first)});
        }        
    }
    for (int i = 1; i <= n; ++i)
    {
        set<l4>::iterator it = yset.find(l4(y[i], i));
        if (it != yset.begin())
        {
            --it;
            e.push_back((Edge){i, it->second, abs(y[i]-it->first)});
            ++it;
        }
        ++it;
        if (it != yset.end())
        {
            e.push_back((Edge){i, it->second, abs(y[i]-it->first)});
        }        
    }
    sort(e.begin(), e.end());
    init();
    ll cost = 0;
    for (int i = 0; i < e.size(); ++i)
    {
        if (merge(e[i].u, e[i].v))
        {
            cost += e[i].len;
        }
    }
    printf("%lld\n", cost);
}