#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;++i) {
    cin >> h[i];
  }
  int cnt = 0;
  int ma = 0;
  for(int i=0;i<n;++i) {
    if(h[i] < ma) continue;
    cnt++;
    ma = max(ma, h[i]);
  }
  cout << cnt << endl;
}
