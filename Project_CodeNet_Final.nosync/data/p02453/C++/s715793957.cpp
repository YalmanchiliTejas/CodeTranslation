#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
const int INF = 1000000007;
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll fac(ll a) { return a > 1 ? fac(a - 1) * a : 1; }
bool echeck(ll a) { return a % 2 == 0 ? 1 : 0; }
ll comb(ll n, ll m){
  ll tmp = 1;
  for(int i = n; i >= n - m + 1; i--){
    tmp *= i;
  }
  ll temp = 1;
  for(int i = 1; i <= m; i++){
    temp *= i;
  }
  return tmp / temp;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int>v(n);
  rep(i,n)cin >> v[i];
  int q;
  cin >> q;
  int tmp;
  rep(i,q){
    cin >> tmp;
    cout << lower_bound(all(v),tmp) - v.begin() << endl;
  }
  return 0;
}  
