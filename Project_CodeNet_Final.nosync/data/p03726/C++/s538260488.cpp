#include <bits/stdc++.h>
#define maxN 100002
using namespace std;

//FILE *fin = freopen("d.in", "r", stdin);

/* ---------------------- */
int n;
vector < int > V[maxN];
/* ---------------------- */
bool vis[maxN];

bool dfs(int nod)
{
    int nr = 0, ans = 0;
    vis[nod] = 1;
    for (int son : V[nod])
        if (!vis[son])
        {
            ++ nr;
            ans += dfs(son);
        }
    if (nr == 0)
        return 0;
    if (nr != 1 && ans < nr - 1)
    {
        printf("First\n");
        exit(0);
    }
    return (ans == nr - 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
    }
    if ((n & 1) || !dfs(1))
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}
