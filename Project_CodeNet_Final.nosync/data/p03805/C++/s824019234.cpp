#include<bits/stdc++.h>
using namespace std;

int G[100][100];

signed main(){

  int n,m; cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    a--; b--;
    G[a][b] = G[b][a] = 1;
  }

  vector<int> v;
  for(int i = 0; i < n; i++) v.push_back(i);
  int ans = 0;
  do{
    for(int i = 0; i < n-1; i++){
      if(G[ v[i] ][ v[i+1] ] == 0) break;
      if(i == n-2) ans++;
    }
  }while( next_permutation(v.begin()+1,v.end()) );
  cout << ans << endl;

  return 0;
}
