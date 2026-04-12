#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h+1,vector<char> (w+1,'.'));

  rep(i,h){
    rep(j,w){
      cin >> a.at(i).at(j);
    }
  }

  int current_x = 0, current_y = 0;
  bool flag = 0;
  a.at(0).at(0) = '.';

  while(current_x != h - 1  || current_y != w - 1 ) {
    if(a.at(current_x + 1).at(current_y) == '#' && a.at(current_x).at(current_y + 1) != '#') {
      current_x++;
      a.at(current_x).at(current_y) = '.';
      if(current_x == h - 1 && current_y == w - 1) flag = 1;
      continue;
    }
    else if(a.at(current_x + 1).at(current_y) != '#' && a.at(current_x).at(current_y + 1) == '#') {
      current_y++;
      a.at(current_x).at(current_y) = '.';
      if(current_x == h - 1 && current_y == w - 1) flag = 1;
      continue;
    }
    else {
      break;
    }

    
  }

  // rep(i,h){
  //   rep(j,w){
  //     cout << a.at(i).at(j);
  //   }
  //   cout << endl;
  // }

  // cout << current_x << ' ' << current_y << endl;
  // 
  // cout << "flag" << flag << endl;

  if(flag == 1){
    bool flag2 = 1;
    rep(i,h){
      rep(j,w){
        if(a.at(i).at(j) == '#') flag2 = 0;
      }
    }
    flag = flag2;
  }

  if(flag == 0) cout << "Impossible" << endl;
  else{
    cout << "Possible" << endl;
  }
}

