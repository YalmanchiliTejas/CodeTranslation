#include<bits/stdc++.h>
using namespace std;
int dfs(int **graph,int sv,bool *visited,int n)
{
    bool all_visited = true;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            all_visited = false;
            break;
        }
    }
    if(all_visited)
        return 1;
    int total = 0;
    for(int i = 1; i <= n; i++)
    {
        if(graph[sv][i] && !visited[i])
        {
            visited[i] = true;
            total = total + dfs(graph,i,visited,n);
            visited[i] = false;
        }
    }
    return total;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int **graph = new int*[n + 1];
    for(i = 0; i <= n; i++)
    {
        graph[i] = new int[n + 1];
        for(j = 0; j <= n; j++)
            graph[i][j] = 0;
    }
    for(i = 1; i <= m; i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    bool visited[n + 1] = {};
    visited[1] = true;
    cout<<dfs(graph,1,visited,n)<<endl;
    return 0;
}