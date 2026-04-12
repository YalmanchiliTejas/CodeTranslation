#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll N, X, M;
ll used[100010];
ll val[100010];

int main() {
  std::cin >> N >> X >> M;

  ll x = X;
  ll cnt = 0;
  ll sum = 0;
  std::vector<ll> S;
  S.emplace_back( 0 );

  rep( i, 100001 )
    used[i] = -1;

  while( true ) {
    if( used[x] != -1 ) {
      break;
    }
    
    used[x] = cnt;
    val[cnt] = x;

    sum = (sum+x);
    S.emplace_back( sum );
    x = (x*x)%M;
    ++cnt;
  }

  ll idx = used[x];

  ll ans = 0;

  if( N <= cnt ) {
    ans += S[N];
  } else {
    ans += S[cnt];
    N -= cnt;
    ll mo = cnt-idx;
    ll sum = S[cnt]-S[idx];

    ans += N/mo*sum+S[N%mo+idx]-S[idx];
  }

  std::cout << ans << endl;

  return 0;
}