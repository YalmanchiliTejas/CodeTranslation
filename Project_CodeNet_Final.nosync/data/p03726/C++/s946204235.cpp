#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e6+5;
struct node{
    int u,v,nxt;
}edge[N];
int head[N],mcnt;
void add_edge(int u,int v){
    mcnt++;
    edge[mcnt].u=u;
    edge[mcnt].v=v;
    edge[mcnt].nxt=head[u];
    head[u]=mcnt;
}
int n;
int sz[N];
bool dfs(int u,int fa){
    sz[u]=1;
    int cnt=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==fa)
            continue;
        if(dfs(v,u))
            return true;
        if(sz[v]){
            cnt++;
            sz[u]=0;
            if(cnt==2)
                return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    puts(dfs(1,0)||sz[1]?"First":"Second");
}
