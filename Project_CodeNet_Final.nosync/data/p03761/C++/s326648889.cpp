#include <stdio.h>
#include <stdlib.h>

int search(char *str, char ch);

int main(){
 unsigned n;
 char **S;
 char ans[64];
 unsigned min = unsigned(-1), cur = 0;
 unsigned kosu;
 unsigned i;
 char ch;
 scanf("%d", &n);
 S = (char **)malloc(sizeof(char *) * n);
 for(i = 0; i < n; i++){
  S[i] = (char *)malloc(64);
  scanf("%s", S[i]);
 }
 for(ch = 'a'; ch <= 'z'; ch++){
  min = unsigned(-1);
  for(i = 0; i < n; i++){
   kosu = search(S[i], ch);
   if(min > kosu) min = kosu;
  }
  for(i = 0; i < min; i++){
   ans[cur++] = ch;
  }
 }
 ans[cur] = '\0';
 printf(ans);
 putchar('\n');
}

int search(char *str, char ch){
 unsigned count = 0, i;
 for(i = 0; str[i]; i++) if(str[i] == ch) count++;
 return count;
}