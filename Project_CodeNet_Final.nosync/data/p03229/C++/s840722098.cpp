#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define LINF LLONG_MAX

using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<ll>());

  vector<ll> mxfirst, mnfirst;
  if (N % 2 == 0) {
    mxfirst.push_back(1);
    mxfirst.push_back(-1);
    mnfirst.push_back(1);
    mnfirst.push_back(-1);
    for (int i = 0; i < (N - 2) / 2; i++) {
      mxfirst.push_back(2);
      mnfirst.push_back(2);
    }
    for (int i = 0; i < (N - 2) / 2; i++) {
      mxfirst.push_back(-2);
      mnfirst.push_back(-2);
    }
  } else {
    mxfirst.push_back(1);
    mxfirst.push_back(1);
    mnfirst.push_back(-1);
    mnfirst.push_back(-1);
    for (int i = 0; i < (N - 2) / 2; i++) {
      mxfirst.push_back(2);
      mnfirst.push_back(-2);
    }
    for (int i = 0; i < ((N - 2) / 2) + 1; i++) {
      mxfirst.push_back(-2);
      mnfirst.push_back(2);
    }
  }
  sort(mxfirst.begin(), mxfirst.end(), greater<ll>());
  sort(mnfirst.begin(), mnfirst.end(), greater<ll>());
  ll res1 = 0, res2 = 0;

  for (int i = 0; i < N; i++) {
    res1 += mxfirst[i] * A[i];
    res2 += mnfirst[i] * A[i];
  }

  ll ans = max(res1, res2);
  cout << ans << endl;
}