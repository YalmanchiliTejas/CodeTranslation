#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector <int> v[10];
int fix[10],ans,n,m;
void dfs (int x,int r){
      if (r == n) ans++;
      fix[x] = 1;
      for (int i = 0; i < v[x].size(); i++){
            int to = v[x][i];
            if (!fix[to]) dfs(to,r + 1);
      }
      fix[x] = 0;
      return;
} 
int main (){
  cin >> n >> m;
  
    for (int i = 1; i <= m; i++){
          int a,b;
          cin >> a >> b;
          v[a].pb(b);
          v[b].pb(a);
    }
    dfs(1,1);
    cout<<ans;
}