#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  
  int n = max(x,y);
  int ans = 1 << 30;
  for(int i = 0; i <= n; i++){
    int tmp = 0;
    tmp += i * c;
    if(i<x) tmp += (x-i) * a;
    if(i<y) tmp += (y-i) * b;
    
    chmin(ans, tmp);
  }
  
  cout << ans;
  
  return 0;
}