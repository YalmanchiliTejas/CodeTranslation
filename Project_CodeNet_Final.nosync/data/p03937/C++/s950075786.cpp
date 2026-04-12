#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<random>
using namespace std;


int main(){

  int h, w;
  cin >> h >> w;
  vector< string > a(h);

  for(int i=0; i<h; i++) cin >> a[i];

  bool f = true;
  for(int i=0; i<h-1; i++){
    for(int j=0; j<w-1; j++){
      if( a[i+1][j] == '#' && a[i][j+1] == '#' ){
        f = false;
        break;
      }
    }
  }
  if( f ) cout << "Possible" << endl;
  else cout << "Impossible" << endl;


  return 0;
}














// EOF
