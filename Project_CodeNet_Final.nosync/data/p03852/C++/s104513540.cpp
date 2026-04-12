#include <bits/stdc++.h>

using namespace std;

char c;

int main() {
  scanf("%c", &c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') puts("vowel");
  else puts("consonant");
  return 0;
}