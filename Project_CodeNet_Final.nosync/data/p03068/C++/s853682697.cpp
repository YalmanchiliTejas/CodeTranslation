#include <bits/stdc++.h>
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;
template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  char target = S[K - 1];
  for (int i = 0; i < N; i++) {
    if (S[i] != target) S[i] = '*';
  }

  cout << S << endl;
  return 0;
}
