#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<string> vec(h);
  for(int i=0;i<h;i++){
    cin>>vec.at(i);
  }
  int a=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(vec.at(i).at(j)!='#'){
        a++;
      }
    }
    if(a==w){
      for(int j=0;j<w;j++){
        vec.at(i).at(j)='@';
      }
    }
    a=0;
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(vec.at(j).at(i)!='#'){
        a++;
      }
    }
    if(a==h){
      for(int j=0;j<h;j++){
        vec.at(j).at(i)='@';
      }
    }
    a=0;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(vec.at(i).at(j)!='@'){
        cout<<vec.at(i).at(j);
      }
    }
    cout<<endl;
  }  
}