#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> a;
  map<ll, ll> mp;
  a.emplace_back(x);
  if(x == 0){
    cout << 0 << endl;
    return 0;
  }
  bool zero = false;
  ll count = 0;
  mp[x] = count++;
  while(1){
    ll b = a.back();
    ll c = b*b%m;
    a.emplace_back(c);
    if(c == 0){
      zero = true;
      break;
    }
    if(mp[c] != 0) break;
    mp[c] = count++;
  }

  if(!zero){
    ll sum = 0;
    ll k = a.size()-1;
    ll p = mp[a.back()];
    ll len = k-p;
    REP(i, len) sum += a[p+i];
    ll ans = (n-p)/len * sum;
    REP(i, (n-p)%len) ans += a[p+i];
    REP(i, p) ans += a[i];
    cout << ans << endl;
  }else{
  ll sum = 0;
  ll k = a.size()-1;
  REP(i, k) sum += a[i];
    cout << sum << endl;
  }
  return 0;
}