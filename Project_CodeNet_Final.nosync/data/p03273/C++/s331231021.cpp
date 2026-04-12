#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int h, w;
  cin >> h >> w;
  int count;
  int checkl[h], checkc[w];
  rep(i, h) checkl[i] = 0;
  rep(i, w) checkc[i] = 0;
  
  vector<vector<char>> grid(h, vector<char>(w));
  vector<vector<int>> ans(h, vector<int>(w, 0));
  
  rep(i, h){
    rep(j, w){
      cin >> grid.at(i).at(j);
    }
  }
  rep(i, h){
    count = 0;
    rep(j, w){
      if (grid.at(i).at(j) == '.'){
        count++;
      }
    }
    if (count == w) {
      checkl[i] = 1;
      
    }
    
  }
  rep(i, h) {
    if (checkl[i] == 1){
      rep(j, w){
        ans.at(i).at(j) = 1;
      }
    }
  }
  rep(i, w){ ///列の処理
    count = 0;
    rep(j, h){
      if (grid.at(j).at(i) == '.'){
        count++;
      }
    }
    
  
    if (count == h){
      checkc[i] = 1;
    }
    
  }
  rep(i, w){
    if(checkc[i] == 1){
      rep(j, h){
        ans.at(j).at(i) = 1;
      }
    }
  }
  
  rep(i, h){
    if(checkl[i] != 1){
    rep(j, w){
      if(ans.at(i).at(j) == 0){
        cout << grid.at(i).at(j) ;
      }
    }
    cout << endl;
  }
  }
}