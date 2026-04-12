#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;

ll n, a;
ll ans=0;
vector<ll> ps;
vector<ll> vec;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
  	cin >> a;
  	vec.pb(a);
  	ps.pb(a+(i==1?0:ps[i-2]));
  }

  rep(i, 0, n-2){
  	ans+=((ll)vec[i]%MOD*(((ll)ps[n-1]-(ll)ps[i])%MOD))%MOD;
  }
  cout << ans%MOD;
}