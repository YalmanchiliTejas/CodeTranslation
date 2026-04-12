#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S;
  cin >> S;
  bool bl = false;
  rep(i, 2) {
    if (S[i] != S[i+1]) bl = true;
  }
  puts(bl ? "Yes" : "No");
  return 0;
}