#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <set>

int N, M;
std::vector<std::vector<int>> T;
int ans = 0;

void sol (int cur, std::set<int> list, std::string str){
  if ( list.size() == 0 ) {
    ans++;
    return;
  }

  for(auto itr = list.begin(); itr != list.end(); ++itr){
    if ( T[cur][*itr] == 1 ) {
      auto l = list;
      l.erase(*itr); sol(*itr, l, str+"-"+std::to_string(*itr));
      continue;
    }
  }
  return;
}

int main (void) {

  std::cin >> N >> M;
  T.resize(N); for(int i=0; i<N; i++) T[i].assign(N,0);

  for(int i=0; i<M; i++){
    int a, b; std::cin >> a >> b;
    T[a-1][b-1] = 1;
    T[b-1][a-1] = 1;
  }

  std::set<int> list;
  for(int i=1; i<N; i++) list.insert(i);
  sol(0, list, "0"); std::cout << ans << std::endl;

  return 0;
}