#include <iostream>
#include <vector>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int N,M;
vector<vector<int> > G(10);
vector<int> seen(10,0);
int ans = 0;

void dfs(int n, int cnt){
  if(cnt == (N-1)){
    ans++;
    return;
  }
  for(auto &i:G[n]){
    if(seen[i]) continue;
    seen[i] = 1;
    dfs(i,cnt+1);
    seen[i] = 0;
  }
}

int main(){
  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  seen[0] = 1;
  dfs(0,0);
  
  cout << ans << endl;
}