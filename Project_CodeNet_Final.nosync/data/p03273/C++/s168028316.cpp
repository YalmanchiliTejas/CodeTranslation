#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char> > a(h,vector<char>(w));
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++)
      cin >> a.at(i).at(j);
  }
  vector<int> I(h);
  vector<int> J(w);
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
      if(a.at(i).at(j) != '.'){
        break;
      }
      if( j == w-1){
        I.at(i) = 1;
      }
    }
  }
  for(int i = 0;i<w;i++){
    for(int j = 0;j<h;j++){
      if(a.at(j).at(i) != '.'){
        break;
      }
      if(j == h-1){
        J.at(i) = 1;
      }
    }   
  }
  for(int i = 0;i<h;i++){
    if( I.at(i) !=1){
      for(int j = 0;j<w;j++){
        if( J.at(j) != 1){
          cout << a.at(i).at(j) ;
        }
        if( j == w-1){
          cout << endl;
        }
      }
    }
  }
}