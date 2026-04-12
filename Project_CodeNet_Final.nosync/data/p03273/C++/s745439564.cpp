#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector <char>> masu( H, vector<char>( W ));

  int h, w;
  int check = 0;
  for ( h = 0; h < H; h++ ) {    
    for ( w = 0; w < W; w++ ) {
      cin >> masu.at( h ).at( w );
      if( masu.at( h ).at( w ) == '.' ) {
        check++;
      }
    }
    if( check == W ) {
      for ( int i = h; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
          if( i < H - 1 ) {
            masu.at( i ).at( j ) = masu.at( i + 1 ).at( j );
          }
        }
      }
      h--;
      H--;
    }
    check = 0;
  }      

  check = 0;
  for ( w = 0; w < W; w++ ) { 
    for ( h = 0; h < H; h++ ) { 
      if( masu.at( h ).at( w ) == '.' ) {
        check++;
      }
    }
    if( check == H ) {
      for ( int j = w; j < W; j++ ) {
        for ( int i = 0; i < H; i++ ) {
          if( j < W - 1 ) {
            masu.at( i ).at( j ) = masu.at( i ).at( j + 1 );
          }
        }
      }
      w--;
      W--;
    }
    check = 0;
  }
  for ( h = 0; h < H; h++ ) {
    for ( w = 0; w < W; w++ ) {
      cout << masu.at( h ).at( w );
    }
    cout << endl;
  }
  return 0;
}
