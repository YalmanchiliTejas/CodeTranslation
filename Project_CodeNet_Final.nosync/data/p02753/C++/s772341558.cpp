#include <stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
  char s[3];
  scanf("%s",s);
  if(s[0]==s[1] && s[1]==s[2]) printf("No");
  else printf("Yes");
  return 0;
}