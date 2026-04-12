#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
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

struct ball { ll x; ll y; };

int main() {
  int N; cin >> N;
  ball b[N]; rep(i,N) { ll x, y; cin >> x >> y; if (x>y) swap(x,y); b[i] = {x,y}; }  
  if (N==1) { cout << 0 << endl; return 0; }

  sort(b,b+N,[](const ball &x, const ball &y){ return x.x<y.x; });
  sort(b+1,b+N,[](const ball &x, const ball &y){ return x.y<y.y; });
  sort(b+1,b+N-1,[](const ball &x, const ball &y){ return x.x<y.x||(x.x==y.x&&x.y<y.y); });
  // rep(i,N) cout << b[i].x << " " << b[i].y << endl;

  ll xmax = 0, xmin = INF, ymax = 0, ymin = INF;
  rep(i,N) { 
    xmax = max(xmax,b[i].x); xmin = min(xmin,b[i].x);
    ymax = max(ymax,b[i].y); ymin = min(ymin,b[i].y);
  }
  ll r1 = (xmax-xmin)*(ymax-ymin);
  // cout << r1 << endl;

  ll xdiff = b[N-1].y-b[0].x, ydiff = INF;
  multiset<ll> yset;
  yset.insert(b[0].y); yset.insert(b[N-1].x);
  repr(i,1,N-1) yset.insert(b[i].x);
  ydiff = min(ydiff,*(yset.rbegin())-*(yset.begin()));
  repr(i,1,N-1) {
    yset.erase(yset.find(b[i].x)); yset.insert(b[i].y);
    ydiff = min(ydiff,*(yset.rbegin())-*(yset.begin()));
  }
  ll r2 = xdiff * ydiff;
  // cout << r1 << endl;

  ll result = min(r1, r2);
  cout << result << endl;
  return 0;
}