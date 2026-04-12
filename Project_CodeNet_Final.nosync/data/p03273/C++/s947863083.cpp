#include <bits/stdc++.h>
using namespace std;

int main(){

  int h,w;
  cin>>h>>w;
  
  vector<string> data(h);
  
  vector<bool> g(h);
  vector<bool> r(w);
  
  for (int i=0;i<h;i++){
    cin>>data.at(i);
  }
  
  for (int i=0;i<h;i++){
    bool flag1=false;
    for (int j=0;j<w;j++){
      if (data.at(i).at(j)=='#'){
        flag1=true;
        break;
      }
    }
  g.at(i)=flag1;
  }
  
  
  
  for (int j=0;j<w;j++){
    bool flag2=false;
    for (int i=0;i<h;i++){
      if (data.at(i).at(j)=='#'){
        flag2=true;
        break;
      }
    }
    r.at(j)=flag2;
  }
  
  
  
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      if (g.at(i)==true and r.at(j)==true){
        cout<<data.at(i).at(j);
      }
    }
    cout<<endl;
  }
  
  
}
  











