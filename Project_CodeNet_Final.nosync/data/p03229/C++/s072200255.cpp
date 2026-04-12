#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;

ll MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<ll> pattern1;
  vector<ll> pattern2;

  if (N % 2 == 0) {
    pattern1.push_back(-1);
    pattern1.push_back(1);
    pattern2.push_back(1);
    pattern2.push_back(-1);
    for (ll i = 0; i < (N - 2); i++) {
      if (i % 2 == 0) {
        pattern1.push_back(2);
        pattern2.push_back(-2);
      } else {
        pattern1.push_back(-2);
        pattern2.push_back(2);
      }
    }
  } else {
    pattern1.push_back(1);
    pattern1.push_back(1);
    pattern2.push_back(-1);
    pattern2.push_back(-1);
    for (ll i = 0; i < (N - 2); i++) {
      if (i % 2 == 0) {
        pattern1.push_back(-2);
        pattern2.push_back(2);
      } else {
        pattern1.push_back(2);
        pattern2.push_back(-2);
      }
    }
  }

  sort(a.begin(), a.end());
  sort(pattern1.begin(), pattern1.end());
  sort(pattern2.begin(), pattern2.end());
  ll res1 = 0;
  ll res2 = 0;
  for (ll i = 0; i < N; i++) {
    // cout << a[i] << endl;
    res1 += a[i] * pattern1[i];
    res2 += a[i] * pattern2[i];
  }

  cout << max(res1, res2) << endl;
}