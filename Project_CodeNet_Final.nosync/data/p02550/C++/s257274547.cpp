#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;
#define rep(i, n) for(int i = 0; i < n; i++)
const ll mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  if(N <= M) {
    ll ans = X;
    rep(i, N - 1) {
      X = X * X % M;
      ans += X;
    }
    cout << ans << endl;
  }
  else {
    set<ll> check;
    check.insert(X);
    ll A = X;
    ll right = 1;
    rep(i, M) {
      A = A * A % M;
      right++;
      if(check.count(A)) {
        break;
      }
      check.insert(A);;
    }
    ll left = 1;
    ll B = X;
    rep(i, M) {
      if(B == A) {
        break;
      }
      B = B * B % M;
      left++;
    }
    ll ans = 0;
    ll keep = X;
    rep(i, left - 1) {
      ans += keep;
      keep = keep * keep % M;
    }
    ll roopsum = 0;
    rep(i, right - left) {
      roopsum += keep;
      keep = keep * keep % M;
    }
    ans += roopsum * ((N - left + 1) / (right - left));
    rep(i, (N - left + 1) % (right - left)) {
      ans += keep;
      keep = keep * keep % M;
    }
    cout << ans << endl;
  }
}