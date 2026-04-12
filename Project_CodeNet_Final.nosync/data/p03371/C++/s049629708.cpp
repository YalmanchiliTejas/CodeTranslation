#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans1 = a * x + b * y;
  int ans2;
  if(x > y)
    ans2 = c * y * 2 + a * (x - y);
  else
    ans2 = c * x * 2 + b * (y - x);
  int ans3 = c * max(x, y) * 2;
  cout << min(ans1, min(ans2, ans3)) << endl;
}