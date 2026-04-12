#include <bits/stdc++.h>

int main() {
  std::string x(1, ' ');
  scanf("%s", &x[0], x.size());
  if (x[0] == 'a' || x[0] == 'e' || x[0] == 'i' || x[0] == 'o' || x[0] == 'u')
    printf("vowel");
  else
    printf("consonant");
}
