#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
struct edge{
  ll c,s,t;
  bool operator <(const edge&q)const{
      return c<q.c;
  }
  bool operator >(const edge&q)const{
      return c>q.c;
  }
};
ll n,par[100005],ans;
vector<P>g[100005],ex,ey;
void ini(){
    for(int i=0;i<n;i++)par[i]=i;
}
int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unit(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)par[x]=y;
}
int main(void){
    scanf("%lld",&n);
    ini();
    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        ex.PB(P(x,i));
        ey.PB(P(y,i));
    }
    sort(ex.begin(),ex.end());
    sort(ey.begin(),ey.end());
    priority_queue<edge,vector<edge>,greater<edge> >kul;
    for(int i=0;i<ex.size()-1;i++){
        kul.push(edge{ex[i+1].F-ex[i].F,ex[i].S,ex[i+1].S});
    }
    for(int i=0;i<ey.size()-1;i++){
        kul.push(edge{ey[i+1].F-ey[i].F,ey[i].S,ey[i+1].S});
    }
    while(!kul.empty()){
        ll c=kul.top().c,s=kul.top().s,t=kul.top().t;
        kul.pop();
        if(same(s,t))continue;
        ans+=c;
        unit(s,t);
    }
    printf("%lld\n",ans);
}
