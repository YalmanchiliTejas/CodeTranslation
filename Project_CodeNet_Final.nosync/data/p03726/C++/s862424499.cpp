#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,x,y,ans,tot,sg[N],head[N];
struct edge{int v,nxt;}e[N];


void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u,int fa){
    sg[u]=1; int cnt=0;
    for (int i=head[u],v;i;i=e[i].nxt)
        if ((v=e[i].v)!=fa){
            dfs(v,u); if (sg[v]) cnt++; sg[u]^=sg[v];
        }
    if (cnt>=2){puts("First"); exit(0);}
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(1,0);
    if (sg[1]) puts("First"); else puts("Second");

    return 0;
}
