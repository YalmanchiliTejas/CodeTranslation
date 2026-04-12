#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, s, e) for (int i = (s); i < (e); i++)
#define all(x) x.begin(), x.end()

#define endl "\n"

void use_cio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto x : V) os << x << ", ";
  return os << "]";
}

//--------------------------------------------------//

int main() {
  use_cio();
  int n;
  cin >> n;
  vector<int> va(n);
  rep(i, n) cin >> va[i];
  reverse(all(va));
  vector<int> lds = {va[0]};
  for (int i = 1; i < n; i++) {
    if (lds.back() <= va[i])
      lds.push_back(va[i]);
    else
      lds[upper_bound(all(lds), va[i]) - lds.begin()] = va[i];
  }
  cout << lds.size() << endl;
}
