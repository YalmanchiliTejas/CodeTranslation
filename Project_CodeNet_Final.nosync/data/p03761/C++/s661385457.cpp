#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  string S[n];
  rep(i, n)
    cin >> S[i];
  //ここまで入力

  
  //アイデアは，n個の数字の最大公約数を取るイメージ
  
  
  //各文字列S[i]に対して，各アルファベットの登場回数を数える
  map<char, int> m[n];
  rep(i, n)
    rep(j, S[i].size() )
    m[i][S[i][j] ]++;

  //各アルファベットの登場回数の最小値を格納する
  //108で初期化（100以上ならなんでもいい）
  int count_min[26];
  rep(i, 26)
    count_min[i] = 108;

   //全ての文字列を見たときに，各アルファベットの登場回数の最小値を求める
  rep(i, 26)
    rep(j, n)
      if(m[j][i+'a' ] < count_min[i] )
	count_min[i] = m[j][i+'a' ];

  //解答
  rep(i, 26)
    rep(j, count_min[i])
    cout << (char)(i+'a') ;
  cout << endl;

  

  return 0;
}
