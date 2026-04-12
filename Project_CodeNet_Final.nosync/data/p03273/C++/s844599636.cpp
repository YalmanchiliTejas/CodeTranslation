#include <bits/stdc++.h>
using namespace std;

int main(){
int h,w;
  cin>>h>>w;
  vector<vector<char>> table(h,vector<char>(w));
  vector<int> r(h);
  vector<int> c(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>table.at(i).at(j);
      if(table.at(i).at(j)=='#'){
        r.at(i)=1;
        c.at(j)=1;
      }
    }
  }
  int max=0;
  for(int j=0;j<w;j++){
    if(c.at(j)){
      max=j;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(r.at(i)&&c.at(j)){
        if(j!=max){
        cout<<table.at(i).at(j);
        }else{
        cout<<table.at(i).at(j)<<endl;
        }
      }
    }
  }
}
 
