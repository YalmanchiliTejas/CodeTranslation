#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int h,w; cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<vector<bool>> check(h,vector<bool>(w,true));
  
  rep(i,h){
    bool b = true;
    rep(j,w){
      if(a[i][j] == '#') b = false;
    }
    if(b){
      rep(k,w) check[i][k] = false;
    }
  }
  rep(j,w){
    bool b = true;
    rep(i,h){
      if(a[i][j] == '#') b = false;
    }
    if(b){
      rep(k,h) check[k][j] = false;
    }
  }
  
  rep(i,h){
    bool b = false;
    rep(k,w){
      if(check[i][k]) b = true;
    }
    if(b){
      rep(j,w){
        if(check[i][j]) cout << a[i][j];
      }
      cout << endl;
    }
  }
  
  
  return 0;
}