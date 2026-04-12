#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int> PII;
typedef map<int, int> MII;

const int SZ = 112345;
const int MOD = 1e9 + 7;

char s[4];

int main() {
  scanf("%s", s);
  int a = 0, b = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') a++;
    else b++;
  }
  if (a > 0 && b > 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
