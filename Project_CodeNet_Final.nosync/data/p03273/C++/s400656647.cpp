#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<string>> a(H,vector<string>(W));
  string tmp;
  for (int i = 0; i < H; i++) {
    cin >> tmp;
    for(int j=0;j<W;j++){
      a.at(i).at(j)=tmp.at(j);
    }
  }
  bool isW=true;
  for(int i=0;i<H;i++){
    isW=true;
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=="#"){
        isW=false;
      }
    }
    if(isW){
      for(int j=0;j<W;j++){
        a.at(i).at(j)="V";
      }
    }
  }
  for(int i=0;i<W;i++){
    isW=true;
    for(int j=0;j<H;j++){
      if(a.at(j).at(i)=="#"){
        isW=false;
      }
    }
    if(isW){
      for(int j=0;j<H;j++){
        a.at(j).at(i)="V";
      }
    }
  }
  bool isWrite=false;  
for(int i=0;i<H;i++){
  isWrite=false;
  for(int j=0;j<W;j++){
    if(a.at(i).at(j)=="V"){
      continue;
    }else{
      cout << a.at(i).at(j);
      isWrite=true;//その行になんか書いたか
    }
  }
  if(isWrite)  cout << endl;
}



}
