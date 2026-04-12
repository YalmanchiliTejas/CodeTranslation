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
  ll n, k, a, b, s;
  in2(n, k);
  b = k + 1;
  s = 0;
  if(k == 0){
    out(n * n);
    memi;
    return 0;
  }
  while(b <= n){
    a = b - k;
    s = s + a * (n / b);
    a = n % b - k + 1;
    s += max(0ll, a);
    b++;
  }
  out(s);
  memi;
}
