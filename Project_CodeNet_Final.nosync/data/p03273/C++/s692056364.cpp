#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a.at(i).at(j);
    }
  }
  vector<bool> gyou(h,false);
  vector<bool> retsu(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#'){
        gyou.at(i)=true;
        retsu.at(j)=true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(gyou.at(i)==true){
      for(int j=0;j<w;j++){
        if(retsu.at(j)==true){
          cout << a.at(i).at(j);
        }
      }
       cout << endl;
    }
  }
}