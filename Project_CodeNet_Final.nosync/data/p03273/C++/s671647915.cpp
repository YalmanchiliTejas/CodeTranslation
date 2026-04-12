#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<string> inputs(int H) {
  vector<string> data(H);
  rep(i, H){
    cin >> data.at(i);
  }
  return data;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> data = inputs(H);
  vector<bool> flag_yoko(H, false);
  vector<bool> flag_tate(W, false);
  
  rep(i, H){
    rep(j, W){
      if(data.at(i).at(j) == '#')
        flag_yoko.at(i) = true;
    }
  }
  rep(i, W){
    rep(j, H){
      if(data.at(j).at(i) == '#')
        flag_tate.at(i) = true;
    }
  }
  rep(i, H){
    rep(j, W){
      if(flag_yoko.at(i) && flag_tate.at(j))
        cout << data.at(i).at(j);
    }
    if(!flag_yoko.at(i))
      continue;
    cout << endl;
  } 
}