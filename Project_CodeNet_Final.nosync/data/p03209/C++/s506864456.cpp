#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

vector<ll> l,p;

ll rec(ll n, ll x){
  if(n == 0) return 1;
  if(x == 1) return 0;
  if(2 <= x && x <= 1+l[n-1]) return rec(n-1,x-1);
  if(x == 2+l[n-1]) return p[n-1]+1;
  if(3 + l[n-1] <= x && x <= 2*l[n-1] + 2) return p[n-1] + 1 + rec(n-1, x - l[n-1] - 2);
  if(x == 2*l[n-1] + 3) return 2*p[n-1] + 1;

  return 0;
}

int main(){
  ll n;
  ll x;
  cin >> n >> x;
  l.pb(1LL); p.pb(1LL);
  rep(i, n){
    l.pb(2*l[i]+3);
    p.pb(2*p[i]+1);
  }

  std::cout << rec(n, x) << '\n';
}
