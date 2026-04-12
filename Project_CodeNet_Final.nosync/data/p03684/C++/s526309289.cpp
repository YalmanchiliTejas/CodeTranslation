#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
struct Node{
    int x,y,id;
}p[max_n];
struct edge{
    int u,v,w;
    bool operator <(edge e){
        return w<e.w;
    }
}edge[max_n];
int tot;
int par[max_n];
int findpar(int x){
    return x==par[x]?x:par[x]=findpar(par[x]);
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+n+1,[&](Node p1,Node p2){return p1.x<p2.x;});
    for(int i=1;i+1<=n;i++){
        edge[++tot]={p[i].id,p[i+1].id,p[i+1].x-p[i].x};
    }
    sort(p+1,p+n+1,[&](Node p1,Node p2){return p1.y<p2.y;});
    for(int i=1;i+1<=n;i++){
        edge[++tot]={p[i].id,p[i+1].id,p[i+1].y-p[i].y};
    }
    for(int i=1;i<=n;i++)par[i]=i;
    sort(edge+1,edge+tot+1);
    int ans=0;
    for(int i=1;i<=tot;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        u=findpar(u),v=findpar(v);
        if(u!=v){
            ans+=w;
            par[u]=v;
        }
    }
    printf("%d\n",ans);
    return 0;
}

