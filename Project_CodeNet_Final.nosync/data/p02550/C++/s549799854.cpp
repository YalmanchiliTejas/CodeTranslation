#include <bits/stdc++.h>

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> bool chmin(T &a, U b) { if (b < a) { a = b; return true; } return false; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  ll n, x, m; cin >> n >> x >> m;
  map<ll,ll> cnt;
  vll sum;

  ll c = 1;

  while (true) {
    if (cnt[x]) break;

    cnt[x] = c++;
    sum.eb(x);

    x = x % m * x % m;
  }

  ll ans = 0;
  rep(i, cnt[x]-1) ans += sum[i];

  ll roop_sum = accumulate(sum.begin()+cnt[x]-1,sum.end(),0LL);
  ll roop_len = c - cnt[x];
  ll still_roop = n - cnt[x] + 1;
  ll amari = still_roop % roop_len;

  ans += roop_sum * (still_roop / roop_len);
  rep(i, amari) ans += sum[cnt[x]-1+i];

  cout << ans << endl;
  
  return (0);
}