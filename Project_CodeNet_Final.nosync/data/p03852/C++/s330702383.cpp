#include <stdio.h>
int main(void){
  char c;
  scanf("%c",&c);
  printf("%s\n",(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')? "vowel":"consonant");
  return 0;
}