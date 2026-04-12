#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, h, a = 0, b = 0;
  cin >> n;
  rep(i,n)
  {
    cin >> h;
    if (b <= h) {
      a++;
      b = h;
    }
  }
  cout << a;
}