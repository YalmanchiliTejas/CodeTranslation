#include <iostream>
#include <algorithm>

int main(void)
{
  std::string s;
  std::cin >> s;
  int a_cnt = std::count(s.begin(), s.end(), 'A');
  int b_cnt = std::count(s.begin(), s.end(), 'B');
  std::string result = (a_cnt && b_cnt) ? std::string("Yes") : std::string("No");
  std::cout << result << std::endl;
}