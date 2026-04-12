#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;
struct edge{int to,cost;};
using P=pair<int,int>;
const int INF=1<<29;
const int MAX_V=10010;
vector<edge> G[MAX_V];
int d1[MAX_V];
int d2[MAX_V];
int V,E;
void dijkstra(int s,int *d){
  priority_queue<P,vector<P>,greater<P>> que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    REP(i,G[v].size()){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
	d[e.to]=d[v]+e.cost;
	que.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(){_;
  int n,f,t,c;cin>>n;
  REP(i,n-1){
    cin>>f>>t>>c;
    G[f].push_back(edge{t,c});
    G[t].push_back(edge{f,c});
  }
  V=n;
  E=(n-1)*2;
  dijkstra(0,d1);
  dijkstra(distance(d1,max_element(d1,d1+n)),d2);
  dijkstra(distance(d2,max_element(d2,d2+n)),d1);
  REP(i,n){
    cout<<max(d1[i],d2[i])<<endl;
  }
}