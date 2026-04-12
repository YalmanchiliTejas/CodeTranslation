#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define H_MAX 50
#define W_MAX 50

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int H,W;

namespace patch {
  template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
}
int answer = 0;

bool check_all_visited(bool* visited, int num) {
  rep(i,num){
    if(visited[i] == true)
      continue;
    else
      return false;
  }
  return true;
}
void dfs(int v, bool *visited, bool hoge[][8], int m) {
  if (check_all_visited(visited, m) == true) {
    answer += 1;
    return;
  } else {
    rep(i,m) {
      if(hoge[v][i] == true && visited[i] == false) {
	visited[i] = true;
	dfs(i, visited, hoge, m);
	visited[i] = false;
      }
    }
    return;
  }
}
  

int main() {
  int n,m;
  vector<pii> p_vec;
  pii p;
  cin >> n >> m;
  bool hoge[n][8];
  rep(i,n) {
    rep(j,n) {
      hoge[i][j] = false;
    }
  }
  rep(i,m) {
    cin >> p.fi >> p.se;
    p_vec.pb(p);
    hoge[p.fi-1][p.se-1] = true;
    hoge[p.se-1][p.fi-1] = true;
  }

  bool visited[8];
  rep(i,n) {
    visited[i] = false;
  }
  visited[0] = true;
  dfs(0, visited, hoge, n);

  cout << answer << endl;

  return 0;
}
 