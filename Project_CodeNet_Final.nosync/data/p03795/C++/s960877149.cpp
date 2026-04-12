#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int n;
  cin >> n;
  int x = n*800;
  int y = int(n/15)*200;
  cout << x - y << endl;
  return 0;
}