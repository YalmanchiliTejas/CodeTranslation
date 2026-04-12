#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

int n,m;
const int mod = 1000000007;
int cal(int x,int y)
{
    int ret = 1;
    for (int i = 0; i < y; i++)
        ret = ret * x % mod;
    return ret;
}
int fa[100010];
int find(int u)
{
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (n == 0 && m == 0) return 0;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 0; i < m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            if (find(u) == find(v)) continue;
            fa[fa[u]] = fa[v];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        if (find(i) == i)
            cnt++;
        int ans = 0;
        if (cnt == n) {
            ans = cal(2,n);
        }
        else
            ans = (cal(2,cnt) + 1) % mod;
        printf("%d\n",ans);
    }
}