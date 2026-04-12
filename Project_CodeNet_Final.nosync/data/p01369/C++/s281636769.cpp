#include<cstdio>
using namespace std;

char right[12] = "yhnujmikolp";

bool check(char c) { // right : T
  for (int i = 0; i < 11; i++) if (right[i] == c) return true;
  return false;
}

int main() {
  char s[50];
  while (1) {
    scanf("%s", s);
    if (s[0] == '#') break;
    int counter = 0;
    bool now = check(s[0]);
    for (int i = 1; s[i] != 0; i++) {
      if (now != check(s[i])) {
        now = check(s[i]);
        counter++;
      }
    }
    printf("%d\n", counter);
  }
}

