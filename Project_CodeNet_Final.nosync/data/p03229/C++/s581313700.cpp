#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

ul N, M, T;
std::string S;
ul gcd(ul m, ul n) {
  if ((0 == m) || (0 == n)) return 0;
  while (m != n) {
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  return m;
}  // gcd

ul lcm(ul m, ul n) {
  if ((0 == m) || (0 == n)) return 0;

  return ((m / gcd(m, n)) * n);  // lcm = m * n / gcd(m,n)
}  // lcm

ul B, K;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  list<ul> ans_list;
  vector<ul> A(N, 0);
  ul ans = 0;
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  ans += A.back() - A.front();
  ul fitr = 0;
  bool flag = true;
  if (N == 2) {
    cout << ans << endl;
    return 0;
  }
  ul num = 2;
  if (N % 2 == 0) {
    while (num != N) {
      // cout << ans  <<" "<< fitr << " " << num << " " << N<< endl;
      if (flag) {
        ans += A[N - 1 - fitr] - A[fitr + 1];
        // cout <<"u" << A[N-1 - fitr] << ", " << A[fitr+1] << endl;
      } else {
        ans += A[N - 1 - fitr - 1] - A[fitr];
        // cout << A[N-1 - fitr -1 ] << ", " << A[fitr] << endl;
        ++fitr;
      }
      ++num;
      flag = !flag;
    }
  } else {
    while (num + 1 != N) {
      // cout << ans  <<" "<< fitr << " " << num << " " << N<< endl;
      if (flag) {
        ans += A[N - 1 - fitr] - A[fitr + 1];
        // cout <<"u" << A[N-1 - fitr] << ", " << A[fitr+1] << endl;
      } else {
        ans += A[N - 1 - fitr - 1] - A[fitr];
        // cout << A[N-1 - fitr -1 ] << ", " << A[fitr] << endl;
        ++fitr;
      }
      ++num;
      flag = !flag;
    }
    if (A[N - 1 - fitr] - A[fitr + 1] > A[N - 1 - fitr - 1] - A[fitr]) {
      ans += A[N - 1 - fitr] - A[fitr + 1];
    } else {
      ans += A[N - 1 - fitr - 1] - A[fitr];
    }
  }

  cout << ans << endl;
}