#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1<<30
typedef long long ll;
typedef pair<int, int> pi;

vector<pi>G[100005];
bool used[100005];

vector<pi>X;
vector<pi>Y;
int N;

int prim(){
  for(int i=0;i<N;i++){
    used[i] = false;
  }

  ll res = 0;

  priority_queue<pi, vector<pi>, greater<pi> >Q;
  Q.push(pi(0, 0));

  while(!Q.empty()){
    pi q = Q.top(); Q.pop();
    int p = q.second;
    int cost = q.first;
    if(used[p]) continue;

    res += cost;
    used[p] = true;

    for(int i=0;i<G[p].size();i++){
      pi next = G[p][i];
      Q.push(pi(next.second, next.first));
    }
  }

  return res;
}

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    int x, y; cin >> x >> y;
    X.push_back(pi(x, i));
    Y.push_back(pi(y, i));
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  for(int i=0;i<N-1;i++){
    G[X[i].second].push_back(pi(X[i+1].second, X[i+1].first-X[i].first));
    G[Y[i].second].push_back(pi(Y[i+1].second, Y[i+1].first-Y[i].first));
    G[X[i+1].second].push_back(pi(X[i].second, X[i+1].first-X[i].first));
    G[Y[i+1].second].push_back(pi(Y[i].second, Y[i+1].first-Y[i].first));        
  }

  cout << prim() << endl;
  return 0;
}
