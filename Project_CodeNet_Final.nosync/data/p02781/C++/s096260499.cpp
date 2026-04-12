#include <bits/stdc++.h>
using namespace std;

string n;
int k;
int len;
long long com(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (a == 0) {
    if (b == 1) {
      return 1;
    } else {
      return 0;
    }
  }
  long long ret = 1;
  for (int i=a; i>a-b; i--) {
    ret *= i;
  }
  for (int i=b; i>0; i--) {
    ret /= i;
  }
  return ret;
}
long long f(int num, int idx, int cnt_not_0) {
  if (cnt_not_0 > k) {
    return 0;
  }
  if (idx == len - 1) {
    if (cnt_not_0 == k && num <= n[idx] - '0') {
      return 1;
    } else {
      return 0;
    }
  }
  if (num > n[idx] - '0') {
    return 0;
  }
  if (num < n[idx] - '0') {
    return com(len - idx - 1, k - cnt_not_0) * pow(9, k - cnt_not_0);
  }
  long long ret = f(0, idx + 1, cnt_not_0);
  for (int i=1; i<=9; i++) {
    // printf("num: %d, idx %d, cnt_not_0: %d, i: %d\n", num, idx, cnt_not_0, i);
    // cout<<ret<<endl;
    ret += f(i, idx + 1, cnt_not_0 + 1);
    // cout<<ret<<endl;
  }
  return ret;
}

int main() {
  cin>>n;
  cin>>k;
  len = n.length();
  long long ans = 0;
  long long tmp = pow(9, k);
  for (int i=k; i<len; i++) {
    ans += tmp * com(i - 1, k - 1);
  }
  for (int i=1; i<=9; i++) {
    ans += f(i, 0, 1);
  }
  cout<<ans<<endl;
}