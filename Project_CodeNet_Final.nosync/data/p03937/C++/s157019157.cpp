#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> maze(h,vector<char>(w));
  rep(i,h)rep(j,w) cin >> maze[i][j];
  
  int num=0;
  
  rep(i,h)rep(j,w) if(maze[i][j] == '#') num++;
  
  if(num == h+w-1){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  
  return(0);
}