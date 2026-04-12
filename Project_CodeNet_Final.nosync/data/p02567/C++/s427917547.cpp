#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int op(int a, int b){
  return max(a, b);
}

int e(){
  return -1;
}

int v;

bool f(int x){
  return x < v;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    segtree<int, op, e> seg(A);
    rep(i, Q){
      ll T;
      cin >> T;
      if(T == 1){
        ll X, V;
        cin >> X >> V;
        X--;
        seg.set(X, V);
      }
      if(T == 2){
        ll L, R;
        cin >> L >> R;
        L--;
        R--;
        cout << seg.prod(L, R+1) << endl;
      }
      if(T == 3){
        ll X, V;
        cin >> X >> V;
        X--;
        v = V;
        cout << seg.max_right<f>(X)+1 << endl;
      }
    }
}