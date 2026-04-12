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
  ll n;
  in(n);
  vector<string> s(n);
  rep(i, n)
    in(s[i]);
  vector<vector<ll>> a(n, vector<ll> (26, 0));
  char f = 'a';
  rep(i, 26){
    rep(j, n){
      rep(k, s[j].size()){
        if(s[j][k] == f)
          a[j][i]++;
      }
    }
    f++;
  }
  vector<ll> b(26, 999999999999999);
  rep(i, 26){
    rep(j, n)
      b[i] = min(b[i], a[j][i]);
  }
  f = 'a';
  rep(i, 26){
    rep(j, b[i])
      out(f);
    f++;
  }
  memi;
}