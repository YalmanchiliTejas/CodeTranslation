#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> a(h, vector<char>(w));

  for ( int i = 0; i < h; i++ ){
    for ( int j = 0; j < w; j++){
      cin >> a.at(i).at(j);
    }
  }

  vector<bool> row(h, false);
  vector<bool> col(w, false);

  for ( int i = 0; i < h; i++ ){
    for ( int j = 0; j < w; j++ ){
      if ( a.at(i).at(j) == '#' ){
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }

  for ( int i = 0; i < h; i++ ){
    if ( row.at(i) == true ){
      for ( int j = 0; j < w; j++ ){
        if ( col.at(j) == true ){
          cout << a.at(i).at(j);
        }
      }

      cout << endl;
    } 
  }

}
