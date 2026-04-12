#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H;cin >>H; // 縦行数
  int W;cin >>W; // 横行数
  vector<string> A(H); // 入力升目
  vector<string> B(H); // 圧縮後升目：縦
  vector<vector<string>> C(H,vector<string>(W)); // 圧縮後升目：縦

  rep(i,H){
    cin >> A.at(i);
  }

  // 空白行を削除：行に # が含まれる場合のみ、転送する。
  int b =0; // 圧縮後配列の対象行数
  rep(i,H){
    bool del = true; // 転送非対象
    rep(j,W){
      if (A.at(i).at(j) == '#'){
        del = false;
        break;
      }
    }
    if (! del) {
      B.at(b) = A.at(i);
      b +=1;
    }
  }
// cout << "A-------------" << endl;

  // 横圧縮
  int c =0; // 圧縮後配列の処理対象列数
  rep(i,W){  // 各列ごとの処理
    // 縦に見て、# があるか判定
    bool del = true; // 転送非対象
    rep(j,b){  // b は対象行件数になってる。
//      cout << "j:" << j << " b:" << b << " i:" << i << endl;
      if ( B.at(j).at(i) == '#' ) {
        del = false;
        break;
      }
    }
    // あった場合のみ、楯列を上から
    if (! del) {
      rep(j,b){
        C.at(j).at(c) = B.at(j).at(i);
      }
      c +=1;
    }
  
  }
  // 結果出力
  rep(i,b){
    rep(j,c){
      cout << C.at(i).at(j);
      if ( j == c-1 ) { cout << endl; }
    }
  }

}
