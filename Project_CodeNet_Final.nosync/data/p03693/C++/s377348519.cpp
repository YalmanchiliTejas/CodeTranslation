#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  string num = to_string(r) + to_string(g) + to_string(b);
  string res = (stoi(num) % 4 == 0) ? "YES" : "NO";

  cout << res << endl;
}