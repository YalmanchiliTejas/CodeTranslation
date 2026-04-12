#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct SegTree {
  int size;
  vector<ll> pos;
  SegTree(ll N) { size = 1; while(size<N) size<<=1; pos.resize(2*size,0); }
  ll operator[](const ll &x) const { return pos[x+size]; }

  void build() { per(i,size) operate(i); }
  void set(ll x, const ll v) { pos[x+size] = v; }
  void update(ll x, const ll v) { set(x,v); x+=size; while (x>>=1) operate(x); }
  ll query(ll a, ll b) {
    ll L = 0, R = 0;
    for (a+=size, b+=size; a<b; a>>=1, b>>=1) {
      if (a&1) { L = q(L,pos[a]); a++; }
      if (b&1) { b--; R = q(pos[b],R); }
    }
    return q(L,R);
  }
  void operate(ll i) { pos[i] = max(pos[i*2],pos[i*2+1]); }
  ll q(ll x, ll y) { return max(x,y); }
};

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  ll N, Q; cin >> N >> Q;
  ll A[N]; rep(i,N) cin >> A[i];

  SegTree st(N); rep(i,N) st.update(i,A[i]);
  rep(_,Q) {
    ll t, x, y; cin >> t >> x >> y; x--;
    if (t==1) st.update(x,y);
    else if (t==2) cout << st.query(x,y) << endl;
    else if (t==3) {
      ll l = x+1, r = N+1;
      while (l!=r) {
        ll mid = (l+r)/2;
        if (st.query(x,mid)>=y) r = mid;
        else l = mid+1;
      }
      cout << l << endl;
    }
  }
  // cout << result << endl;
  return 0;
}