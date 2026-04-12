#include <bits/stdc++.h>

using namespace std;

struct pos
{
    int x, y;
};

pos arr[100010];
int par[100010];

int root(int x)
{
    return x == par[x] ? x : (par[x] = root(par[x]));
}

bool merge(int x, int y)
{
    x = root(x);
    y = root(y);
    if(x == y)
        return 0;
    par[x] = y;
    return 1;
}

struct edg
{
    int x, y, w;
    edg(int x, int y) : x(x), y(y)
    {
        w = min(abs(arr[x].x - arr[y].x), abs(arr[x].y - arr[y].y));
    }
    bool operator <(const edg &a) const
    {
        return w < a.w;
    }
};

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d", &arr[i].x, &arr[i].y);

    for(i = 0; i < n; i++)
        par[i] = i;

    vector<pair<int, int>> vx, vy;
    for(i = 0; i < n; i++)
        vx.push_back({ arr[i].x, i });
    for(i = 0; i < n; i++)
        vy.push_back({ arr[i].y, i });

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    vector<edg> v;
    for(i = 0; i < (int)vx.size() - 1; i++)
        v.push_back(edg(vx[i].second, vx[i + 1].second));
    for(i = 0; i < (int)vy.size() - 1; i++)
        v.push_back(edg(vy[i].second, vy[i + 1].second));

    sort(v.begin(), v.end());
    long long r = 0;
    for(auto e : v)
        if(merge(e.x, e.y))
            r += e.w;

    printf("%lld\n", r);
    return 0;
}