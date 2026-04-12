#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int x,y,z;
  cin >> x >> y >>z;
  int count = 0;

  while(true){
    if(x < y * count + z * (count+1)){
      count--;
      break;
    }
    count++;
  }
  
  cout << count;
  return 0;
}