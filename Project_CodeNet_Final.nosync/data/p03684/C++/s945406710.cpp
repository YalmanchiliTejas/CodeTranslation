#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

#define fi first
#define se second
typedef long long LL;
typedef long double LD;


struct edge{
    LL x,y,c;
    edge(){}
    edge(LL x, LL y, LL c) : x(x), y(y), c(c) {}
};

int N,t[100010],sz[100010],x[100010],y[100010],ind[100010];
edge a[300010]; int K;
LL res=0;

int getf(int x){
    return (t[x]==x ? x : t[x]=getf(t[x]));
}

void add_edge(int x, int y, LL c){
    x=getf(x),y=getf(y);
    if (x==y) return;
    if (sz[x]>sz[y]) swap(x,y);

    t[x]=y,sz[y]+=sz[x];
    res+=c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    int i;
    for (i=1; i<=N; i++){
        cin >> x[i] >> y[i];
        ind[i]=t[i]=i;
        sz[i]=1;
    }

    sort(ind+1,ind+N+1,[](int a, int b){ return x[a]<x[b]; });
    for (i=1; i<N; i++)
        a[++K]=edge(ind[i],ind[i+1],min(abs(x[ind[i]]-x[ind[i+1]]),abs(y[ind[i]]-y[ind[i+1]])));

    sort(ind+1,ind+N+1,[](int a, int b){ return y[a]<y[b]; });
    for (i=1; i<N; i++)
        a[++K]=edge(ind[i],ind[i+1],min(abs(x[ind[i]]-x[ind[i+1]]),abs(y[ind[i]]-y[ind[i+1]])));

    sort(a+1,a+K+1,[](edge A, edge B){ return A.c<B.c; });
    for (i=1; i<=K; i++)
        add_edge(a[i].x,a[i].y,a[i].c);

    cout << res << "\n";
    return 0;
}
