#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w ; 
  cin >> h >> w ; 
  vector<vector<char>> data(h ,vector<char> (w));
  for (int i = 0; i < (int)(h); i++){
    for (int j = 0; j < (int)(w); j++){
      cin >> data.at(i).at(j) ;
    }
  }
  
  vector<int> yoko , tate;
  
    for (int i = 0; i < (int)(h); i++){
    int  count = 0 ;
     for (int j = 0; j < (int)(w); j++){
      if(data.at(i).at(j) == '.') count ++ ;
    }
    if(count != w) yoko.push_back(i) ;
  }
  
  for (int i = 0; i < (int)(w); i++){
    int  count = 0 ;
    for (int j = 0; j < (int)(h); j++){
      if(data.at(j).at(i) == '.')  count ++  ;
    }
    if(count != h) tate.push_back(i) ;
  }
  
  
 for (int i = 0; i < (int)(yoko.size());i++){
     for (int j = 0; j < (int)(tate.size());j++){
      cout << data.at(yoko.at(i)).at(tate.at(j)) ;
    }
    cout <<endl;
  }
  
}