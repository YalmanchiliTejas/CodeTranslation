#include<bits/stdc++.h>
using namespace std;

#define maxn 111111
typedef pair<int, int> pii;
pii a[maxn];
int b[maxn], c[maxn];
int n;

bool cmp1(int x, int y)
{
    return a[x].first < a[y].first;
}

bool cmp2(int x, int y)
{
    return a[x].second < a[y].second;
}

struct edge
{
    int x, y, z;
    edge(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
    friend bool operator <(edge x, edge y)
    {
        return x.z < y.z;
    }
};
edge e[maxn * 2];
int m;

void add_edge(int x, int y, int z)
{
    e[++m] = edge(x, y, z);
}

int fa[maxn];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
    {
        return 0;
    }
    fa[x] = y;
    return 1;
}

long long solve()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    long long res = 0;
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        if (unite(e[i].x, e[i].y))
        {
            res += e[i].z;
        }
    }
    return res;
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = c[i] = i;
    }
    sort(b + 1, b + 1 + n, cmp1);
    sort(c + 1, c + 1 + n, cmp2);

    for (int i = 1; i < n; i++)
    {
        add_edge(b[i], b[i + 1], a[b[i + 1]].first - a[b[i]].first);
        add_edge(c[i], c[i + 1], a[c[i + 1]].second - a[c[i]].second);
    }

    cout << solve() << endl;
    return 0;
}
