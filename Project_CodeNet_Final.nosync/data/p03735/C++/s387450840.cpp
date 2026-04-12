#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 200000;
ll N;
ll x[MAX_N], y[MAX_N];

ll calc1() {
  // pattarn [min, ?], [?, max]
  ll ma1 = 0, ma2 = 0, mi1 = 1e18, mi2 = 1e18;
  for (int i = 0; i < N; ++i) {
    ma1 = max(ma1, x[i]); mi1 = min(mi1, x[i]);
    ma2 = max(ma2, y[i]); mi2 = min(mi2, y[i]);
  }
  return (ma1-mi1)*(ma2-mi2);
}

ll calc2() {
  // pattarn [min, max], [?, ?]
  ll ma = 0, mi = 1e18;
  vector<pll> vec;
  multiset<ll> mset;
  for (int i = 0; i < N; ++i) {
    vec.push_back(pll(y[i], x[i]));
    ma = max(ma, x[i]);
    mi = min(mi, y[i]);
    mset.insert(y[i]);
  }
  sort(all(vec));
  ll res = 1e18;
  for (int i = 0; i < N; ++i) {
    mset.erase(mset.find(vec[i].fi));
    mset.insert(vec[i].sc);
    res = min(res, (ma-mi) * (*mset.rbegin() - *mset.begin()));
  }
  return res;
}

ll calc() {
  return min(calc1(), calc2());
}


int main() {
  cin >> N;
  rep(i,N) cin >> x[i] >> y[i];

  for (int i = 0; i < N; ++i) {
    if (x[i] < y[i]) swap(x[i], y[i]);
  }

  cout << calc() << endl;

  return 0;
}
