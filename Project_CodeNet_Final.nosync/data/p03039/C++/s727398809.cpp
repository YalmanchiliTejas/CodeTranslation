#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define all(c) c.begin(),c.end()

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
 
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

char albt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                 'm','n','o','p','q','r','s','t','u','v','w','x',
                 'y','z'};

//vector<ll> g[202020];
//fill(score, score+202020, 0);
//vector<ll> v;

//ll f[101010], rf[101010];
ll f[202020], rf[202020];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    rf[0] = inv(f[0]);
    for(ll i=1;i<202020;i++){
      f[i] = (f[i - 1] * i) % MOD;
      rf[i] = inv(f[i]);
    }
}
 
ll C(int n, int k) {
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!
 
    ll bc = (b * c) % MOD;
 
    return (a * bc) % MOD;
}

int main(){
  init();
  ll n, m, k;
  cin >> n >> m >> k;
  
  ll ansx = 0;
  for (int i=1;i<n;i++) ansx += i*(n-i);
  ansx = (ansx*m*m)%MOD;
  
  ll ansy = 0;
  for (int i=1;i<m;i++) ansy += i*(m-i);
  ansy = (ansy*n*n)%MOD;
  
  ll ans = (ansx + ansy)*C(n*m-2,k-2)%MOD;
  //cout << ansx << " " << ansy << " " << C(n*m-2,k-2) << endl;
    
  cout << ans << endl;
}