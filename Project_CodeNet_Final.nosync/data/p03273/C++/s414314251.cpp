#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<int> a(h,0),b(w,0);
  vector<vector<char>> g(h,vector<char>(w));
  int i,j;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> g.at(i).at(j);
      if(g.at(i).at(j)=='#'){
        a.at(i)++;
        b.at(j)++;
      }
    }
  }
  
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(a.at(i)!=0&&b.at(j)!=0){
        cout << g.at(i).at(j);
      }
    }
    if(a.at(i)!=0){
      cout << endl;
    }
  }
}