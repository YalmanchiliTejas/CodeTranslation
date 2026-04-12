#include <bits/stdc++.h>
#define pb push_back
#define REP(i, n) for (signed long long i = 0; i < (n); i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  ll n;
  cin >> n;
  vector<ll> v, x;
  REP(i, n) {
    ll a;
    cin >> a;
    v.pb(a);
    x.pb(a);
  }
  sort(v.begin(), v.end());
  for (auto &a : x) {
    if (a < v[v.size() / 2])
      cout << v[v.size() / 2] << endl;
    else {
      cout << v[v.size() / 2 - 1] << endl;
    }
  }
}
