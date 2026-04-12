#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  deque<ll> q;
  rep(i, n) {
    ll a;
    cin >> a;
    if(i % 2)
      q.push_front(a);
    else
      q.push_back(a);
  }
  rep(i, n) {
    if(n % 2) {
      cout << q.back() << (i == n - 1 ? '\n' : ' ');
      q.pop_back();

    } else {
      cout << q.front() << (i == n - 1 ? '\n' : ' ');
      q.pop_front();
    }
  }
}