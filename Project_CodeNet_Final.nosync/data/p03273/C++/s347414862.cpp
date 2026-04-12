#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  
  vector<bool> exih(h,false);
  vector<bool> exiw(w,false);
  
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        exih[i]=true;
        exiw[j]=true;
      }
    }
  }
  
  rep(i,h){
    int out = 0;
    rep(j,w){
      if(exih[i]&&exiw[j]){
        cout << a[i][j];
        out ++;
      }
    }
    if(out>0)
     cout << endl;
  }
}