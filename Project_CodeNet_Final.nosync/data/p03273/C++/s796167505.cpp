#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> x(h,vector<char>(w));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin>>x[i][j];
    }
  }
  //白だけの行Hと列Wをカウント
  vector<int> couh,couw;
  for(int i=0; i<h; i++){
    int a=0;
    for(int j=0; j<w; j++){
      if(x[i][j]=='.'){
        a++;
      }
    }
    if(a==w){
      couh.push_back(i);
    }
  }

  for(int i=0; i<w; i++){
    int a=0;
    for(int j=0; j<h; j++){
      if(x[j][i]=='.'){
        a++;
      }
    }
    if(a==h){
      couw.push_back(i);
    }
  }
    //cout<<couw[0]<<endl<<endl;
    //出力
  bool okh=true,okw=true;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      okh=true;okw=true;
      for(int k=0; k<couh.size(); k++){
        if(couh[k]==i){
            okh=false;
        }
      }
      for(int k=0; k<couw.size(); k++){
        if(couw[k]==j){
            okw=false;
        }
      }
      if(okh&&okw){
          cout<<x[i][j];
      }
    }
    if(okh){
      cout<<endl;
    }
  }
}