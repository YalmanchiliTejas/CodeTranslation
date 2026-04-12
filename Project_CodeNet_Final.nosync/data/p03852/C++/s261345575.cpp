#include <cstdio>

int main()
{
  char c;
  scanf("%c", &c);
  puts(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? "vowel" : "consonant");
  return 0;
}