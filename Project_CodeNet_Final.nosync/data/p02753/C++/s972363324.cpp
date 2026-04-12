#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;
// 152a

int main() {
  string s;
  cin >> s;

  if (s[0] != s[1] || s[1] != s[2]){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
  