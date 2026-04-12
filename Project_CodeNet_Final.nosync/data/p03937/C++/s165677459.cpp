#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
using namespace std;

typedef long long ll;

int main() {
  int H,W; cin >> H >> W;
  string s[9],t[9];
  for ( int i = 0; i < H; i++ ) cin >> s[i];
  for ( int i = 0; i < H; i++ ) {
    t[i] = s[i];
  }
  bool f = true;
  int i = 0,j = 0;
  s[i][j] = '.';
  while(1) {
    if (  j-1 >= 0 && s[i][j-1] == '#' ) {
      f = false;
      break;
    } else if ( i-1 >= 0 && s[i-1][j] == '#' ) {
      f = false;
      break;      
    } else if (i+1 < H && s[i+1][j] == '#' ) {
      s[i][j] = '.';      
      i++;
    } else if (j+1 < W && s[i][j+1] == '#' ) {
      s[i][j] = '.';            
      j++;
    } else {
      f = false;
      break;
    }
    
    if ( i == H-1 && j == W-1 ) break;
  }
  i = 0,j = 0;
  t[i][j] = '.';
  while(1) {
    if (  j-1 >= 0 && t[i][j-1] == '#' ) {
      f = false;
      break;
    } else if ( i-1 >= 0 && t[i-1][j] == '#' ) {
      f = false;
      break;      
    } else if ( j+1 < W && t[i][j+1] == '#') {
      t[i][j] = '.';      
      j++;
    } else if ( i+1 < H && t[i+1][j] == '#') {
      t[i][j] = '.';            
      i++;
    } else {
      f = false;
      break;
    }
    
    if ( i == H-1 && j == W-1 ) {
      if ( s[i-1][j] == '#' || s[i][j-1] == '#' ) {
	f = false;
	break;
      } else {
	break;
      }
    }
  }  

  if (f) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
