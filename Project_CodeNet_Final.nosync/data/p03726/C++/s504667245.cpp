#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int n;
int head[MAXN],ecnt;
struct node{
    int v,nxt;
}E[MAXN*2];

void addedge(int u,int v){
    E[++ecnt]=(node){v,head[u]};
    head[u]=ecnt;
}

bool dfs(int u,int fa=0){
    int cnt=0;
    for(int i=head[u];i;i=E[i].nxt){
        int v=E[i].v;
        if(v==fa) continue;
        cnt+=dfs(v,u);
    }
    if(cnt>=2){
        puts("First");
        exit(0);
    }
    return cnt^1;
}

int main(){

    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    if(dfs(1)) puts("First");
    else puts("Second");

    fclose(stdin);
    fclose(stdout);
}
