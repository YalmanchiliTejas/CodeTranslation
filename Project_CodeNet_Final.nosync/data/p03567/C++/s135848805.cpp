#include <bits/stdc++.h>
using namespace std;

char s[114];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i=0; i<=n-2; i++) {
    if (s[i] == 'A' &&  s[i+1] == 'C') {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}

