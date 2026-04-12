#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  char s[3];
  
  cin >> s;
  
  for (int i = 0; i < 2; i++) {
    if (s[i] != s[i+1] ) {
      printf("Yes\n");
      return 0;
    }
  }
  
  printf("No\n");
  
  return 0;
}
