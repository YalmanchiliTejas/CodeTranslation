#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h, vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a.at(i).at(j);
    }
  }
  int count=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#'){
        count++;
      }
    }
  }
  if(count==h+w-1){
    cout<<"Possible";
  }
  else{
    cout<<"Impossible";
  }
}
