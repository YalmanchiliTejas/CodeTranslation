#include <stdio.h>

int main(){
char x;
scanf("%c",&x);
if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o') printf("vowel");
else printf("consonant");
}