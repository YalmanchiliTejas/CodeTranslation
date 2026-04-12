#include <iostream>

int main() {
  // 年齢入力
  int age;
  std::cin >> age;

  // 七五三判定処理
  std::string ans;
  if (age == 7 || age == 5 || age == 3) {
    ans = "YES";
  } else {
    ans = "NO";
  }

  // 出力
  std::cout << ans << std::endl;

  return 0;
}
