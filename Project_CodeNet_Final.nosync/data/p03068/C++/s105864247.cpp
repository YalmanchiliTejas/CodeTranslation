#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;


int main() {
  int n; cin >> n;
  string s; cin >> s;
  int k; cin >> k;
  k--;
  rep(i,n) {
    if (s[i] == s[k]) cout << s[k];
    else cout << "*";
  }
}
