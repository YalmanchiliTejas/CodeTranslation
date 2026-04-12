#include<bits/stdc++.h>
using namespace std;

int N;
int M;
bool edge[10][10] = {0};
int ans = 0;
bool mem[10] = {0};

int DFS(int v,int n)
{
    if(n == N - 1)return 1;
    mem[v] = true;
    int res = 0;
    for(int i = 0; i < N; i++)if(edge[v][i + 1] && !mem[i + 1])res += DFS(i + 1,n + 1);
    mem[v] = false;
    return res;
}

int main()
{
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a][b] = edge[b][a] = true;
    }
    printf("%d\n",DFS(1,0));
    return 0;
}
