#include<bits/stdc++.h>
using namespace std;

void pro(int x);

int N;
int D[100010] = {0};
bool visit[100010] = {0};
vector<int> G[100010];
bool O = false;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N - 1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        D[a]++;
        D[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i < N + 1; i++)
    {
        if(D[i] == 1)
        {
            pro(i);
        }
    }
    if(!O)
    {
        printf("Second\n");
    }
    return 0;
}

void pro(int x)
{
    visit[x] = true;
    D[x] = 0;
    for(int i = 0; i < G[x].size() + 1; i++)
    {
        if(i == G[x].size())
        {
            if(!O)
            {
                O = true;
                printf("First\n");
            }
            return;
        }
        if(visit[G[x][i]] == false)
        {
            D[G[x][i]] = 0;
            visit[G[x][i]] = true;
            for(int j = 0; j < G[G[x][i]].size(); j++)
            {
                if(D[G[G[x][i]][j]] == 1)
                {
                    if(!O)
                    {
                        O = true;
                        printf("First\n");
                    }
                    return;
                }
                D[G[G[x][i]][j]]--;
                if(D[G[G[x][i]][j]] == 1 && visit[G[G[x][i]][j]] == false)
                {
                    pro(G[G[x][i]][j]);
                }
            }
            return;
        }
    }
    return;
}
