#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>> a(h,vector<char>(w));
  for ( int i = 0; i < h; i++){
    for ( int j = 0; j < w; j++){
      cin >> a[i][j];
    }
  }
  
  
  
  int hanteiyoko,hanteitate;
  
  for ( int i = 0; i < h; i++){
    hanteiyoko = 1;
    for ( int j = 0; j < w; j++){
      if ( a[i][j] == '#' ){
        hanteiyoko = 0;
      }
    }
    if ( hanteiyoko == 1 ){
      for ( int j = 0; j < w; j++){
        a[i][j] = ' ';
      }
    }
  }
  
  for ( int j = 0; j < w; j++){
    hanteitate = 1;
    for ( int i = 0; i < h; i++){
      if ( a[i][j] == '#' ){
        hanteitate = 0;
      }
    }
    if ( hanteitate == 1 ){
      for ( int i = 0; i < h; i++){
        a[i][j] = ' ';
      }
    }
  }
  
  
  for ( int i = 0; i < h; i++){
    hanteiyoko = 1;
    for ( int j = 0; j < w; j++){
      if ( a[i][j] == ' ' ){
      	continue;
      }else{
        cout << a[i][j];
        hanteiyoko = 0;
      }
    }
    if ( hanteiyoko == 0 ){
      cout << endl;
    }
  }
  
}