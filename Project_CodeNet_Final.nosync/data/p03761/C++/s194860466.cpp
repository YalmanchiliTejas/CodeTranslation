#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> v(n,vector<int>(26,0));
  
  rep(i,n){
    string s;
    cin >> s;
    rep(j,s.size()){
      v[i][s[j] - 'a']++;
    }
  }
  
  int INF = 1 << 30;
  vector<int> v2(26,INF);
  rep(j,26){
    rep(i,n){
      v2[j] = min(v2[j], v[i][j]);
    }
  }
  
  rep(i,26){
    if(v2[i] != INF){
      rep(j,v2[i]){
        char ans = 'a' + i;
        cout << ans;
      }
    }
  }
  
  return 0;
}