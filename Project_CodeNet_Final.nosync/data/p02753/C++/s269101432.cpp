#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  // 入力
  string S;
  cin >> S;

  string result = "No";
  if (S[0]!=S[1] || S[1]!=S[2]) {
    result = "Yes";
  }

  // 出力
  cout << result << endl;
  return 0;
}