#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

i64 m[100];
i64 cnt[100];

int main() {
  i64 N;
  cin >> N;
  i64 X;
  cin >> X;
  m[0] = 1;
  cnt[0] = 1;
  for(int i = 1;i <= 50;i++) {
    m[i] = m[i - 1] * 2 + 1;
    cnt[i] = cnt[i - 1] * 2 + 3;
  }

  i64 ans = 0;
  i64 i = N;
  while(true) {
    if(i == 0) {
      X -= 1;
      ans++;
      break;
    }
    X -= 1;
    if(X == 0) break;
    if(cnt[i - 1] >= X) {
      i -= 1;
      continue;
    }
    X -= cnt[i - 1];
    ans += m[i - 1];
    X -= 1;
    ans++;
    if(X == 0) break;
    if(cnt[i - 1] >= X) {
      i -= 1;
      continue;
    }
    X -= cnt[i - 1];
    ans += m[i - 1];
    break;
  }
  cout << ans << endl;
}
