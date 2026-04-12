#include <bits/stdc++.h>
using namespace std;using ll = long long;using ld = long double;using P = pair<ll,ll>;
#define rt "\n"
#define sp " "
#define test1 cout << "test1" << endl;
#define test2 cout << "test2" << endl;
#define fixprecision(n) fixed; cout << setprecision(n)
#define kyopro ios::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define iikae auto&
#define rep(i, s, N) for(ll i{s}; i < N; i++)
#define rem(i, s, N) for(ll i{N - 1}; i > s - 1; i--)
ll gcd(ll a, ll b){return b != 0 ? gcd(b, a % b) : a;}
struct UnionFind{vector<ll> par;UnionFind(ll n) : par(n, -1){}void init(ll n){par.assign(n, -1);}ll root(ll x){if (par[x] < 0) return x;else return par[x] = root(par[x]);}bool issame(ll x, ll y){return root(x) == root(y);}bool merge(ll x, ll y){x = root(x); y = root(y);if(x == y) return false;if(par[x] > par[y]) swap(x, y);par[x] += par[y];par[y] = x;return true;}int size(int x) {return -par[root(x)];}};

int main(){
  kyopro;
  ll N;
  cin >> N;
  ll hardle{};
  ll ans{};
  rep(i, 0, N){
    ll height;
    cin >> height;
    if(hardle <= height){
      ans++;
      hardle = height;
    }
  }
  cout << ans << rt;
}