#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, x, n) for(int i = x; i < (int)(n); i++)
#define ALL(n) begin(n), end(n)
//struct cww{cww(){ios::sync_with_stdio(false);cin.tie(nullptr);}}star;
const long long INF = numeric_limits<long long>::max();

int main() {
  char s[4];
  scanf("%s", s);

  if (s[0] == s[1] && s[1] == s[2]) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}
