#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ull> vu;
typedef vector <vector <int>> vvi;
typedef pair <int, int> pi;
typedef vector <pair <int, int>> vpi;

int n;
vi v;

void read() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.pb(x);
  }
}

void solve() {
  int sol = 0, cmax = 0;
  for(int i = 0; i < n; ++i) {
    if (v[i] >= cmax) {
      cmax = v[i];
      ++sol;
    }
  }
  cout << sol;
}

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
//  cin >> t; //please do not forget to comment this if there are no queries
  while(t) {
    --t;
    read();
    solve();
  }
  return 0;
}
