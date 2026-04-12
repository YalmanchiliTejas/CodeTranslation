#include<bits/stdc++.h>
using namespace std;

#define int ll
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  cout << (x >= 30 ? "Yes\n" : "No\n");
  return 0;
}
