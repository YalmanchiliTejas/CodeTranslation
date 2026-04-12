#include<stdio.h>

int main(){
  char moji;
  scanf("%c", &moji);
  if(moji == 'a' || moji == 'i' || moji == 'u' || moji == 'e' || moji == 'o'){
    printf("vowel\n");
  }else{
    printf("consonant\n");
  }

  return 0;
}
