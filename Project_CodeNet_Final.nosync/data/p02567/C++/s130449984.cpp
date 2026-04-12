#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef string str;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef dsu uf;
typedef fenwick_tree<ll> fw;

const ll mod=1e9+7;
const ll inf=1e18;

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
#define pc(x) __builtin_popcount(x)
#define gll greater<ll>()


int op(int a, int b) {return max(a, b);}
 
int e() {return -1;}
 
int x;
bool f(int b) {return b < x;};
 

void solve(){
 int n,q;
  cin >> n >> q;
 vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  
  segtree<int, op, e> st(a);
  while(q--){
   ll t,l,r;
    cin >> t >> l >> r;
    if(t==1) st.set(l-1,r);
    else if(t==2) cout << st.prod(l-1, r) << endl;
    else {
      x = r;
      cout << st.max_right<f>(l - 1) + 1 << endl;
    }
    
  }
}
int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}