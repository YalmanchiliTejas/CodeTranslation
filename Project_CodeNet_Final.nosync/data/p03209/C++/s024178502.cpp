#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}

ll len[51],pat[51];
ll rec(ll k, ll x){
  if(x == len[k]) return pat[k]; //x層の数がlenと同じだったら全パティの数を返せば良い
  ll ans = 0;
  x--;
  
  if(x > 0){//まず下のバーガーから計算
    ll l = min(x,len[k-1]); //xがk-1レベルのバーガーを超えていたらlenにする。(xが下段のバーガーに収まるかチェック)
    ans += rec(k-1,l);
    x -= l;
  }
  
  if(x > 0){//真ん中のパティ
    ans++;
    x--;
  }
  
  if(x > 0){//上段のバーガー
    ll l = min(x,len[k-1]);
    ans += rec(k-1,l);
    x -= l;
  }
  
  return ans;
}

int main(){
  ll n,x; cin >> n >> x;
  //先にバーガーの長さとパティの数を計算して配列に入れておく
  len[0] = pat[0] = 1;
  for(int i = 1; i <= n; i++){
    len[i] = len[i-1] * 2 + 3;
    pat[i] = pat[i-1] * 2 + 1;
  }
  
  cout << rec(n,x) << endl;
  return 0;
}