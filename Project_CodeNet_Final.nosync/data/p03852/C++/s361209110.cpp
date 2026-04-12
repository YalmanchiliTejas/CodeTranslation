#include <cstdio>
#include <string>
 
int main()
{
  char c;
  scanf("%c", &c);
  std::string s("aeiou");
  if (s.find(c) != -1)
    printf("vowel\n");
  else
    printf("consonant\n");
  return 0;
}
