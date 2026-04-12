#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll mod = 1000000007;

const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
  T tmp = r;
  r = l;
  l = tmp;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
  for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
  return is;
}


int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> lvp(51, 0);
  vector<ll> lv(51, 0);
  lv[0] = 1;
  lvp[0] = 1;
  for (int i = 1; i < 51; ++i) {
    lv[i] = lv[i - 1] * 2 + 3 ;
    lvp[i] = lvp[i - 1] * 2 + 1;
  }


  ll ans = 0;

  ll tmplv = n;
  ll pos = 0;
  // for (int i = n; i >= 0 ; --i) {
  //   tmplv = i;
  //   if (x >= pos + lv[i])break;
  //   pos++;
  // }


  // x -= pos + lv[tmplv];
  // ans += lvp[tmplv];

  // if (x > 0) {
  //   x--;
  //   ans++;
  // }

  for (int i = n; i >= 0 ; --i) {
    if (x >= lv[i] + pos) {
      x -= pos +lv[i];
      ans += lvp[i];
      if (x > 0) {
        x--;
        ans++;
      }
      i++;
      pos = 0;
      continue;
    }

    pos++;

  }







  cout << ans ;

}


















