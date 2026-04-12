#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a.at(i).at(j);
    }
  }
  vector<bool> row(H,true),line(W,true);
  for(int i=0;i<H;i++){
    bool flag=true;
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      row.at(i)=false;
    }
  }
  for(int i=0;i<W;i++){
    bool flag=true;
    for(int j=0;j<H;j++){
      if(a.at(j).at(i)=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      line.at(i)=false;
    }
  }

  for(int i=0;i<H;i++){
    if(!row.at(i)){
      continue;
    }
    for(int j=0;j<W;j++){
      if(row.at(i)&&line.at(j)){
        cout<<a.at(i).at(j);
      }
    }
    cout<<endl;
  }
}
