#include<stdio.h>
#include<vector>
using namespace std;
vector<int> graph[100];
int n_node,n_edge;
bool visited[100];
int ans;

void depth(int at,int node_visited)
{
    if(node_visited==n_node)
    {
        ans++;
        return;
    }
    for(vector<int>::iterator it=graph[at].begin();it!=graph[at].end();++it)
    {
        if(visited[*it]==false)
        {
            visited[*it]=true;
            depth(*it,node_visited+1);
            visited[*it]=false;
        }
    }
}

main()
{
    scanf("%d %d",&n_node,&n_edge);
    for(int i=1;i<=n_edge;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[1]=true;
    depth(1,1);
    printf("%d",ans);
}
