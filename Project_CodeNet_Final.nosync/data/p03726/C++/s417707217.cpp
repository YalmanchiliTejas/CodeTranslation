#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int tot=0,h[100005];
int n,x,y,siz[100005],f[100005];
struct Edge{
    int x,next;
}e[200005];

inline void add_edge(int x,int y){
    e[++tot].x=y;
    e[tot].next=h[x],h[x]=tot;
}

bool dfs(int x,int fa){
    siz[x]=1;
    int cnt=0;
    for(int i=h[x];i;i=e[i].next){
        if(e[i].x==fa)continue;
        if(dfs(e[i].x,x))return true;
        if(siz[e[i].x]){
            cnt++,siz[x]=0;
            if(cnt==2)return true;
        }
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    printf(dfs(1,0)||siz[1]?"First":"Second");
}