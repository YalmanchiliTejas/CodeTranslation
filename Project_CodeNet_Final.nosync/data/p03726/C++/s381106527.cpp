#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

int N;
int f[100005];
vector <int> edg[100005];

void first() { printf("First\n"); exit(0); }
void second() { printf("Second\n"); exit(0); }

void DFS(int nod, int fth)
{
    for(auto nxt: edg[nod])
        if(nxt != fth)
            DFS(nxt, nod);

    if(f[nod])  return;

    if(!f[nod] && f[fth])   first();

    f[nod] = fth; f[fth] = nod;
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    f[0] = -1;
    DFS(1, 0);

    for(int i = 1; i <= N; i++)
        if(!f[i])   first();
    second();

    return 0;
}
