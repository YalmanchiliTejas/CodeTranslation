#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin>>n>>m;
  bool adj_matrix[n][n];
  vector<int> v,p;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      adj_matrix[i][j] = false;
    }
    if( i != 0 ) p.push_back(i);
    v.push_back(i);
  }
  for(int i=0; i<m; ++i){
    int a,b; cin>>a>>b;
    adj_matrix[a-1][b-1] = adj_matrix[b-1][a-1] = true;
  }
  int ret=0; bool reached;
  do{
    reached = true;
    for(int i=0; i<n-1; ++i){
      v[i+1] = p[i];
      if( !adj_matrix[v[i]][v[i+1]] ){
        reached =false; break;
      }
    }
    if ( reached) ++ret;
  } while( next_permutation(p.begin(), p.end()));
  cout << ret <<endl;
  return 0;
}