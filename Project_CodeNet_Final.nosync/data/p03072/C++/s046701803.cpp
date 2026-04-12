#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll n;
ll h[e5];
ll max_height = 0;
ll ans;

int main(){
  cin >> n;
  for(ll i = 0;i < n;i++) cin >> h[i];
  for(ll i = 0;i < n;i++){
    if(h[i] >= max_height) ans++;
    max_height = max(max_height,h[i]);
  }
  cout << ans << endl;
}
