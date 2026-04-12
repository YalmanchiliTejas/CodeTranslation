#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int H,W; cin >> H >> W;
  char data[101][101];
  for ( int i = 1; i <=H; i++ ) {
    for ( int j = 1; j <= W; j++ ) {
      cin >> data[i][j];
    }
  }
  //  bool f = true;
  int cnt;

  for ( int i = 1; i <= H; i++ ) {
    cnt = 0;
    for ( int j = 1; j <=W; j++ ) {
      if(data[i][j] == '.' ) {
	cnt++;
	if(cnt == W) {
	  for ( int k = 1; k <= W; k++ ) {
	    data[i][k] = 'X';
	  }
	}
		     
      }
    }
  }
    for ( int j = 1; j <= W; j++ ) {
    cnt = 0;
    for ( int i = 1; i <=H; i++ ) {
      // cout << data[i][j];

      if(data[i][j] == '.' || data[i][j] == 'X') {
	cnt++;
	if(cnt == H) {
	  //	  len++;
	  for ( int k = 1; k <= H; k++ ) {
	    //cout << "i " << i << " j " << j << " k " << k;
	    data[k][j] = 'X';
	    //cout << data[j][k];
	  }
	  //	  cout << endl;
	}
		     
      }

    }

    // cout << endl;
  }

    for ( int i = 1; i <= H; i++ ) {
      cnt = 0;
      for ( int j = 1; j<= W; j++ ) {
	if ( data[i][j] != 'X' ){
	cout << data[i][j];	
	}
	if(data[i][j] == 'X' ) cnt++;
	//	 if ( j == W )cout << endl;
      }
      if( cnt != W )cout << endl;
    }
    
    
  return 0;
}
