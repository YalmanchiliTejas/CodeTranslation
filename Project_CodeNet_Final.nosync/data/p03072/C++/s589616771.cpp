#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(int i=0;i<n;i++)

int N;
int H[101];

int main() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", &H[i]);
  int max = -1;
  int ans = 0;

  REP(i, N) {
    if (max <= H[i]) {
      ans++;
      max = H[i];
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
