#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

vvi G = vv(200001, 0, 0, int);
std::vector<int> w(200001, 0);
std::vector<int> c(200001, 0);
std::vector<int> ok(200001, 1);
void dfs(int from, int now, int mode){
  if(mode==-1&&c[now]>=2) {
    ok[from] = 0;
    return;
  }
  /*
  std::cout << now  << " " << from<< '\n';
  for(int i=1;i<=6;i++) std::cout << w[i] << " ";
  std::cout << '\n';
  */
  if(mode==1){
    if(w[now]==1){
      std::cout << "First" << '\n';
      exit(0);
    }
    w[now] = 1;
    for(int i=0;i<G[now].size();i++){
      c[G[now][i]]--;
    }
  }
  for(int i=0;i<G[now].size();i++){
    if(from==G[now][i]||ok[G[now][i]]==0) continue;
    dfs(now, G[now][i], -mode);
  }
}
int main(int argc, char const *argv[]) {
  int N, a, b;
  std::cin >> N;
  for(int i=0;i<N-1;i++){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1;i<=N;i++) c[i] = G[i].size();
  for(int i=1;i<=N;i++) if(G[i].size()==1) dfs(-1, i, -1);
  std::cout << "Second" << '\n';
  return 0;
}
