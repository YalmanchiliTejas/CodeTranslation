#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
    int to,next;
}e[200010];
int n,head[100010];
int dfs(int u,int fa){
    int flag=0;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].to;
        if(v==fa)
            continue;
        flag+=dfs(v,u);
    }
    if(flag>=2){
        puts("First");
        exit(0);
    }
    return flag^1;
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1,cnt=-1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[++cnt]=(edge){v,head[u]};
        head[u]=cnt;
        e[++cnt]=(edge){u,head[v]};
        head[v]=cnt;
    }
    if(dfs(1,0))
        puts("First");
    else
        puts("Second");
    return 0;
}