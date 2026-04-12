#include<bits/stdc++.h>
using namespace std ;
int main () {
  int H , W ;
  cin >> H >> W ;
  int pre = 0 ;
  for(int i = 0 ; i < H ; i++ ){
    for(int j = 0 ; j < W ; j++ ){
      char ch ;
      cin >> ch ;
      if(ch=='#') pre ++ ;
    }
  }
  if(pre == H + W -1 ) cout << "Possible" << endl ;
  else cout << "Impossible" << endl ;
}