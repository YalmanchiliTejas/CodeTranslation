/*
    問題をよく読もう！
    論理的に考えよう！
    サンプルを確認しよう!
    絶対に諦めるな！
    工夫をしろ！
    配列は少し多めにとっておく

    Twitterは終わるまでログアウト！
    （間違えて解法をツイートしてはいけないから）

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <functional>
#include <cmath>
using namespace std;
#define rep(i, n) for(int i=0; i<n; ++i)
typedef long long ll;
//必要な宣言

void solve();

char c;

int main() {
  cin >> c;

  solve();

  return 0;
}

void solve() {

  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;

  return;
}