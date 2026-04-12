#include <cstdio>

char s[10];

int main(){
  scanf("%s", s);

  bool ans = false;

  for(int i = 0; ; i++){
    if(s[i + 1] == 0) break;
    if(s[i] == 'A' && s[i + 1] == 'C') ans = true;
  }

  puts(ans ? "Yes" : "No");
  return 0;
}