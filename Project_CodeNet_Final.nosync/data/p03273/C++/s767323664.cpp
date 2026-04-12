#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int h,w;
  cin >>h >>w;
  string s[h];
  rep(i,h) cin >>s[i];
  vector<bool> row(h,false);
  vector<bool> col(w,false);
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#'){
        row[i]=true;
        col[j]=true;
      }
    }
  }
  rep(i,h){
    if(row[i]){
     rep(j,w){
       if(col[j]) cout <<s[i][j];
     }
     cout << endl;
    }
  }
  return 0; 
}