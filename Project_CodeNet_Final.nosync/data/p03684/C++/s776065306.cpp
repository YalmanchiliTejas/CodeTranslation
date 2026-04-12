#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll ans = 0;
  ll x[N],y[N];
  bool used[N];
  set<P> X;
  set<P> Y;
  priority_queue<P, vector<P>, greater<P>> Q;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    X.insert(make_pair(x[i],i));
    Y.insert(make_pair(y[i],i));
    used[i] = false;
  }
  used[0] = true;
  X.erase(make_pair(x[0],0));
  Y.erase(make_pair(y[0],0));
  auto itrx = X.lower_bound(make_pair(x[0],0));
  auto itry = Y.lower_bound(make_pair(y[0],0));
  if (itrx != X.end()) {
    Q.push(make_pair(abs(itrx->F - x[0]),itrx->S));
  }
  if (itrx != X.begin()) {
    Q.push(make_pair(abs(prev(itrx)->F - x[0]),prev(itrx)->S));
  }
  if (itry != Y.end()) {
    Q.push(make_pair(abs(itry->F - y[0]),itry->S));
  }
  if (itry != Y.begin()) {
    Q.push(make_pair(abs(prev(itry)->F - y[0]),prev(itry)->S));
  }
  for (int i = 0; i < N-1; i++) {
    while (!Q.empty()) {
      P p = Q.top();
      Q.pop();
      if (!used[p.S]) {
        used[p.S] = true;
        int a = p.S;
        ans += p.F;
        X.erase(make_pair(x[a],a));
        Y.erase(make_pair(y[a],a));
        auto _itrx = X.lower_bound(make_pair(x[a],a));
        auto _itry = Y.lower_bound(make_pair(y[a],a));
        if (_itrx != X.end()) {
          Q.push(make_pair(abs(_itrx->F - x[a]),_itrx->S));
        }
        if (_itrx != X.begin()) {
          Q.push(make_pair(abs(prev(_itrx)->F - x[a]),prev(_itrx)->S));
        }
        if (_itry != Y.end()) {
          Q.push(make_pair(abs(_itry->F - y[a]),_itry->S));
        }
        if (_itry != Y.begin()) {
          Q.push(make_pair(abs(prev(_itry)->F - y[a]),prev(_itry)->S));
        }
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}