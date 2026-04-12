#include <cstdio>
#include <type_traits>

int main() {
  static_assert(std::is_same<long, decltype(1234567890987654321-1234567890987654321)>::value, "");

  char s[4];
  scanf("%s", s);
  puts(((s[0]+s[1]+s[2]) % 3 == 0)? "No": "Yes");
}
