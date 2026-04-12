#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Path{
  set<int> edges;
  int now;
  Path(){}
};
bool state[9][9];
int main(void){
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    state[a][b] = state[b][a] = true;
  }
  queue<Path>que;
  Path p = Path();
  p.now = 1;
  p.edges.insert(1);
  que.push(p);
  int ans = 0;
  while(!que.empty()){
    Path np = que.front();que.pop();
    if(np.edges.size() == N){
      ans++;
      continue;
    }
    for(int i = 1; i <= N; i++){
      if(i == np.now)continue;
      if(!state[np.now][i])continue;
      decltype(np.edges)::iterator it = np.edges.find(i);
      if(it != np.edges.end())continue;
      Path next = np;
      next.edges.insert(i);
      next.now = i;
      que.push(next);
    }
  }cout << ans << endl;

}
