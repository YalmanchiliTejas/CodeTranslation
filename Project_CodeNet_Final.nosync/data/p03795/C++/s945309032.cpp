#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  int fif = n/15;
  cout << 800*n - 200*fif << endl;
  return 0;
}
