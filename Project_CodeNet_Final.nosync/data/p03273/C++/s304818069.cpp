#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w,x=0;
  bool finished=false;
  cin>>h>>w;
  vector<string> a(h);
  vector<vector<int>> b(h,vector<int>(w,1));
  for (int i=0;i<h;i++){
    cin>>a.at(i);
  }
  for (int i=0;i<h;i++){
    finished=false;
    for (int j=0;j<w;j++){
      if (a.at(i).at(j)=='#'){
        finished=true;
        break;
      }
    }
    if (finished){
      continue;
    }else{
      b.at(i)=vector<int>(w,0);
    }
  }
  for (int j=0;j<w;j++){
    finished=false;
    for (int i=0;i<h;i++){
      if (a.at(i).at(j)=='#'){
        finished=true;
        break;
      }
    }
    if (finished){
      continue;
    }else{
      for (int k=0;k<h;k++){
        b.at(k).at(j)=0;
      }
      x++;
    }
  }
  int y;
  for (int i=0;i<h;i++){
    y=0;
    for (int j=0;j<w;j++){
      if (b.at(i).at(j)==1){
        cout<<a.at(i).at(j);
        y++;
        if (w-x==y){
          cout<<endl;
        }
      }
    }
  }
}
    