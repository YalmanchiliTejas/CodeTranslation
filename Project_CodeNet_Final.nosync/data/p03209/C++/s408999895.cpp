#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll si[55];
  int N;
  ll X;
  cin >> N >> X;
  si[0] = 1;
  for (int i = 1; i <= N; i ++) {
    si[i] = si[i - 1] * 2 + 3;
  }
  ll pt[55];
  pt[0] = 1;
  for (int i = 1; i <= N; i ++) {
    pt[i] = pt[i - 1] * 2 + 1;
  }
  ll ans = 0;
  while (N > 0 && X > 0) {
    if (X >= si[N - 1] + 1) {
      ans += pt[N - 1];
      X -= (si[N - 1] + 1);
      if (X > 0) {
        ans ++;
        X --;
      }
    }
    else {
      X --;
    }
    N --;
    //cout << ans << endl;
  }
  if (X >= 1) ans ++;
  cout << ans << endl;
}


