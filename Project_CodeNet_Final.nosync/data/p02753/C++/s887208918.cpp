#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using in6 = int64_t;
using ind = double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  if(s.at(1) == s.at(2) && s.at(0) == s.at(1)) cout << "No" << endl;
  else cout << "Yes" << endl;
}
