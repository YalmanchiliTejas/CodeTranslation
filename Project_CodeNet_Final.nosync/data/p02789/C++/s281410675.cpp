#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define st string
#define ve(i) vector<i>
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define each(i, n) for(auto&& i: n)

int main() {
  int N, M;
  cin >> N >> M;
  st a = "No";
  if (N == M) {
    a = "Yes";
  }
  cout << a << endl;
}