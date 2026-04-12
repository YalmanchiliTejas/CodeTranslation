#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  string s;
  cin >> s;
  if (s.at(0)==s.at(1)&&s.at(1)==s.at(2)) cout << "No" << endl;
  else cout << "Yes" << endl;
}
