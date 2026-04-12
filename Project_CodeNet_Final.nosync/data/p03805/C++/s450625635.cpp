#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

bool path[10][10] = {};

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<int> v(n);
  rep(i,n) v[i] = i;
  
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    path[a][b] = true;
    path[b][a] = true;
  }
  
  int ans = 0;
  do{
    if(v[0] == 0){ 
      bool can = true;
      rep(i, n-1){
        if(path[v[i]][v[i+1]] == false) can = false;
      }
      if(can) ans++;
    }
  }while(next_permutation(v.begin(),v.end()));
  
  cout << ans << endl;
  return 0;
  
}