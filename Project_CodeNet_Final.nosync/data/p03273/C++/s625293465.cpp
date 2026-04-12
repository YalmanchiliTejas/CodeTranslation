#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
  
  int H, W;
  cin >> H >> W;
  
  vector<string> A(H);
  for( int i = 0; i < H; i++ ){
    cin >> A.at(i);
  }
  
  vector<bool> yoko(W, false);
  vector<bool> tate(H, false);
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W; j++ ){
      if( A.at(i).at(j) == '#' ){
        yoko.at(j) = true;
        tate.at(i) = true;
      }
    }
  }
  
  for( int i = 0; i < H; i++ ){
    if( tate.at(i) == true ){
      for( int j = 0; j < W; j++ ){
        if( yoko.at(j) == true ){
          cout << A.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  
}

