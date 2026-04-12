#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,ans;
vector<int> path[10];
bool reached[10];
void dfs(int x){
  reached[x] = true;
  int c = 0;
  for(int i=0;i<n;++i)
    if(reached[i]) c++;
  if(c==n){
    ans++;
    return;
  }
  for(auto &i:path[x]){
    if(reached[i]) continue;
    dfs(i);
    reached[i] = false;
  }
}

int main()
{
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  
  ans = 0;
  for(int i=0;i<n;++i) reached[i]=false;
  dfs(0);
  cout << ans << "\n";
  
}
