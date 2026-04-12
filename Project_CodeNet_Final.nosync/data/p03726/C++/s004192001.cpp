#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int nxt, to;
} e[200010];
int head[100010], cnt;

void add_edge(int a, int b)
{
    e[++cnt] = { head[a], b };
    head[a] = cnt;
}

bool ok = 1;

bool dfs(int nod, int tata)
{
    int grad(0);
    for (int i(head[nod]); i; i = e[i].nxt)
        if (e[i].to != tata)
            grad += dfs(e[i].to, nod);
    if (grad <= 1)
        return 1 - grad;
    ok = 0;
    return 0;
}

int main()
{
    int n, a, b;
    cin >> n;

    while (--n) {
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }

    if (dfs(1, 0) || !ok)
        cout << "First";
    else
        cout << "Second";

    return 0;
}
