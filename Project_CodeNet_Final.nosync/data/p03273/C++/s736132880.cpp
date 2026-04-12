#include<iostream>
#include<cstring>
using namespace std;

bool goodx[101],goody[101];

int main(){
  int H,W; cin >> H >> W;
  string board[101];
  for ( int i = 0; i < 101; i++ ) {
    goodx[i] = false;
    goody[i] = false;
  }
  for ( int i = 0; i < H; i++ ) {
    cin >> board[i];
  }
    
  for ( int i = 0; i < H; i++ ) {
    for ( int j = 0; j < W; j++ ) {
      if ( board[i][j] == '#') {
	goodx[i] = true;
	goody[j] = true;
      }
    }
  }

  
  for ( int i = 0; i < H; i++ ) {
    if ( goodx[i] ) {
      for ( int j = 0; j < W; j++ ) {
	if ( goody[j] ) {
	  cout << board[i][j];
	}
      }
      cout << endl;
    }
  }
  return 0;
}
