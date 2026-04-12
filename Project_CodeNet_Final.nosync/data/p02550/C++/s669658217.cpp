#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

class Cycle {
 private:
  ll _index = 1;
  ll _cycle_entrance = -1;
  ll _cycle_length = -1;
  ll _cycle_sum = 0;

  vector<ll> _list;
  map<ll, ll> _m;

 public:
  Cycle() {
    _list.emplace_back(-1);  // dummy
  }

  bool add(ll value) {
    if (_m[value]) {
      _cycle_entrance = _m[value];
      _cycle_length = _index - _cycle_entrance;

      ll cycle_sum = 0;
      for (ll i = 0; i < _cycle_length; i++) {
        ll index = _cycle_entrance + i;
        cycle_sum += _list[index];
      }
      _cycle_sum = cycle_sum;

      return false;
    }

    _m[value] = _index;
    _list.emplace_back(value);
    _index++;
    return true;
  }

  ll sum(ll length) {
    ll result = 0;
    ll rest = length;

    for (ll i = 1; i < _cycle_entrance; i++) {
      if (rest <= 0) {
        break;
      }
      result += _list[i];
      rest--;
    }
    ll cycle_num = rest / _cycle_length;
    result += (_cycle_sum * cycle_num);

    rest = rest % _cycle_length;

    for (ll i = 0; i < rest; i++) {
      ll index = _cycle_entrance + i;
      result += _list[index];
    }
    return result;
  }
};

int main() {
  ll N, X, M;
  scanf("%lld %lld %lld", &N, &X, &M);

  auto cycle = Cycle();

  ll x = X;
  for (;;) {
    if (!cycle.add(x)) {
      break;
    }
    x = x * x % M;
  }

  cout << (cycle.sum(N)) << endl;
}
