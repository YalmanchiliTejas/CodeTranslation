#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000

using namespace std;

int main(){
  int n; cin >> n;
  vector<pair<int,int> > px,py;
  //adjacent list
  vector<pair<int,int> > G[n+1];
  for(int i=1;i<=n;i++){
    int x,y; cin >> x >> y;
    px.push_back(make_pair(x,i));
    py.push_back(make_pair(y,i));
  }
  sort(px.begin(),px.end());
  sort(py.begin(),py.end());
  for(int i=0;i<n-1;i++){
    G[px[i].second].push_back(make_pair(px[i+1].second,px[i+1].first-px[i].first));
    G[px[i+1].second].push_back(make_pair(px[i].second,px[i+1].first-px[i].first));
    G[py[i].second].push_back(make_pair(py[i+1].second,py[i+1].first-py[i].first));
    G[py[i+1].second].push_back(make_pair(py[i].second,py[i+1].first-py[i].first));
  }
  /*for(int i=1;i<=n;i++){
    for(int j=0;j<G[i].size();j++){
      cout << i << " " << G[i][j].first << " " << G[i][j].second << endl;
    }
  }*/
  //minimum spanning tree
  //PQ has make_pair(d[id],id)
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > PQ;
  int visited[n+1],d[n+1];
  for(int i=1;i<=n;i++){
    visited[i]=0;
    d[i]=INF;
  }
  d[1]=0;
  PQ.push(make_pair(0,1));
  int sum=0;
  while(PQ.empty()==false){
    int u=PQ.top().second;
    int u_cost=PQ.top().first;
    PQ.pop();
    if(u_cost>d[u]) continue;
    visited[u]=1;
    sum=sum+d[u];
    for(int i=0;i<G[u].size();i++){
      if(visited[G[u][i].first]==0){
        if(G[u][i].second<d[G[u][i].first]){
          d[G[u][i].first]=G[u][i].second;
          PQ.push(make_pair(d[G[u][i].first],G[u][i].first));
        }
      }
    }
  }
  cout << sum << endl;
}