#include<iostream>
#include<cstdio>


using namespace std;
int used[10 + 7];
int    s[10 + 7][10 + 7];

int ans = 0;
int n, m;
void DFS(int depth,int now)
{
    for(int i = 1;i <= n;++i)
    {
        if(s[now][i] && !used[i])
        {
            used[i] = 1;
            DFS(depth + 1, i);
            used[i] = 0;
        }
    }

    if(depth == n)
        ans++;
}
int main()
{   

    scanf("%d%d",&n,&m);

    for(int i = 1;i <= m;++i)
    {
        int fr,to;
        scanf("%d%d",&fr,&to);
        s[fr][to] = s[to][fr] = 1;
    }
    used[1] = 1;
    DFS(1,1);
    printf("%d\n",ans);
    return 0;
}