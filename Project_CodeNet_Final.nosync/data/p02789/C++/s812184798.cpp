#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef string str;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=1e9+7;
const ll inf=1e16;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define pb(x) pop_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sum(x) accumulate(all(x),0)
#define pc(x) __builtin_popcount(x)
#define gll greater<ll>()

void solve(){
 ll n,m;
  cin >> n >> m;
  cout << (n==m?"Yes":"No") << endl;
}

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}