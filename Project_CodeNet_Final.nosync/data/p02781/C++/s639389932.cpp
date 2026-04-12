#include <bits/stdc++.h>
using namespace std;

string n;
int k;
int len;
long long ans = 0;
long long com(long long a, long long b) {
  if (a < 0) {
    return 0;
  } if (b == 0) {
    return 1;
  } else if (b == 1) {
    return a;
  } else if (b == 2) {
    return a * (a - 1) / 2;
  } else {
    return a * (a - 1) * (a - 2) / 6;
  }
}
long long p9(long long a) {
  if (a == 0) {
    return 1;
  }
  return 9LL * p9(a - 1);
}

void f(int idx, bool small_than_n, int rest, bool equal0) {
  if (idx == len) {
    if (rest == 0 && !equal0) {
      ++ans;
    }
    return;
  }
  if (rest == 0) {
    ++ans;
    return;
  }
  if (small_than_n) {
    if (equal0) {
      f(idx+1, true, rest, true);
      ans += p9(rest) * com(len - idx - 1, rest - 1);
    } else {
      ans += p9(rest) * com(len - idx, rest);
    }
    return;
  }
  if (n[idx] == '0') {
    f(idx+1, false, rest, false);
  } else {
    f(idx+1, true, rest, equal0);
    for (int i=1; i<n[idx]-'0'; i++) {
      f(idx+1, true, rest-1, false);
    }
    f(idx+1, false, rest-1, false);
  }
}
int main() {
  cin>>n;
  cin>>k;
  len = n.length();
  f(0, false, k, true);
  cout<<ans<<endl;
}