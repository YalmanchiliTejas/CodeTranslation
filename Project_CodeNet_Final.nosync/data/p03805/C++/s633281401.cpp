#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for(long i = x; i < n; i++)
#define erep(i, x, n) for(long i = x; i <= n; i++)
#define all(a) a.begin(), a.end()
#define eall(a) a.begin()+1, a.end()
#define show(ans)  cout << ans << endl;
const long MOD = 1000000007;

long N, M;
long cnt = 0;
vector<bool> vis(9, false);
vector<vector<long>> s(9);
bool check(){
  erep(i, 1, N){
    if(vis[i] == false){
      return false;
    }
  }
  return true;
}

void dfs(long x){
  vis[x] = true;
  if(check() == true){
    cnt++;
    vis[x] = false;
    return;
  }
  rep(i, 0, s[x].size()){
    if(vis[s[x][i]] == false) dfs(s[x][i]);
  }
  vis[x] = false;
  return;
}

int main(){
cin >> N >> M;
erep(i, 1, M){
  long a1, b1;
  cin >> a1 >> b1;
  s[a1].push_back(b1);
  s[b1].push_back(a1);
}
dfs(1);
show(cnt);

return 0;
}