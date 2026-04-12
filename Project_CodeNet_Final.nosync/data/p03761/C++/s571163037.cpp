#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

void counter(char s[], int cnt[]) {
  for (int i=0; i<26; i++) {
    cnt[i] = 0;
  }
  for (int i=0; i<strlen(s); i++) {
    cnt[s[i]-'a'] += 1;
  }
}

int main() {

  int n;
  scanf("%d", &n);

  int cnt0[26];
  for (int i=0; i<26; i++) {
    cnt0[i] = 50;
  }

  for (int i=0; i<n; i++) {
    char s[50];
    scanf("%s", s);

    int cnt[26];
    counter(s, cnt);
    for (int j=0; j<26; j++) {
      cnt0[j] = min(cnt[j], cnt0[j]);
    }
  }
  for (int i=0; i<26; i++) {
    for (int j=0; j<cnt0[i]; j++) {
      printf("%c", 'a'+i);
    }
  }
}