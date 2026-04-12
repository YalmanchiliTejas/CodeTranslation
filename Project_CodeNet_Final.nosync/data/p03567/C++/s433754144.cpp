#include <cstdio>
#include <cstring>
using namespace std;

char S[10];
int len;

int main() {
  scanf("%s", S + 1);
  len = strlen(S + 1);
  for (int i = 1; i < len; ++i)
    if (S[i] == 'A' && S[i + 1] == 'C') {
      puts("Yes");
      return 0;
    }
  puts("No");
  return 0;
}
