#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n; cin >> n;
  vi score(n);
  rep(i,n) cin >> score[i];
  rep(i,n/2) score[i] = (score[n-1-i] += score[i]);

  ll ans = 0;
  for (int i=1; i<n/2; ++i) {
    int last = (n-1)%i == 0 ? n/2 : n-1-i;
    ll sum = 0;
    for (int j=0; j<last; j+=i) {
      sum += score[j];
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
  return 0;
}
