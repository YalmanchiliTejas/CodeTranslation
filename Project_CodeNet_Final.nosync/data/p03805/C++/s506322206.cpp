#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 10, M = N * N;

int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int n, m, res;

void dfs(int u, int state)
{
    if(state == (1 << n) - 1)
    {
        res ++;
        return;
    }
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!(state >> j & 1))
            dfs(j, state | (1 << j));
    }
}

int main()
{
    memset(h, -1, sizeof h);
    
    scanf("%d%d", &n, &m);
    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a --, b --;
        add(a, b);
        add(b, a);
    }
    
    dfs(0, 1);
    
    printf("%d", res);
    return 0;
}