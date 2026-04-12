#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N;
vector<ll> num;
ll ans = 0;
ll before = 0;
bool operation(vector<ll>& A) {
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    num.at(i) = A.at(i) / N;
    sum += num.at(i);
  }
  for (ll i = 0; i < N; ++i) {
    ans += A.at(i) / N;
    A.at(i) %= N;
    A.at(i) += (sum - num.at(i));
  }
  if (sum == 0) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  vector<ll> A(N);
  num = vector<ll>(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  bool check = false;
  while (!check) {
    check = operation(A);
  }
  cout << ans << "\n";
}
