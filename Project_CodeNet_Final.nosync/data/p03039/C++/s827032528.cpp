#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INFTY = 1e9+7;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  ll x = 0;
  for (ll i=1; i<M; i++) {
    x += i*(i+1)/2;
    x %= INFTY;
  }
  ll N2 = (N*N)%INFTY;
  x = (x*N2)%INFTY;

  ll y = 0;
  for (ll i=1; i<N; i++) {
    y += i*(i+1)/2;
    y %= INFTY;
  }
  ll M2 = (M*M)%INFTY;
  y = (y*M2)%INFTY;

  ll sum = (x+y)%INFTY;  // distance of each 2 points

  int n = N*M-2;
  int r = K-2;
  r = min(r,n-r);

  if (r == 0) {
    cout << sum << endl;
    return 0;
  }

  if (r == 1) {
    cout << (sum*n)%INFTY << endl;
    return 0;
  }

  int numerator[r], denominator[r];
  rep(i,r) {
    numerator[i] = n-r+i+1;
    denominator[i] = i+1;
  }

  for (int p=2; p<=r; p++) {
    int pivot = denominator[p-1];
    if (pivot > 1) {
      int offset = (n-r)%p;
      for (int i=p-1; i<r; i+=p) {
        numerator[i-offset] /= pivot;
        denominator[i] /= pivot;
      }
    }
  }

  ll comb = 1;
  rep(i,r) {
    if (numerator[i] > 1) {
      comb *= numerator[i];
      comb %= INFTY;
    }
  }

  cout << (sum*comb)%INFTY << endl;
  return 0;
}
