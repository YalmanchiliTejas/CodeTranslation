#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
//by NeighThorn
using namespace std;
const int maxn=10000+5;
int n,hd[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],cnt,maxdis[maxn],secdis[maxn];
inline void add(int s,int x,int y){
    w[cnt]=s;to[cnt]=y;nxt[cnt]=hd[x];hd[x]=cnt++;
}
inline void dfs(int root,int fa){
    for(int i=hd[root];i!=-1;i=nxt[i])
        if(to[i]!=fa){
            dfs(to[i],root);
            if(maxdis[to[i]]+w[i]>maxdis[root])
                secdis[root]=maxdis[root],maxdis[root]=maxdis[to[i]]+w[i];
            else if(maxdis[to[i]]+w[i]>secdis[root])
                secdis[root]=maxdis[to[i]]+w[i];
        }
}
inline void change(int root,int fa){
    for(int i=hd[root];i!=-1;i=nxt[i])
        if(to[i]!=fa){
            if(maxdis[root]==maxdis[to[i]]+w[i]){
                if(maxdis[to[i]]<secdis[root]+w[i])
                    secdis[to[i]]=maxdis[to[i]],maxdis[to[i]]=secdis[root]+w[i];
                else if(secdis[to[i]]<secdis[root]+w[i])
                    secdis[to[i]]=secdis[root]+w[i];
            }
            else{
                if(maxdis[to[i]]<maxdis[root]+w[i])
                    secdis[to[i]]=maxdis[to[i]],maxdis[to[i]]=maxdis[root]+w[i];
                else if(secdis[root]<secdis[root]+w[i])
                    secdis[to[i]]=maxdis[root]+w[i];
            }
            change(to[i],root);
        }
}
signed main(void){
    scanf("%d",&n);cnt=0;memset(hd,-1,sizeof(hd));
    for(int i=1,s,x,y;i<n;i++)
        scanf("%d%d%d",&x,&y,&s),add(s,x,y),add(s,y,x);
    memset(maxdis,0,sizeof(maxdis));memset(secdis,0,sizeof(secdis));
    dfs(0,-1);change(0,-1);
    for(int i=0;i<n;i++)
        printf("%d\n",maxdis[i]);
    return 0;   
}
