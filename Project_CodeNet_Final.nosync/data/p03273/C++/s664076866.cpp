#include<bits/stdc++.h>
using namespace std;
int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> data(h,vector<char>(w) );
  for ( int i = 0 ; i < h ; i++ ) {
    for ( int j = 0 ; j < w ; j++ ) {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<int> a(0),b(0);
  
  
  for ( int i = 0 ; i < h ; i++ ) {
    for ( char j : data.at(i)  ){
      if (j=='#'){
        a.push_back(i);
        break;
      }
    }
  }
  
  for ( int j = 0 ; j < w ; j++ ) {
    for ( int i = 0 ; i < h ; i++   ){
      if (data.at(i).at(j)=='#'){
        b.push_back(j);
        break;
      }
    }
  }
  
  for ( int i = 0 ; i < a.size() ; i++ ) {
    for ( int j = 0 ; j < b.size() ; j++ ) {
      cout << data.at(a.at(i)).at(b.at(j));
    }
    cout << endl;
  }
}