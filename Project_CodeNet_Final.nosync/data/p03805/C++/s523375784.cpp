#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int, pair<int, vector<int>>>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>());
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph.at(y).push_back(x);
    graph.at(x).push_back(y);
  }
  P p = make_pair(0, make_pair(0, vector<int>(n, 0)));
  p.second.second.at(0) = 1;
  queue<P> que;  
  que.push(p);
  // cout << "graph:start" << endl;
  // rep(i,n){
  //   cout << i << ", ";
  //   cout << "[ ";
  //   for(auto &v: graph.at(i)) cout << v << ": ";
  //   cout << " ]" << endl;
  // }
  // cout << "graph:end" << endl;
  int ans = 0;
  while(!que.empty()) {
    P v = que.front();
    que.pop();
    if (v.second.first == n - 1) {
      int tmp = count(ALL(v.second.second), 1);  
      if (tmp == n) ans++;
      continue;
    } 
    for(auto &nv : graph.at(v.first)) {      
      if (v.second.second.at(nv) >= 1) continue;  
      vector<int> tvec(n, 0);
      rep(i, n) tvec.at(i) = v.second.second.at(i);
      tvec.at(nv)++;
      que.push(make_pair(nv, make_pair(v.second.first+1, tvec)));
    }
  }
  cout << ans << endl;

  
  
  return 0;
}