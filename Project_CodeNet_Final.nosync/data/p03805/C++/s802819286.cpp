#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using ch = char;
using db = double;
using bl = bool;
using vll = vector<long long>;
using vdb = vector<db>;
using vvll = vector<vll>;
using vst = vector<st>;
using vch = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;} return false;}
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;} return false;}
const ll mod = 1000000007;
const ll inf = 1LL << 60;

int main(){
  ll n, m;
  cin >> n >> m;
  vvll graph(n);
  rep(i, 0, m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  vll v(n);
  iota(all(v), 0);
  ll ans = 0;
  do{
    ll check = true;
    rep(i, 0, n - 1) if(find(all(graph.at(v.at(i + 1))), v.at(i)) == graph.at(v.at(i + 1)).end()) check = false;
    if(check) ans++;
  }while(next_permutation(v.begin() + 1, v.end()));
  cout << ans << endl;
}