#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define int long long
const int N = 1e5+5;
int n, ans = 0, par[N];

struct point
{
    int x,y,id;
};

struct edge
{
    int u,v,w;
};

bool cmp_x(point a, point b)
{
    return a.x < b.x;
}

bool cmp_y(point a, point b)
{
    return a.y < b.y;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int dist(point a, point b)
{
    return min(abs(a.x-b.x),abs(a.y-b.y));
}

void init()
{
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int findSet(int i)
{
    if (i == par[i])
        return i;
    return (par[i] = findSet(par[i]));
}

bool isSameSet(int i, int j)
{
    return (findSet(i) == findSet(j));
}

void unionSet(int i, int j)
{
    if (!isSameSet(i,j))
    {
        par[findSet(i)] = findSet(j);
    }
}

point tmp_x[N], tmp_y[N];
vector<edge> ve;

signed main()
{
    int x,y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        tmp_x[i] = tmp_y[i] = {x,y};
        tmp_x[i].id = i;
        tmp_y[i].id = i;
    }
    sort(tmp_x,tmp_x+n,cmp_x);
    sort(tmp_y,tmp_y+n,cmp_y);
    for (int i = 0; i < n-1; i++)
    {
        ve.push_back({tmp_x[i].id, tmp_x[i+1].id, dist(tmp_x[i],tmp_x[i+1])});
        ve.push_back({tmp_y[i].id, tmp_y[i+1].id, dist(tmp_y[i],tmp_y[i+1])});
    }
    sort(ve.begin(),ve.end(),cmp);
    init();
    for (auto e: ve)
    {
        int u = e.u, v = e.v, w = e.w;
        if (!isSameSet(u,v))
        {
            unionSet(u,v);
            ans += w;
        }
    }
    cout << ans;
}
