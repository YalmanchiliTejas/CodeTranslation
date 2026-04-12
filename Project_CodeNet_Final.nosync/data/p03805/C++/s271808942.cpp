#include <bits/stdc++.h>
using namespace std;

int N,M;
int pass;

void dfs( int x , vector<bool> seen ,vector< vector<int> > &G){

  //すでに頂点xを訪れている
  if( seen[x] ) return;

  seen[x] = true;

  //全ての頂点に訪問したか
  bool flag = true;
  for( int i = 0; i < N; i++){
    if( !(seen[i]) ){
      flag = false;
    }
  }
  //した（→パスになっている）
  if( flag ){
    pass++;
    return;
  }

  for( auto next_x : G[x] ){
    dfs( next_x , seen , G );
  }

}

int main(){

  cin >> N >> M;
  vector< vector<int> > G( N , vector<int> (M) );
  for( int i = 0; i < M; i++){

    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);

  }

  pass = 0;
  vector<bool> seen(N);
  dfs( 0 , seen , G );

  cout << pass << endl;

  return 0;

}
