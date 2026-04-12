#include <iostream>

using ll = long long;
int main(int argc, char ** argv)
{
  //
  std::string s;
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (*(s.c_str() + i) == 'A') {
      ans++;
    }
  }
  if ((ans == 0) || (ans == 3)) {
    std::puts("No");
  } else {
    std::puts("Yes");
  }
  return 0;
}
