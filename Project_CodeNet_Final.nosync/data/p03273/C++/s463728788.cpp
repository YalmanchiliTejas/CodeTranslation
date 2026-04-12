#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  long long int a,b;cin>>a>>b;
  vector<vector<char>>c(a,vector<char>(b));
  bool e[a];
  bool f[b];
  rep(i,a)rep(j,b)cin>>c[i][j];
  rep(i,a){
    bool d=true;
    e[i]=false;
    rep(j,b){
      if(c[i][j]!='.')d=false;
  }
    if(d)e[i]=true;
  }
  rep(i,b){
    bool d=true;
    f[i]=false;
    rep(j,a){
      if(c[j][i]!='.')d=false;
    }
    if(d)f[i]=true;
  }
  rep(i,a){
    if(e[i])continue;
    rep(j,b){
      if(f[j]){
        continue;
        j++;
      }
      cout<<c[i][j];
    }
    cout<<endl;
  }
}