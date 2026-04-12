#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll a, b, c, x, y, s, t, u;
  in3(a, b, c);
  in2(x, y);
  s = 99999999999;
  rep(i, 2 * max(x, y) + 1){
    t = max(0ll, x - i / 2);
    u = max(0ll, y - i / 2);
    s = min(s, a * t + b * u + c * i);
  }
  out(s);
  memi;
}
