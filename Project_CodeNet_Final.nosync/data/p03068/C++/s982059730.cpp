#include <bits/stdc++.h>
using namespace std;
     
int main() {
    //ながさN  文字列小文字 S Kばんめ
    string S;
    int N,K;
    cin >> N >> S >> K;

    int X = K-1;
    //B Kばんめの文字
    string B = S.substr(X,1);

    // 置換対象の文字列    // 検索文字列
    for (int i = 0; i < N; i++) {
      string Y = S.substr(i,1);;
      if (Y == B){
      }
      else{
        S.replace(i, 1, "*");
      }
    }
  cout << S << endl;
          
}