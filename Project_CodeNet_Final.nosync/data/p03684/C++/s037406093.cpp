#include<bits/stdc++.h>
#define ll long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define se second
#define fi first
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
const ll N=1e5+5;
ll n;
vector<plll> ed;
ll par[N];

ll root(ll x){
    while(par[x]!=x){
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}

void merge(ll x,ll y){
    ll p = root(x);
    ll q = root(y);
    par[p] = par[q];
}

ll kruskal(){
    ll u,v,cost=0,mincost=0;
    for(int i=0;i<N;i++) par[i]=i;
    for(int i=0;i<ed.size();i++){
        u=ed[i].se.fi;
        v=ed[i].se.se;
        cost=ed[i].fi;
        if(root(u)!=root(v)){
            mincost+=cost;
            merge(u,v);
        }
    }
    return mincost;
}

struct point{
    ll x,y,id;
};
point px[N],py[N];

bool compx(point a,point b){
    return (a.x < b.x);
}

bool compy(point a,point b){
    return (a.y < b.y);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>px[i].x>>px[i].y;
        px[i].id=i;
        py[i]=px[i];
    }
    sort(px+1,px+n+1,compx);
    sort(py+1,py+n+1,compy);
    for(int i=1;i<n;i++){
        int u=px[i].id;
        int v=px[i+1].id;
        ll cost=px[i+1].x-px[i].x;
        ed.pb(plll(cost,pll(u,v)));
    }
    for(int i=1;i<n;i++){
        int u=py[i].id;
        int v=py[i+1].id;
        ll cost=py[i+1].y-py[i].y;
        ed.pb(plll(cost,pll(u,v)));
    }
    sort(ed.begin(),ed.end());
    cout<<kruskal();
	return 0;
}