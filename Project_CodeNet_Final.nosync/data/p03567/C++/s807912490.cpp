#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
  char s[100];
  scanf("%s", s);
  bool ac = false;
  for (int i = 1; s[i]; ++i) {
    if (s[i - 1] == 'A' && s[i] == 'C') {
      ac = true;
      break;
    }
  }
  puts(ac ? "Yes" : "No");
  return 0;
}
