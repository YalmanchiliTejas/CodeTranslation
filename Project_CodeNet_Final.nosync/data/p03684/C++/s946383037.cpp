#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
const int N=1e5+5;
struct Edge {
    int u,v,w;
    bool operator < (const Edge &b) const {
        return w<b.w;
    }
};
std::vector<Edge> g;
int par[N],n,x[N],y[N],t[N];
int fd(int x) {
    return par[x]==x?x:par[x]=fd(par[x]);
}
void init() {
    for(int i=1;i<=n;i++) par[i]=t[i]=i;
}
bool cmpx(int a,int b) {
    return x[a]<x[b];
}
bool cmpy(int a,int b) {
    return y[a]<y[b];
}
int main() {
    scanf("%d",&n);init();
    for(int i=1;i<=n;i++) scanf("%d%d",x+i,y+i);
    std::sort(t+1,t+1+n,cmpx);
    for(int i=2;i<=n;i++) g.push_back((Edge){t[i],t[i-1],x[t[i]]-x[t[i-1]]});
    init();std::sort(t+1,t+1+n,cmpy);
    for(int i=2;i<=n;i++) g.push_back((Edge){t[i],t[i-1],y[t[i]]-y[t[i-1]]});
    std::sort(g.begin(),g.end());
    long long ans=0;
    for(auto &v:g) {
        int l=fd(v.u),r=fd(v.v);
        if(l==r) continue;
        ans+=v.w;par[l]=r;
    }
    printf("%lld\n",ans);
    return 0;
}
