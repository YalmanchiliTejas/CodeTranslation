#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}

template<typename T>
vector<int> compress(vector<T> &v) {
  vector<T> t = v;
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
	vector<int> r(v.size());
  for (int i = 0; i < v.size(); i++) {
    r[i] = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
  }
	return r;
}

int main() {
  int n; cin >> n;
  V a(n);
  rep(i, n) cin >> a[i];
  V b = compress(a);

  deque<int> dq;
  rep(i, n) {
    int j = lower_bound(ALL(dq), b[i]) - dq.begin();
    if (j == 0) {
      dq.push_front(b[i]);
    }
    else {
      dq[j-1] = b[i];
    }
  }
  cout << dq.size() << endl;
  return 0;
}
