#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf (1e9 + 7)
using namespace std;

int n, nn = 0, egn = 0, pre[100005];
map<pair<long, long>, int> mps;

struct node
{
    long long x, y;
    int id;
}nd[100005];

struct edge
{
    long long w;
    int u, v;
}eg[300005];

bool cmp(const struct node & a, const struct node & b)
{
    return a.x < b.x;
}

bool cmp2(const struct node & a, const struct node & b)
{
    return a.y < b.y;
}

bool cmp3(const struct edge & a, const struct edge & b)
{
    return a.w < b.w;
}

int pr(int a)
{
    if(a == pre[a])
        return a;
    pre[a] = pr(pre[a]);
    return pre[a];
}

void con(int u, int v)
{
    if(u < v)
        pre[u] = v;
    else
        pre[v] = u;
}

int main()
{
    long long a, b;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld%lld", &a, &b);
        if(!mps[{a, b}])
        {
            mps[{a, b}] = 1;
            nn++;
            pre[nn] = nn;
            nd[nn].x = a;
            nd[nn].y = b;
            nd[nn].id = nn;
        }
    }
    sort(nd + 1, nd + 1 + nn, cmp);
    for(int i = 1;i < nn;i++)
    {
        egn++;
        eg[egn].w = nd[i + 1].x - nd[i].x;
        eg[egn].u = nd[i].id;
        eg[egn].v = nd[i + 1].id;
    }
    sort(nd + 1, nd + 1 + nn, cmp2);
    for(int i = 1;i < nn;i++)
    {
        egn++;
        eg[egn].w = nd[i + 1].y - nd[i].y;
        eg[egn].u = nd[i].id;
        eg[egn].v = nd[i + 1].id;
    }
    sort(eg + 1, eg + 1 + egn, cmp3);
    long long ans = 0;
    int tmp = 0;
    for(int i = 1;i <= egn;i++)
    {
        if(tmp >= nn - 1)
            break;
        int u = pr(eg[i].u);
        int v = pr(eg[i].v);
        long long w = eg[i].w;
        if(u != v)
        {
            con(u, v);
            ans += w;
            con(u, v);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
