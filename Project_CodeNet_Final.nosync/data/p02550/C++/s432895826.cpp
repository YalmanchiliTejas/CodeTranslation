#include <bits/stdc++.h>
using namespace std;
int main() {
  // 入力
  long long N, X, M, Sum_A = 0;
  cin >> N >> X >> M;
  
  if (M > 1) {

    // 数列{A_n}
    vector<long long> A(M+1, 0);
    A.at(1) = X;
    for (int i = 2; i <= M; i++) {
      A.at(i) = (A.at(i-1)*A.at(i-1))%M;
    }

    // 循環節があるか確認
    int nagasa = 0, hajime = 0;
    for (int i = 1; i < M; i++) {
      if (A.at(M-i) == A.at(M)) {  // A_{1~M-1}のうちA_Mと同じで最も近いもの
        nagasa = i;  // 循環節の最小の長さ
        for (int j = 1; j <= M-i; j++) {
          if (A.at(j) == A.at(M)) {  // A_{1~M-1}のうちA_Mと同じで最も遠いもの
            hajime = j-1;  // 循環節1節目のうちA_Mと同じものの添え字
            break;  //ループを抜ける
          }
        }
        if (nagasa == i) {
          break;  //ループを抜ける
        }
      }
    }

    // 循環しない場合
    if (nagasa == 0) {
      for (int i = 0; i <= N; i++) {
        Sum_A += A.at(i);
      }
    }

    // 循環する場合
    else {
      long long shou, amari;
      shou = (N-hajime)/nagasa;  // 循環節の数-(0or1)
      //amari = hajime + (N-hajime)%nagasa;  // 循環節(or2節目)にたどり着くまで
      amari = N-shou*nagasa;

      // 循環節の部分の和
      for (int i = M-nagasa; i < M; i++) {
        Sum_A += A.at(i) * shou;
      }

      // 循環節にたどり着くまでの和
      for (int i = 0; i <= amari; i++) {
        Sum_A += A.at(i);
      }
    }
    
  }
  // 出力
  cout << Sum_A << endl;
}