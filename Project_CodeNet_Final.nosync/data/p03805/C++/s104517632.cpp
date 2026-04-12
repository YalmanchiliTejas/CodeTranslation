#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int N,M;
int ans = 0;
vector<vector<int>> G;

void dfs(int now, unsigned int bits){
  bits |= (1<<now);

  if(__builtin_popcount(bits) == N) {
    ans += 1;
    return;
  }

  for(auto e:G[now]){
    if(!(bits & (1<<e))){
      dfs(e,bits);
    }
  }

}

int main(){

  cin >> N >> M;
  G.resize(N);

  rep(i,M){
    int from,to;
    cin >> from >> to;
    from--;to--;

    G[from].push_back(to);
    G[to].push_back(from);
  }

  dfs(0,0b00000000);
  cout << ans << endl;

}