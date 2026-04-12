#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define INF 200000000000000
#define PB push_back
struct e{
  ll a,b,c;  
};
ll n,m,s,t,ans,r;
P sd[100005],td[100005];
vector<P>g[100005];
e eg[200005];
int main(void){
    cin>>n>>m>>s>>t;
    s--;
    t--;
    for(int i=0;i<m;i++){
        cin>>eg[i].a>>eg[i].b>>eg[i].c;
        g[--eg[i].a].PB(P(--eg[i].b,eg[i].c));
        g[eg[i].b].PB(P(eg[i].a,eg[i].c));
    }
    for(int i=0;i<n;i++){
        sd[i]=P(INF,0);
        td[i]=P(INF,0);
    }
    priority_queue<P,vector<P>,greater<P> >dik;
    dik.push(P(0,s));
    sd[s]=P(0,1);
    while(!dik.empty()){
        ll v=dik.top().S,c=dik.top().F;
        dik.pop();
        if(sd[v].F<c)continue;
        for(int i=0;i<g[v].size();i++){
            ll u=g[v][i].F,d=g[v][i].S;
            if(sd[u].F>c+d){
                sd[u]=P(c+d,sd[v].S);
                dik.push(P(c+d,u));
            }else if(sd[u].F==c+d){
                sd[u].S=(sd[u].S+sd[v].S)%M;
            }
        }
    }
    dik.push(P(0,t));
    td[t]=P(0,1);
    while(!dik.empty()){
        ll v=dik.top().S,c=dik.top().F;
        dik.pop();
        if(td[v].F<c)continue;
        for(int i=0;i<g[v].size();i++){
            ll u=g[v][i].F,d=g[v][i].S;
            if(td[u].F>c+d){
                td[u]=P(c+d,td[v].S);
                dik.push(P(c+d,u));
            }else if(td[u].F==c+d){
                td[u].S=(td[u].S+td[v].S)%M;
            }
        }
    }
    ans=sd[t].S*sd[t].S%M;
    r=sd[t].F;
    for(int i=0;i<n;i++){
        if(sd[i].F+td[i].F==r&&sd[i].F==td[i].F){
            ans=(ans+M-sd[i].S*td[i].S%M*sd[i].S%M*td[i].S)%M;
        }
    }
    for(int i=0;i<m;i++){
        ll a=eg[i].a,b=eg[i].b,c=eg[i].c;
        if(sd[a].F+td[b].F+c==r&&abs(sd[a].F-td[b].F)<c){
            ans=(ans+M-sd[a].S*td[b].S%M*sd[a].S%M*td[b].S%M)%M;
        }
        if(sd[b].F+td[a].F+c==r&&abs(sd[b].F-td[a].F)<c){
            ans=(ans+M-sd[b].S*td[a].S%M*sd[b].S%M*td[a].S%M)%M;
        }
    }
    cout<<ans<<endl;
}
