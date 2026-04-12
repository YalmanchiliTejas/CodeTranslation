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

ll f(ll n, ll x) {
  if(n == 0) return 1;
  ll d = pow(2, n + 1) - 3;
  ll a = pow(2, n) - 1;
  if(x <= 1)
    return 0;
  else if(x <= d + 1)
    return f(n - 1, x - 1);
  else if(x == d + 2)
    return a + 1;
  else if(x <= d * 2 + 1)
    return a + 1 + f(n - 1, x - d - 2);
  else
    return a * 2 + 1;
}

int main() {
  ll n, x;
  cin >> n >> x;
  cout << f(n, x) << endl;
}