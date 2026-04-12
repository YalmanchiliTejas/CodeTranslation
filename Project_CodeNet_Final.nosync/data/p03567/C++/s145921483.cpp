#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s; cin >> s;
  rep(i, s.size()-1) {
    if (s.at(i) == 'A' && s.at(i+1) == 'C') {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
    return 0;
}