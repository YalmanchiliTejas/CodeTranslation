#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  int N;
  cin >> N;
  vector<ll>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  ll lef = A[0];
  ll rig = A[0];
  ll mi = 1;
  ll ma = N - 1;
  ll ans_ = 0;
  for (int i = 1; i < N; i ++) {
    if (i % 2) {
      ll kj = A[ma];
      ans += kj - min(lef, rig);
      if (lef < rig) lef = kj;
      else rig = kj;
      ma --;
    }
    else {
      ll kj = A[mi];
      ans += max(lef, rig) - kj;
      if (rig > lef) rig = kj;
      else lef = kj;
      mi ++;
    }
  }
  mi = 0;
  ma = N - 2;
  lef = A[N - 1];
  rig = A[N - 1];
  for (int i = 1; i < N; i ++) {
    if (i % 2 == 0) {
      ll kj = A[ma];
      ans_ += kj - min(lef, rig);
      if (lef < rig) lef = kj;
      else rig = kj;
      ma --;
    }
    else {
      ll kj = A[mi];
      ans_ += max(lef, rig) - kj;
      if (rig > lef) rig = kj;
      else lef = kj;
      mi ++;
    }
  }
  cout << max(ans, ans_) << endl;
}
