#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct edge{
    int t,next;
}e[N*2];int ecnt,head[N];
void addedge(int f,int t){
    e[++ecnt]=(edge){t,head[f]};head[f]=ecnt;
    e[++ecnt]=(edge){f,head[t]};head[t]=ecnt;
}

int DFS(int u,int fr){
    int tot=0;
    for(int i=head[u];i;i=e[i].next){
        if(e[i].t!=fr) tot+=DFS(e[i].t,u);
    }
    if(fr==0&&tot==0) return 1;
    else if(fr==0&&tot==1) return 0;
    if(tot>=2) return 2;
    return tot^1;
}

int n;
int main(){
    scanf("%d",&n);
    for(int i=1,f,t;i<n;i++) scanf("%d%d",&f,&t),addedge(f,t);
    if(DFS(1,0)) puts("First");
    else puts("Second");
    return 0;
}