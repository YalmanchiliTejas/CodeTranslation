#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii=pair<int,int>;

int pa[100001],n;
vector<pii> xp,yp;

struct edge{
    int u,v,w;
    edge() {}
    edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const edge &rhs)const {
        return w<rhs.w;
    }
};
vector<edge> ev;

void add(vector<pii> &arr) {
    for(int i=0;i<sz(arr)-1;i++) ev.push_back(edge(arr[i].se,arr[i+1].se,arr[i+1].fi-arr[i].fi));
}
int find(int cur) {return cur==pa[cur] ? cur : pa[cur]=find(pa[cur]);}
bool merge(int u,int v) {
    u=find(u); v=find(v);
    if(u==v) return false;

    pa[v]=u;
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        xp.push_back(pii(x,i));
        yp.push_back(pii(y,i));
    }
    sort(xp.begin(),xp.end());
    sort(yp.begin(),yp.end());

    add(xp);
    add(yp);

    sort(ev.begin(),ev.end());
    
    long long ans=0;
    for(int i=0;i<n;i++) pa[i] =i;
    for(auto &e:ev) {
        if(merge(e.u,e.v)) {
            ans += e.w;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
