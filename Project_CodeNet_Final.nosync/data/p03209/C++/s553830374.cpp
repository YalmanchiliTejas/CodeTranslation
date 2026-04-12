#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
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

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

vl a,p;

ll rec(int n, ll x){
  if(n == 0) return 1;
  else if(x == 1) return 0;
  else if(x <= 1+a[n-1]) return rec(n-1, x-1);
  else if(x == 2+a[n-1]) return 1+p[n-1];
  else if(x <= 2*a[n-1] + 2) return 1+p[n-1]+rec(n-1, x-a[n-1]-2);
  else return p[n];

  return 0;
}

int main(){
  int n; ll x; cin >> n >> x;
  a.pb(1); rep(i, n) a.pb(2*a[i] + 3);
  p.pb(1); rep(i, n) p.pb(2*p[i] + 1);
  std::cout << rec(n, x) << '\n';
}
