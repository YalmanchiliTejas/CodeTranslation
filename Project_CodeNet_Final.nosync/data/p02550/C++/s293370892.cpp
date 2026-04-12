#include <bits/stdc++.h>
using namespace std;

#define st              first
#define nd              second
#define pb              push_back
#define lwb             lower_bound
#define upb             upper_bound
#define Size(a)         int((a).size())
#define reset(s, n)     memset(s, n, sizeof(s))
#define bit(n, i)       (((n) >> (i)) & 1)
#define cntbit(n)       __builtin_popcountll(n)
#define all(a)          (a).begin(), (a).end()
#define unique(a)       (a).resize(unique(all(a)) - (a).begin())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))

typedef long double ld;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-7;
inline ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, ll p = MOD) {return fpow(a, p - 2, p);}
inline ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
inline void onbit(ll &a, int i){a |= 1LL << i;}
inline void offbit(ll &a, int i){onbit(a, i), a -= (1LL << i);}

const int N = 3e5 + 5;

ll n, m, k;

int visited[N];
vector<long long> clique;
vector<long long> a;
vector<ll> f;
ll size_clique = 1;
ll root;

void dfs(ll u){
  visited[u] = 1;
  if(visited[f[u]] == 0){
    dfs(f[u]);
  } else{
    u = f[u];
    root = u;
    clique[0] = u;
    while(f[u] != root){
      u = f[u];
      clique[size_clique++] = u;
    }
  }
}

void solve(){
  clique.assign(N, 0);
  a.assign(N, 0);
  f.assign(N, 0);
  ll x;
  cin >> n >> x >> m;
  if(m == 1){
    cout << 0 << "\n";
    return;
  }
  a[1] = x;
  for(int i = 2; i < N; i++){
    long long value = (a[i - 1] * a[i - 1]) % m;
    a[i] = value;
    if(a[i] == 0){
      long long res = 0;
      for(int i = 1; i <= n; i++){
        res += a[i];
      }
      cout << res << "\n";
      return;
    }
    f[a[i - 1]] = a[i];
    if(f[a[i]] != 0){
      break;
    }
  }

  dfs(x);
  ll cnt = 0;
  long long res = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] != root){
      res += a[i];
      cnt++;
    } else{
      break;
    }
  }

  for(int i = 1; i < size_clique; i++){
    clique[i] += clique[i - 1];
  }

  n -= cnt;

  ll p = n / size_clique;
  res += p * clique[size_clique - 1];

  n %= size_clique;

  if(n > 0)
    res += clique[n - 1];

  cout << res << "\n";



}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cout << fixed << setprecision(10);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int query = 1;
  // cin >> query;
  int start = 1000 * clock() / CLOCKS_PER_SEC;
  while(query--) solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
