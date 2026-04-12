#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod=(1e+9)+7;
const ll inf=1e+16; 

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m;i>=n;i--)
#define all(x) x.begin(),x.end()

ll n;
vll a;

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  a.resize(n);
  rep(i,0,n) cin >> a[i];
  sort(all(a),greater<ll>());
  
  ll res=0;
    rep(i,0,n/2) res+=2*(a[i]-a[n-1-i]);
    if(n%2==0) res+=(a[n-n/2]-a[n/2-1]);
    else res+=max(a[n-n/2]-a[n/2],a[n/2]-a[n/2-1]);
  
  cout << res << endl;
}