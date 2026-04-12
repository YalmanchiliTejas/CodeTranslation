#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int main(){
  int h,w;
  cin >> h>> w;
  char a[h][w];//たて、よこ
  bool b[h]={},c[w]={};
  rep(i,h){
    rep(r,w){
      cin >> a[i][r];
    }
  }

  rep(i,h){
    int g=0;
    rep(r,w){
      if(a[i][r]=='#')g++;
    }
    if(g==0)b[i]=1;
  }
  rep(i,w){
    int g=0;
    rep(r,h){
      if(a[r][i]=='#')g++;
    }
    if(g==0)c[i]=1;
  }

  rep(i,h){
    rep(r,w){
      if(b[i]==0 && c[r]==0){cout << a[i][r];}
    }
    if(b[i]==0)cout << endl;
  }
  
}