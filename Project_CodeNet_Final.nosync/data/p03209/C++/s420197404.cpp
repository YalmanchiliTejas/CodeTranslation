#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll a[50], p[50];

ll f(int N, ll X) {
  if (N == 0) return 1;
  else if (X == 1) return 0;
  else if (X <= 1 + a[N-1]) return f(N-1, X-1);
  else if (X == 1 + a[N-1] + 1) return p[N-1] + 1;
  else if (X <= 1 + a[N-1] + 1 + a[N-1]) return p[N-1] + 1 + f(N-1, X - 1 - a[N-1] - 1);
  else return p[N-1] + 1 + p[N-1];
}

int main() {
  int N; cin >> N;
  ll X; cin >> X;
  a[0] = 1, p[0] = 1;
  for(int i = 1; i < N; ++i) {
    a[i] = a[i-1] * 2 + 3;
    p[i] = p[i-1] * 2 + 1;
  }
  cout << f(N, X) << endl;
  return 0;
}