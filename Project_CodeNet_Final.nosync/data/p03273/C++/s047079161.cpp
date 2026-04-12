#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  for(int i=0;i<h;i++)
    cin>>a.at(i);
  vector<bool> r(h,0);
  vector<bool> c(w,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#'){
        r.at(i)=1;
        c.at(j)=1;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(r.at(i)){
      for(int j=0;j<w;j++)
        if(c.at(j))
          cout<<a.at(i).at(j);
      cout<<endl;
    }
  }
}