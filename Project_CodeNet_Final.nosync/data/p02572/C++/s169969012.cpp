#include <bits/stdc++.h>
using namespace std;
#define ll                 long long
#define ull                unsigned long long
#define ld                 long double
#define fastio             ios_base::sync_with_stdio(false);cin.tie(NULL);
#define NO                 cout << "NO" << endl
#define YES                cout << "YES" << endl
#define vec                vector<ll>
#define pi                 pair<ll, ll>
#define intarr(arr, n)     ll arr[n]; for (ll i = 0; i < n; i++) cin >> arr[i]
#define intvec(v, n)       vec v;for (ll i = 0; i < n; i++) { ll x;cin >> x; v.pb(x);}
#define loop(i, a, b, c)   for (ll i = a; i < b; i += c)
#define pb                 push_back
#define mkp                make_pair
#define ins                insert
#define print(a, n, m)     for (ll i = n; i < m; i++) {  cout << a[i] << " "; }  cout << endl
#define endl               "\n"
#define mod2               998244353
#define mod                1000000007
#define mem(dp, a)         memset(dp, a, sizeof(dp));
#define all(v)             v.begin(), v.end()
#define ump                unordered_map<ll, ll>
#define ff                 first
#define ss                 second
#define PI                 3.14159265358979
#define minh               priority_queue<ll>
#define maxh               priority_queue<ll,vector<ll>,greater<ll>>
#define flush              cout<<flush

//If path exist b/w A and B - BFS, DFS

// Shortest Path - BFS(unweighted), Dijkstra, Bellman-ford
//                 Floyd-Warshall, A*

//To detect negative cycles - Bellman-ford, Floyd-Warshall
//DFS - Connectivity, count connected components,
//      Find Bridges/Articulation points


// struct mi {
//   ll v; explicit operator ll() const { return v; }
//   mi() { v = 0; }
//   mi(ll _v) {
//     v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
//     if (v < 0) v += MOD;
//   }
//   friend bool operator==(const mi& a, const mi& b) {
//     return a.v == b.v; }
//   friend bool operator!=(const mi& a, const mi& b) {
//     return !(a == b); }
//   friend bool operator<(const mi& a, const mi& b) {
//     return a.v < b.v; }

//   mi& operator+=(const mi& m) {
//     if ((v += m.v) >= MOD) v -= MOD;
//     return *this; }
//   mi& operator-=(const mi& m) {
//     if ((v -= m.v) < 0) v += MOD;
//     return *this; }
//   mi& operator*=(const mi& m) {
//     v = v*m.v%MOD; return *this; }
//   mi& operator/=(const mi& m) { return (*this) *= inv(m); }
//   friend mi pow(mi a, ll p) {
//     mi ans = 1; assert(p >= 0);
//     for (; p; p /= 2, a *= a) if (p&1) ans *= a;
//     return ans;
//   }
//   friend mi inv(const mi& a) { assert(a.v != 0);
//     return pow(a,MOD-2); }

//   mi operator-() const { return mi(-v); }
//   mi& operator++() { return *this += 1; }
//   mi& operator--() { return *this -= 1; }
//     mi operator++(int) { mi temp; temp.v = v++; return temp; }
//     mi operator--(int) { mi temp; temp.v = v--; return temp; }
//   friend mi operator+(mi a, const mi& b) { return a += b; }
//   friend mi operator-(mi a, const mi& b) { return a -= b; }
//   friend mi operator*(mi a, const mi& b) { return a *= b; }
//   friend mi operator/(mi a, const mi& b) { return a /= b; }
//     friend ostream& operator<<(ostream& os, const mi& m) {
//         os << m.v; return os;
//     }
//     friend istream& operator>>(istream& is, mi& m) {
//         ll x; is >> x;
//         m.v = x;
//         return is;
//     }
// };

ll Ceil(ll a, ll b)
{
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll moduloInverse(ll a)
{
  ll p = mod;
  ll b = p - 2, ans = 1;
  for (; b > 0; a = a * a % p, b >>= 1)
    if (b & 1)
      ans = ans * a % p;
  return ans;
}

ll ncrmod(ll n, ll m)
{
  ll p = mod;
  if (m > n)
    return 0;
  ll up = 1, down = 1;
  for (ll i = n - m + 1; i < n + 1; i++)
    up *= i, up %= p;
  for (ll i = 1; i < m + 1; i++)
    down *= i, down %= p;
  return up * moduloInverse(down) % p;
}

ll powmod(ll a, ll n)
{
  if (!n)
    return 1;
  ll pt = powmod(a, n / 2);
  pt *= pt, pt %= mod;
  if (n & 1)
    pt *= a, pt %= mod;
  return pt;
}

void factorize(long long int n)
{
  ll sum2 = 0, sum = 0;
  ll count = 0;

  while (!(n % 2)) {
    n >>= 1;
    count++;
  }

  if (count)
  {
    sum2 += count;
  }

  for (long long i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    if (count)
    {
      if (i & 1)sum += count;
    }
  }
  if (n > 2)
  {
    sum++;
  }
}

bool isPrime(ll n)
{
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  return true;
}

const ll  N = 5e5 + 5;
ll fact[N];
ll invfact[N];

void factorialInverse()
{
  fact[0] = 1;
  for (ll i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  invfact[N - 1] = moduloInverse(fact[N - 1]);
  for (ll i = N - 2; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1);
    invfact[i] %= mod;
  }
}

ll ncr(ll n, ll r) {
  if (n < 0 or r < 0)
    return 0LL;
  if (n < r)
    return 0LL;
  return ((fact[n] % mod) * (invfact[r] % mod * invfact[n - r] % mod) % mod) % mod;
}

// void bfs(ll s) {
//   queue<ll> q;

//   visited[s] = true;
//   q.push(s);

//   while (!q.empty()) {
//     ll front = q.front();
//     cout << front << " ";
//     q.pop();
//     for (auto i : g[front]) {
//       if (!visited[i]) {
//         visited[i] = true;
//         q.push(i);
//       }
//     }
//   }
// }

// map<ll, vec > g;
// map<ll, bool> visited;
// ll ans[N + 1];
// ll child[N + 1];
// ll remain[N + 1];
// ll final[N + 1];
// ll home[N + 1];

// void dfs(ll i) {
//   visited[i] = true;
//   //cout << i << "-> ";
//   for (auto j : g[i]) {
//     if (visited[j] == false) {
//       dfs(j);
//       remain[i] = remain[i] + remain[j];
//     }
//   }
// }


void solve()
{
  ll n;
  cin >> n;
  intarr(a, n);
  ll suf[n];
  suf[n - 1] = a[n - 1];
  for (ll i = n - 2; i >= 0; i--)
  {
    suf[i] = (suf[i + 1] + a[i]) % mod;
  }
  ll ans = 0;
  for (ll i = 0; i <= n - 2; i++)
  {
    ans = (ans + (a[i] * suf[i + 1]) % mod) % mod;
  }
  cout << (ans);
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  fastio;
  ll t;
  t = 1;
  //cin >> t;
  while (t--)
  {
    solve();

  }

  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

  return 0;
}