#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> void cmax(T& a, U b) { if (a<b) a = b; }
template<class T, class U> void cmin(T& a, U b) { if (a>b) a = b; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int p = 0, ans = 0;
  rep(i, n) {
    int h;
    cin >> h;
    if (p <= h) ans++;
    cmax(p, h);
  }
  cout << ans << endl;
}
