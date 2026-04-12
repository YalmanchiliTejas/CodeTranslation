#include<iostream>
using namespace std;

main()
{
  int h, w;
  char mp[10][10];
  int cnt=0;

  cin >> h >> w;
  for ( int i = 0 ; i < h ; ++i) {
    for ( int j = 0 ; j < w ; ++j) {
      cin >> mp[i][j];
    }
  }

  for (int i = 0 ; i < h ; ++i) {
    for ( int j = 0 ; j < w ; ++j) {
      if ( mp[i][j] == '#') {
	cnt ++;
      }
    }
  }

  if ( cnt == (h+w) - 1 ){
    cout << "Possible" << endl;
  } else { 
    cout << "Impossible" << endl;
  }

  return (0);
}
