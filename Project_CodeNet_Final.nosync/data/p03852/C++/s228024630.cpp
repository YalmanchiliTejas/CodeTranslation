#include <bits/stdc++.h>
using namespace std;

int main() {
  string c;
  cin >> c;
  // 英小文字のうち母音は a、e、i、o、u
  
  
  // cが母音であるとき、vowel
  // そうでないとき consonant と出力せよ。
  // ここにプログラムを追記
  
  string vowel = "aeiou";
  
  // vowel の中に 入力内容 c が入っていないかを確認
  bool x = false;
  
  for (int i = 0;i < vowel.size(); i++) {
    if (c.at(0) == vowel.at(i)) {
      x = true;
      break;
    }
  }

  if (x) {
    cout << "vowel" <<endl;
  } else {
    cout << "consonant" <<endl;
  }
}



