#include<bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  vector<vector<char>> data(a,vector<char>(b));
  for ( int i = 0 ; i < a ; i++ ) {
    for ( int j = 0 ; j < b ; j++ ) {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<bool> row(a,false);
  vector<bool> lin(b,false);
  
  for ( int i = 0 ; i < a ; i++ ) {
    for ( int j = 0 ; j < b ; j++ ) {
     if ( data.at(i).at(j) == '#' ) {
       row.at(i) = true;
       lin.at(j) = true;
     }
    }
  }
  
  for ( int i = 0 ; i < a ; i++ ) {
    if ( row.at(i) ) {
      for ( int j = 0 ; j < b ; j++ ) {
        if (lin.at(j)) {
          cout << data.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}