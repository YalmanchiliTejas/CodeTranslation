#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

int main() {
  char buf[4];
  scanf("%s", buf);
  std::string s = buf;

  if (s == std::string(3, 'A') || s == std::string(3, 'B')) {
    puts("No");
  } else {
    puts("Yes");
  }
}
