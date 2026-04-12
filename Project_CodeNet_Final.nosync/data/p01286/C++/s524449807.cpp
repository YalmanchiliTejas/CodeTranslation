#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<typeinfo>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;



class Flow{
private:
    struct edge{
        ll to;
        ll cap;
        ll rev;
    };
    
    ll INF;
    ll v;
    vector<vector<edge>> e;
    vector<bool> used;
    
    void reset_used(){
        for(int i=0;i<used.size();i++){used[i]=false;}
    }
    
    ll dfs(ll where,ll to,ll flow){
        if(where==to){return flow;}
        used[where]=true;
        for(int i=0;i<e[where].size();i++){
            edge &E=e[where][i];
            if(!used[E.to] && E.cap>0){
                ll d=dfs(E.to,to,min(flow,E.cap));
                if(d>0){
                    E.cap-=d;
                    e[E.to][E.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }
    
public:
    Flow(ll v):v(v){
        e.resize(v);
        used.resize(v,false);
        INF=1e18+7;
    }
    
    void add_edge(ll from,ll to,ll cap){
        e[from].push_back((edge){to,cap,(ll)e[to].size()});
        e[to].push_back((edge){from,0,(ll)e[from].size()-1});
    }
    
    ll max_flow(ll s,ll t){
        vector<vector<edge>> ed=e;
        ll flow=0;
        while(1){
            reset_used();
            ll f=dfs(s,t,INF);
            if(f==0){break;}
            flow+=f;
        }
        e=ed;
        return flow;
    }
};



    
int main(){
    const ll INF=1e18;
    ll h,w,c,m,nw,nc,nm;
    while(cin>>h>>w>>c>>m>>nw>>nc>>nm && h!=-1){
        Flow F((h+w+c+m+20)*2);
        ll s=(h+w+c+m+20)*2; s--;
        ll g=s-1;
        ll NW=g-1;
        ll INW=NW-1;
        ll NC=INW-1;
        ll INC=NC-1;
        ll NM=INC-1;
        ll INM=NM-1;
        F.add_edge(INW,NW,nw);
        //F.add_edge(NW,INC,INF);
        F.add_edge(INC,NC,nc);
        //F.add_edge(NC,INM,INF);
        F.add_edge(INM,NM,nm);
        F.add_edge(NM,g,INF);
        for(int i=0;i<h;i++){
            F.add_edge(s,i,1);
            F.add_edge(i,INW,1);
        }
        for(int i=0;i<w;i++){
            F.add_edge(h+i,h+w+i,1);
            F.add_edge(h+w+i,INC,1);
            ll n;
            cin>>n;
            for(int t=0;t<n;t++){
                ll H;
                cin>>H;
                F.add_edge(H-1,h+i,1);
            }
        }
        for(int i=0;i<c;i++){
            F.add_edge(h+2*w+i,h+2*w+c+i,1);
            F.add_edge(h+2*w+c+i,INM,1);
            F.add_edge(NW,h+2*w+i,1);
            ll n;
            cin>>n;
            for(int t=0;t<n;t++){
                ll H;
                cin>>H;
                F.add_edge(h+w+H-1,h+2*w+i,1);
            }
        }
        for(int i=0;i<m;i++){
            F.add_edge(h+2*w+2*c+i,h+2*w+2*c+m+i,1);
            F.add_edge(h+2*w+2*c+m+i,g,1);
            F.add_edge(NC,h+2*w+2*c+i,1);
            ll n;
            cin>>n;
            for(int t=0;t<n;t++){
                ll H;
                cin>>H;
                F.add_edge(h+2*w+c+H-1,h+2*w+2*c+i,1);
            }
        }
        cout<<F.max_flow(s,g)<<endl;
    }
    
    
    return 0;
}

