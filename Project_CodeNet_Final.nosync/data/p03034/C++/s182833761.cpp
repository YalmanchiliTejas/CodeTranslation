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
ll s[e5];
ll b[e5];
ll ans = 0;

int main(){
  cin >> n;
  for(ll i = 0;i < n;i++) cin >> s[i];
  for(ll i = 1;i <= n;i++){
    ll mem1 = 0;
    ll mem2 = 0;
    unordered_set<ll> r;
    unordered_set<ll> l;
    for(ll j = 0,k = n-1;k >= i;j+=i,k-=i){
      r.insert(j);
      l.insert(k);
      if(r.count(k) || l.count(j)) continue;
      mem1 += s[j];
      mem2 += s[k];
      ans = max(ans,mem1+mem2);

    }
  }
  cout << ans << endl;

}
