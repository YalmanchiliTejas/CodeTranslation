#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  string s;
  cin>>h>>w;
  bool a=false;
  vector<bool> height(h,false);
  vector<bool> width(w,false);
  vector<vector<string>> data(h, vector<string>(w));
  for(int i=0; i<h; i++){
    cin>>s;
    for(int j=0; j<w; j++){
      data.at(i).at(j)=s.at(j);
      }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w-1; j++){
      if(data.at(i).at(j)==data.at(i).at(j+1)&&data.at(i).at(j)=="."){
        a=true;
      } else {a=false;  break;}
    }
    if(a==true){
      height.at(i)=true;
      a=false;
    }
  }
  for(int i=0; i<w; i++){
    for(int j=0; j<h-1; j++){
      if(data.at(j).at(i)==data.at(j+1).at(i)&&data.at(j).at(i)=="."){
        a=true;
      } else {a=false; break;}
    }
    if(a==true){
      width.at(i)=true;
      a=false;
      }
  }
  for(int i=0; i<h; i++){
    if(height.at(i)==false){
      for(int j=0; j<w; j++){
        if(width.at(j)==false){
          cout<<data.at(i).at(j);
        } 
      }
      cout<<endl;
    }
  }
}