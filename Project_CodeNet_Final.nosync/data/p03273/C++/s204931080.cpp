#include <iostream>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
char a[101][101];

int main(){
  int h,w;cin>>h>>w;
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }

  set<int> line,column;
  bool flg;
  rep(i,h){
    flg=false;
    rep(j,w){
      if(a[i][j] != '.'){
        flg=true;
        break;
      }
    }
    if(flg==false){
      column.insert(i);
    }
  }

  rep(i,w){
    flg=false;
    rep(j,h){
      if(a[j][i] != '.'){
        flg=true;
        break;
      }
    }
    if(flg==false){
      line.insert(i);
    }
  }

  rep(i,h){
    if(column.count(i)==0){
      rep(j,w){
        if(line.count(j)==0){
          cout<<a[i][j];
        }
      }
      cout<<endl;
    }
  }
}