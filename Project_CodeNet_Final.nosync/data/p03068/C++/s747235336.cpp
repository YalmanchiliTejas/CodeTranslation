#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  string S;
  cin >> N >> S >>K;
  //一文字ずつ比較していく
  for (int i=0; i<N; i++){
    //文字列SのK番目の文字と異なるかどうか判定する。
    if (S.at(i) == S.at(K-1)){
    }else{
      S.replace(i,1,"*");
    }
  }
  cout << S;
}
