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

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct edge { ll from, to, d; };
vector<vector<edge>> adj;
vector<ll> used, s_count, t_count;

vector<ll> dijkstra(int n, vector<ll> &count) {
  int N = adj.size();
  auto c = [](const p_ll &x, const p_ll &y){return x.second>y.second;};
  priority_queue<p_ll, vector<p_ll>, decltype(c)> q(c);
  vector<ll> result(N,LLINF); result[n] = 0; q.push(make_pair(n,0));
  while(q.size()) {
    p_ll now = q.top(); q.pop();
    ll np = now.first, nd = now.second;
    if (nd>result[np]) continue;
    for (auto x: adj[np]) {
      if (result[x.to]<result[np]+x.d) continue;
      else if (result[x.to]==result[np]+x.d) {
        count[x.to] = (count[x.to]+count[np]) % MOD;
      }
      else {
        q.push(make_pair(x.to, result[np]+x.d));
        result[x.to] = result[np]+x.d;
        count[x.to] = count[np];
      }
    }
  }
  return result;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  int N, M; cin >> N >> M;
  int S, T; cin >> S >> T; S--; T--;
  adj.resize(N); s_count.resize(N,1); t_count.resize(N,1);
  rep(i,M) { 
    ll U, V, D; cin >> U >> V >> D; U--; V--;
    adj[U].push_back({U,V,D}); adj[V].push_back({V,U,D});
  }
  vector<ll> ds = dijkstra(S, s_count), dt = dijkstra(T, t_count);
  // debug(all(ds)); debug(all(s_count)); cout << "-------" << endl;
  // debug(all(dt)); debug(all(t_count)); cout << "-------" << endl;

  used.resize(N); rep(i,N) used[i] = ds[i]+dt[i] == ds[T];
  // debug(used,used+N);

  ll total = s_count[T]*s_count[T]%MOD, collision = 0;
  rep(i,N) {
    if (used[i]&&ds[i]*2==ds[T]) {
      // cout << i << endl;
      ll st = s_count[i] * t_count[i] % MOD;
      collision = (collision + st*st) % MOD;
    }
  }
  rep(i,N) {
    for (auto x: adj[i]) {
      if (used[x.from]&&used[x.to]) {
        bool b1 = ds[x.from]+x.d==ds[x.to];
        bool b2 = ds[x.from]*2<ds[T], b3 = ds[x.to]*2>ds[T];
        if (b1&&b2&&b3) {
          // cout << x.from << " " << x.to << endl;
          ll st = s_count[x.from] * t_count[x.to] % MOD;
          collision = (collision + st*st) % MOD;
        }
      }
    }
  }

  ll result = (total-collision+MOD) % MOD;
  cout << result << endl;
  return 0;
}

// 9 12
// 1 9 
// 1 2 1
// 2 3 1
// 4 5 1
// 5 6 1
// 7 8 1
// 8 9 1
// 1 4 1
// 4 7 1
// 2 5 1
// 5 8 1
// 3 6 1
// 6 9 1