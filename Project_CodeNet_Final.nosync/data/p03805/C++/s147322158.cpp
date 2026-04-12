#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

using Graph = vector<vector<int>>;

int main(){
  int n, m; cin >> n >> m;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> vec(n);
  rep(i, n) vec[i] = i;
  vector<int> seen(n);
  rep(i, n) seen[i] = 0;
  int n_seen = 0;
  do{
    if (vec[0] != 0) continue;
    seen.assign(n, 0);
    seen[0] = 1;
    rep(i, n){
      if (vec[i] == 0) continue;
      if (find(G[vec[i]].begin(), G[vec[i]].end(), vec[i-1]) != G[vec[i]].end()){ //前回のものと繋がっている場合
        seen[vec[i]] = 1;
      }
    }
    if (count(seen.begin(), seen.end(),1) == n) n_seen++;
    
  }while (next_permutation(vec.begin(), vec.end()));
  cout << n_seen << endl;
}
