#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int prim(int v, vector< vector< pair<int,int> > > G){
  //v: 頂点数, G: 隣接リスト
  int INF = 1000000000;
  priority_queue< pair<int, int> > wait;
  int result = 0;
  vector<bool> connected(v,false);
  vector<int> cost(v,INF);
  wait.push(make_pair(0, 0));
  while(!wait.empty()){
    int nowpoint = wait.top().second;
    int nowcost = -wait.top().first;
    wait.pop();
    if(!connected[nowpoint]){
      result += nowcost;
      connected[nowpoint] = true;
      for(int i = 0; i < G[nowpoint].size(); ++i){
	int nextpoint = G[nowpoint][i].second;
	int nextcost = G[nowpoint][i].first;
	if(nextcost < cost[nextpoint]){
	  wait.push(make_pair(-nextcost, nextpoint));
	  cost[nextpoint] = nextcost;
	}
      }
    }
  }
  return result;
}

int main(){
  int N;
  cin >> N;
  int x, y;
  vector< pair<int,int> > X, Y;
  for(int i = 0; i < N; ++i){
    cin >> x >> y;
    X.push_back(make_pair(x,i));
    Y.push_back(make_pair(y,i));
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  
  vector< vector< pair<int,int> > > G(N);
  for(int i = 1; i < N; ++i){
    int x1 = X[i-1].first, x2 = X[i].first, s = X[i-1].second, t = X[i].second;
    G[s].push_back(make_pair(abs(x1-x2),t));
    G[t].push_back(make_pair(abs(x1-x2),s));
    int y1 = Y[i-1].first, y2 = Y[i].first;
    s = Y[i-1].second, t = Y[i].second;
    G[s].push_back(make_pair(abs(y1-y2),t));
    G[t].push_back(make_pair(abs(y1-y2),s));
  }
  cout << prim(N,G) << endl;
  return 0;
}
