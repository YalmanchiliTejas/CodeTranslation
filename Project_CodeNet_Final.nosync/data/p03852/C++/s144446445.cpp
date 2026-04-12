#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  scanf("%c", &c);

  char vowels[] = {'a', 'i', 'u', 'e', 'o'};

  bool flag = false;
  for(int i = 0; i < 5; i++) {
    if (c == vowels[i]) {
      flag = true;
    }  
  }
  
  if(flag){
    printf("vowel\n");
  } else {
     printf("consonant\n");
  }

}
