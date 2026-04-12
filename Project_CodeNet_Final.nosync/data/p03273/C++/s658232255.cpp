#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;

int main(){
  int H,W;
  cin >>H>>W;
  int count=0;
  vector<vector<char>> V(H,vector<char>(W));
  vector<bool> I(H,true);
  vector<bool> J(W,true);

  //Vを作成
  rep(i,H){
    rep(j,W){
      cin >>V.at(i).at(j);
    }
  }
  
  //横探索
  rep(i,H){
    rep(j,W){
      if(V.at(i).at(j)== '#')
        count++;
    }
    if(count==0)
      I.at(i)=false;   
    count=0;
  }
  
  //縦探索
  rep(j,W){
    rep(i,H){
      if(V.at(i).at(j)== '#')
        count++;
    }
    //cout << count <<endl;
    if(count==0)
      J.at(j)=false; 
    count=0;
  }
  
  //出力
  rep(i,H){
    rep(j,W){
      if(I.at(i) && J.at(j)){
        cout << V.at(i).at(j);
        count++;
      }    
    }
    if(count>0){
      cout << endl;
      count =0;
    }
  }
  cout << endl;
}