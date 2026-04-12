#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<pair<ll,int>> v[101010];
int n;

bool chmin(pair<ll,ll>& p,pair<ll,ll> q){
    if(q.first<p.first){
        p=q;
        return true;
    }
    else if(p.first==q.first)(p.second+=q.second)%=mod;
    return false;
}

vector<pair<ll,ll>> solve(int s){
    vector<pair<ll,ll>> dist(n,{longinf,0});
    dist[s]={0,1};
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.emplace(0,s);
    while(q.size()){
        auto p=q.top();q.pop();
        ll cur=p.second, d=p.first;
        if(dist[cur].first<d)continue;
        for(auto e : v[cur]){
            dist[cur].first+=e.first;
            if(chmin(dist[e.second], dist[cur]))q.emplace(dist[e.second].first,e.second);
            dist[cur].first-=e.first;
        }
    }
    return dist;
}

int main(){
    int m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    --s;--t;
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        v[x].emplace_back(z,y);
        v[y].emplace_back(z,x);
    }
    auto ds=solve(s);
    auto dt=solve(t);
    ll d=ds[t].first;
    ll ans=0;
    rep(i,n){
        if(ds[i].first==dt[i].first&&2*ds[i].first==d){
            ll ret=ds[i].second*dt[i].second%mod;
            ans+=ret*ret%mod;
            ans%=mod;
        }
    }
    rep(i,n){
        for(auto to : v[i]){
            int j=to.second;
            if(ds[i].first+dt[j].first+to.first==d){
                if(2*ds[i].first<d&&2*dt[j].first<d){
                    ll ret=ds[i].second*dt[j].second%mod;
                    ans+=ret*ret%mod;
                    ans%=mod;
                }
            }
        }
    }
    cout<<(ds[t].second*ds[t].second-ans%mod+mod)%mod<<endl;
    return 0;
}