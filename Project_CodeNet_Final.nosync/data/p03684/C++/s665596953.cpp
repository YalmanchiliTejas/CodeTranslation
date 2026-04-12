#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define MAXN (600000+10)
#define MAXM (600000+10)
int par[MAXN];
struct Edge
{
    int u ,v, w;
} edge[MAXM];
int tol = 0;
void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].w = w;
    tol ++;
}
bool cmp(Edge a, Edge b)
{
    return a.w  < b.w;
}
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
int kruskal(int n)
{
    memset(par, -1, sizeof(par));
    sort(edge ,edge + tol, cmp);
    int cnt = 0, ans = 0;
    for(int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2)
        {
            ans += w;
            par[t1] = t2;
            cnt ++;
        }
        if(cnt == n - 1)
            break;
    }
    if(cnt < n - 1) return -1;
    return ans;
}
int n;

struct City {
    ll x, y, id;
} city[100002];

bool cmp1(City a, City b) {
    return a.x < b.x;
}
bool cmp2(City a, City b) {
    return a.y < b.y;
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld", &city[i].x, &city[i].y);
        city[i].id = i;
    }

    sort(city+1, city+1+n, cmp1);
    for(int i=2;i<=n;i++) {
        addEdge(city[i-1].id, city[i].id, city[i].x - city[i-1].x);
        addEdge(city[i].id, city[i-1].id, city[i].x - city[i-1].x);
    }

    sort(city+1, city+1+n, cmp2);
    for(int i=2;i<=n;i++) {
        addEdge(city[i-1].id, city[i].id, city[i].y - city[i-1].y);
        addEdge(city[i].id, city[i-1].id, city[i].y - city[i-1].y);
    }
    cout << kruskal(n) <<endl;
}


