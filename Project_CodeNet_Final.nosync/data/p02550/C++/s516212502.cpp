#include <iostream> // cout, endl, cin
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#define rep(i,N) for (ll i = 0; i < (N); i++)
#define repone(i,N) for(ll i = 1; i < (N); i++)
#define REP(i,N) for (ll i = (N)-1; i >= 0; i--)
#define FOR(j,i,N) for (ll j = (N)-1; j > (i); j--)
#define repsqrt(i,N) for(ll i = 1; i*i <= (N); i++)
#define loop(i,a,b) for(ll i = a; i < b;i++)
#define ST string
#define vec vector<ll>
#define vecs vector<string>
#define outb(s) cout << fixed << setprecision(15) << s << endl;
#define out(s) cout << s << endl;
#define SZ(x) ((ll)(x).size())
#define Graph vector<vector<ll>>
#define vecb vector<lb>
#define P pair<ll, ll>
#define F first
#define S second
#define vecbool vector<bool>
using ll = long long;
using lb = long double;
using ll = long long;
using lb = long double;
using namespace std;
const ll mod = 1000000007;
const ll zero = 0;
const ll one = 1;
const ll INF = 1e8;
const lb pi = 3.14159265358979;
 
ll nCk(ll N, ll K){
  if(N>1){
    ll kid = 1;
  for(ll i = N; i > N - K; i--){
      kid = kid * i;
    }
    for(ll i = 1; i < K + 1; i++){
        kid = kid / i;
    }
  return kid;
  }
  else{
    return 0;
  }
}
 
ll stair_pow(ll N){// 階乗
  ll sum = 1;
  for(ll i = 1; i <= N; i++){
    sum = sum * i % mod;
  }
  return sum % mod;
}
 
ll gcd(ll p, ll q){
  return q ? gcd(q ,p % q):p;
}
 
ll lcm(ll p, ll q){
  return p / gcd(p, q) * q;
}
 
bool is_prime(ll x){
  if(x <= 1){
    return false;
  }
  for(ll i=2; i * i <= x; i++){
    if(x % i == 0){ 
      return false;
    }
  }
  return true;
}
 
ll sum_of_num(ll num){// 各位の和
  ll dig;
  ll sum = 0;
  while(num){
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}
 
ll how_many_break(ll n, ll m){// 何回割れるか
  ll counter = 0;
  while (n % m == 0){
    n = n / m;
    counter++;
  }
  return counter;
}
 
ll many_pow(ll N, ll M){ // NのM乗
  if(M == 0)return 1;
  else{
    ll sum = 1;
    for(ll i = 0; i < M; i++){
      sum *= N;
    }
    return sum;
  }
}
 
ll one_to_i(ll i){ // 1からiまでの和
  if(i < 0){
    return 0;
  }
  else{
    return i*(i+1)/2;
  }
}
 
ll how_many_yaku(ll num){
  ll ans = 0;
   repsqrt(i,num){
    if(num % i == 0){
      ans++;
      if(i != num/i){
        ans++;
      }
    }
  }
  return ans;
}
 
ll digit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

ll digitsum(ll num){
  ll dig = 0,sum = 0;
   while(num){
    dig = num % 10;
    sum += dig;
    num /= 10;
  }
  return sum;
}
 
struct UnionFind {
  vec d;
  UnionFind(ll n = 0): d(n,-1) {}
  ll find(ll x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(ll x, ll y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(ll x, ll y) { return find(x) == find(y);}
  int size(ll x) { return -d[find(x)];}
};
 
vecbool seen;
void dfs(const Graph &G, ll v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v); 
    }
}

ll LCS(ST s, ST t){
    ll s1 = s.size();
    ll s2 = t.size();
    Graph p(s1 + 1, vec(s2 + 2));
    rep(i,s1 + 1) {
        rep(j,s2 + 1){
            if (i > 0 && j > 0){
                if (s[i-1] == t[j-1]){
                    p[i][j] = max(p[i - 1][j - 1] + 1, max(p[i][j - 1], p[i - 1][j]));
                }
                else {
                    p[i][j] = max(p[i - 1][j], p[i][j - 1]);
                }
            }
            else {
                p[i][j] = 0;
            }
        }
    }
    ll ans = p[s1][s2];
    return ans;
}
 
ll modpow(ll x, ll y){
    ll res = 1;
    rep(i,y){
        res = res * x % mod;
    }
    return res;
}

struct modint{
  ll x;
  modint(ll x = 0) : x((x % mod + mod) % mod){}
  modint operator-() const {
    return modint(-x);
  }
  modint& operator += (const modint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator -= (const modint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator *= (const modint a) { 
    (x *= a.x) %= mod; 
    return *this;
  }
  modint operator + (const modint a) const { 
    return modint(*this) += a;
  }
  modint operator - (const modint a) const { 
    return modint(*this) -= a;
  }
  modint operator * (const modint a) const { 
    return modint(*this) *= a;
  }
  modint pow(ll t) const {
    if (!t) return 1;
    modint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  modint inv() const { 
    return pow(mod - 2);
  }
  modint& operator /= (const modint a) {
    return *this *= a.inv();
  }
  modint operator / (const modint a) const { 
    return modint(*this) /= a;
  }
};
istream& operator >> (istream& is, modint& a) {
  return is >> a.x;
}
ostream& operator << (ostream& os, const modint& a) { 
  return os << a.x;
}

vector<P> prime_factorize(ll N) {
    vector<P> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

/*-----------------------------------------------------------------------------------*/
 
// cout << fixed << setprecision(15)
 
// continue

// count(S.begin(),S.end(),'');
 
// reverse(S.begin(), S.end());
 
// s.substr(8, 8)
 
// sort(p.begin(), p.end());

// reverse(s.begin(), s.end());
 
// sort(p.rbegin(), p.rend()); ← 降順sort.
 
// getline(cin,s);

// transform (s.begin(), s.end(), s.begin(), toupper); ←大文字変換

// transform (s.begin(), s.end(), s.begin(), tolower); ←小文字変換
 
/*-----------------------------------------------------------------------------------*/

ll maximam = 1e8;

int main() {
  ll n,x,m,count = 0;
  cin >> n >> x >> m;
  vec p(m);
  p[0] = x;
  bool is = false;
  rep(i,m - 1){
    count++;
    if(p[i] == 0){
      is = true;
      break;
    }
    p[i + 1] = p[i] * p[i] % m;
  }
  if(n <= m){
    ll ans = 0;
    rep(i,n){
      ans += p[i];
    }
    out(ans);
  }
  else if(is){
    ll ans = 0;
    rep(i,count){
      ans += p[i];
    }
    out(ans);
  }
  else{
    bool is = true, po = false, ppp = true;
    ll counter = 1, ok = 0;
    vec q, r(m), s;
    q.push_back(x);
    ll i = 0;
    while(ppp){
      if(q[i] * q[i] % m == 0){
        po = true;
        break;
      }
      q.push_back(q[i] * q[i] % m);
      if(is){
        counter++;
      }
      else{
        ok++;
        s.push_back(q[i] * q[i] % m);
      }
      if(r[q[i + 1] - 1] == 1){
        is = false;
      }
      if(r[q[i + 1] - 1] == 2){
        ppp = false;
      }
      r[q[i + 1] - 1]++;
      i++;
    }
    ll ans = 0;
    n -= counter;
    rep(j, counter){
      ans += q[j];
    }
    if(po){
      out(ans);
      return 0;
    }
    ll sum = 0;
    rep(j,ok){
      sum += s[j];
    }
    ans += sum * (n / ok);
    ll qq = n % ok;
    rep(j,qq){
      ans += s[j];
    }
    out(ans);
  }
}
