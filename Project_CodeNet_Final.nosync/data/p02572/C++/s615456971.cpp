#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int64_t N, R=1000000007;
  cin >> N;
  vector<int64_t> A(N);
  long long S=0, ans=0;
  for (int64_t i=0; i<N; i++) {
    cin >> A[i];
    S=S+A[i];
    S=S%R;
  }
  for (int64_t i=0; i<N; i++) {
    S=S-A[i];
    if (S<0) {
      S=S+R;
    }
    ans=ans+A[i]*S;
    ans=ans%R;
  }
  cout << ans << endl;
}